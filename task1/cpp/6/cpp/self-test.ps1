# -*- coding: utf-8 -*-
<#
    self-test.ps1 —— 入门六：批量编译并自测本目录下的 5 个源文件（结构体专题）
    用法：  powershell -ExecutionPolicy Bypass -File .\self-test.ps1
    说明：  期望值取自 images/ 中的运行截图（已剔除控制台开头回显的输入行）；
            程序输出重定向到文件后按行精确比对（保留行尾空格与多空格）。
#>

$ErrorActionPreference = "Stop"
Set-Location -Path $PSScriptRoot
$outDir = Join-Path $PSScriptRoot "build"
New-Item -ItemType Directory -Force -Path $outDir | Out-Null
chcp 65001 > $null

$cases = @(
    @{ No = 1; In = "7 6`n4 7 2 6 10 7`n0 5 0 10 3 10`n2 6 8 4 3 6`n6 3 6 7 5 8`n5 9 3 3 8 1`n5 9 9 3 2 0`n5 8 0 4 1 10`n"; Expect = @("6") },
    @{ No = 2; In = "3`n李 100 130 100`n吴 110 130 110`n张 130 150 120`n";  Expect = @("张  130  150  120") },
    @{ No = 3; In = "3`n李 90 90 90`n吴 95 85 90`n张 100 80 91`n";         Expect = @("李  吴", "吴  张") },
    @{ No = 4; In = "4`n1223 95 59`n1224 50 7`n1473 32 45`n1556 86 99`n";  Expect = @("Excellent", "Not excellent", "Not excellent", "Excellent") },
    @{ No = 5; In = "3`n李 24 0`n李 25 0`n梅 14 400`n";                     Expect = @("李 25 0", "李 26 0", "梅 15 480") }
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

    # 只剔除开头连续的回显区（控制台先回显输入、再输出程序结果）
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
