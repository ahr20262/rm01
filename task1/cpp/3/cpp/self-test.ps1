# -*- coding: utf-8 -*-
<#
    self-test.ps1 —— 入门三：批量编译并自测本目录下的 5 个源文件
    用法：  powershell -ExecutionPolicy Bypass -File .\self-test.ps1
    说明：  期望值取自 images/ 中的运行截图（已剔除控制台回显的输入行）；
            程序输出重定向到文件后按行精确比对（保留行尾空格）。
#>

$ErrorActionPreference = "Stop"
Set-Location -Path $PSScriptRoot
$outDir = Join-Path $PSScriptRoot "build"
New-Item -ItemType Directory -Force -Path $outDir | Out-Null
chcp 65001 > $null

$cases = @(
    @{ No = 1; In = "5`n6`n7`n4`n2`n9`n"; Expect = @("2") },
    @{ No = 2; In = "100`n";                Expect = @("长度为", "一共要7天") },
    @{ No = 3; In = "5`n";                  Expect = @("01020304056", "0607080910", "10111213", "131415", "1516") },
    @{ No = 4; In = "1`n";                  Expect = @("2") },
    @{ No = 5; In = "4.3`n";                Expect = @("3") }
)

$vcvars = Get-ChildItem "${env:ProgramFiles}\Microsoft Visual Studio\*\*\VC\Auxiliary\Build\vcvars64.bat" -ErrorAction SilentlyContinue |
          Select-Object -First 1 -ExpandProperty FullName
if (-not $vcvars) { Write-Host "未找到 vcvars64.bat" -ForegroundColor Red; exit 1 }
Write-Host "使用编译器环境: $vcvars`n" -ForegroundColor Cyan

$pass = 0; $fail = 0
foreach ($c in $cases) {
    $n = $c.No
    $src = Join-Path $PSScriptRoot "$n.cpp"
    $exe = Join-Path $outDir "$n.exe"
    $inFile  = Join-Path $outDir "$n.in"
    $outFile = Join-Path $outDir "$n.out"
    $errFile = Join-Path $outDir "$n.err"

    [System.IO.File]::WriteAllText($inFile, $c.In)
    Push-Location $outDir
    cmd /c "call `"$vcvars`" >nul 2>&1 && cl /nologo /EHsc /utf-8 `"$src`" /Fe:`"$exe`" > `"$errFile`" 2>&1"
    $code = $LASTEXITCODE
    Pop-Location
    if ($code -ne 0) {
        Write-Host "[$n.cpp] 编译失败" -ForegroundColor Red
        Get-Content $errFile | Where-Object { $_ -match "error" } | ForEach-Object { Write-Host "    $_" }
        $fail++; continue
    }

    cmd /c "chcp 65001 >nul && `"$exe`" < `"$inFile`" > `"$outFile`" 2>&1"
    $actual = @(Get-Content $outFile -Encoding UTF8 -ErrorAction SilentlyContinue)
    # 只剔除开头连续的回显区（控制台先回显输入、再输出程序结果），
    # 避免把“程序输出恰好等于某个输入值”的行误删
    $inputs = @($c.In.TrimEnd() -split "`n" | ForEach-Object { $_.Trim() })
    $i = 0
    while ($i -lt $actual.Count -and $i -lt $inputs.Count -and $actual[$i].Trim() -eq $inputs[$i]) { $i++ }
    $body = @($actual | Select-Object -Skip $i)

    if (($body -join "|") -eq ($c.Expect -join "|")) {
        Write-Host "[$n.cpp] 编译通过，输出与截图一致" -ForegroundColor Green; $pass++
    } else {
        Write-Host "[$n.cpp] 输出与截图不一致" -ForegroundColor Yellow
        Write-Host ("    期望: " + ($c.Expect -join " <NL> "))
        Write-Host ("    实际: " + ($body -join " <NL> "))
        $fail++
    }
}
Write-Host "`n自测结果：通过 $pass 个，未通过 $fail 个" -ForegroundColor Cyan
