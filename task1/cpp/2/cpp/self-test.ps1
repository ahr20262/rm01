# -*- coding: utf-8 -*-
<#
    self-test.ps1 —— 批量编译并自测本目录下的 5 个源文件（入门二）
    用法：  powershell -ExecutionPolicy Bypass -File .\self-test.ps1
    要求：  已安装 Visual Studio（MSVC），脚本会自动定位 vcvars64.bat
    说明：  期望值取自 images/ 中的运行截图（已剔除控制台回显的输入行）
#>

$ErrorActionPreference = "Stop"
Set-Location -Path $PSScriptRoot
$outDir = Join-Path $PSScriptRoot "build"
New-Item -ItemType Directory -Force -Path $outDir | Out-Null
chcp 65001 > $null

$cases = @(
    @{ No = 1; In = "1900`n";        Expect = @("年份为", "0") },
    @{ No = 2; In = "12`n";          Expect = @("1", "1", "0", "0") },
    @{ No = 3; In = "100`n1.68`n";   Expect = @("35.4308", "overweight") },
    @{ No = 4; In = "3`n";           Expect = @("Today, I ate 3 apples") },
    @{ No = 5; In = "50`n10`n200`n"; Expect = @("输入🍎，耗时，已过", "30") }
)

$vcvars = Get-ChildItem "${env:ProgramFiles}\Microsoft Visual Studio\*\*\VC\Auxiliary\Build\vcvars64.bat" -ErrorAction SilentlyContinue |
          Select-Object -First 1 -ExpandProperty FullName
if (-not $vcvars) { Write-Host "未找到 vcvars64.bat，请在「x64 Native Tools Command Prompt」中运行本脚本" -ForegroundColor Red; exit 1 }
Write-Host "使用编译器环境: $vcvars`n" -ForegroundColor Cyan

$pass = 0; $fail = 0
foreach ($c in $cases) {
    $n = $c.No
    $src = Join-Path $PSScriptRoot "$n.cpp"
    $exe = Join-Path $outDir "$n.exe"

    Push-Location $outDir
    cmd /c "call `"$vcvars`" >nul 2>&1 && cl /nologo /EHsc /utf-8 `"$src`" /Fe:`"$exe`" 2>&1" | Out-Null
    $code = $LASTEXITCODE
    Pop-Location
    if ($code -ne 0) { Write-Host "[$n.cpp] 编译失败" -ForegroundColor Red; $fail++; continue }

    [System.IO.File]::WriteAllText((Join-Path $outDir "$n.in"), $c.In)
    $actual = @(cmd /c "chcp 65001 >nul && `"$exe`" < `"$outDir\$n.in`"") | ForEach-Object { $_.TrimEnd() }
    # 剔除控制台回显的输入行，只保留程序自身的输出
    $inputs = @($c.In.TrimEnd() -split "`n" | ForEach-Object { $_.Trim() })
    $body = @($actual | Where-Object { $inputs -notcontains $_ })

    if (($body -join "|") -eq ($c.Expect -join "|")) {
        Write-Host "[$n.cpp] 编译通过，输出与截图一致" -ForegroundColor Green
        $pass++
    } else {
        Write-Host "[$n.cpp] 输出与截图不一致" -ForegroundColor Yellow
        Write-Host ("    期望: " + ($c.Expect -join " | "))
        Write-Host ("    实际: " + ($body -join " | "))
        $fail++
    }
}

Write-Host "`n自测结果：通过 $pass 个，未通过 $fail 个" -ForegroundColor Cyan
