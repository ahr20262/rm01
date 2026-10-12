# -*- coding: utf-8 -*-
<#
    self-test.ps1 —— 批量编译并自测本目录下的 5 个源文件
    用法：在本目录执行  powershell -ExecutionPolicy Bypass -File .\self-test.ps1
    要求：已安装 Visual Studio（MSVC），脚本会自动定位 vcvars64.bat
#>

$ErrorActionPreference = "Stop"
Set-Location -Path $PSScriptRoot
$outDir = Join-Path $PSScriptRoot "build"
New-Item -ItemType Directory -Force -Path $outDir | Out-Null
chcp 65001 > $null

# 期望输出（与 images/ 中截图运行结果一致）
$cases = @(
    @{ No = 1; In = "h`n";      Expect = @("H") },
    @{ No = 2; In = "123`n23`n"; Expect = @("有多少饮料", "有多少人", "每人有5.348", "一共有46杯") },
    @{ No = 3; In = "`n";        Expect = @(); Pending = $true },   # 占位文件，待补全源码
    @{ No = 4; In = "12`n";      Expect = @("有多少人", "要买120") },
    @{ No = 5; In = "3`n4`n5`n"; Expect = @("a, b, c为", "面积为6.0") }
)

# 定位 vcvars64.bat
$vcvars = Get-ChildItem "${env:ProgramFiles}\Microsoft Visual Studio\*\*\VC\Auxiliary\Build\vcvars64.bat" -ErrorAction SilentlyContinue |
          Select-Object -First 1 -ExpandProperty FullName
if (-not $vcvars) { Write-Host "未找到 vcvars64.bat，请手动在「x64 Native Tools Command Prompt」中运行本脚本" -ForegroundColor Red; exit 1 }
Write-Host "使用编译器环境: $vcvars`n" -ForegroundColor Cyan

$pass = 0; $fail = 0; $skip = 0
foreach ($c in $cases) {
    $n = $c.No
    $src = Join-Path $PSScriptRoot "$n.cpp"
    $exe = Join-Path $outDir "$n.exe"

    # 在 build 目录内编译，.obj 自然落在该目录，避免 /Fo 路径中反斜杠带来的引号转义问题
    Push-Location $outDir
    $build = cmd /c "call `"$vcvars`" >nul 2>&1 && cl /nologo /EHsc /utf-8 `"$src`" /Fe:`"$exe`" 2>&1"
    $code = $LASTEXITCODE
    Pop-Location
    if ($code -ne 0) {
        Write-Host "[$n.cpp] 编译失败" -ForegroundColor Red
        $build | Where-Object { $_ -match "error" } | ForEach-Object { Write-Host "    $_" }
        $fail++; continue
    }

    if ($c.Pending) {
        Write-Host "[$n.cpp] 编译通过，但源码为占位内容（截图未显示代码），待补全后自测" -ForegroundColor Yellow
        $skip++; continue
    }

    $tmp = Join-Path $outDir "$n.in"
    [System.IO.File]::WriteAllText($tmp, $c.In)
    $actual = @(cmd /c "chcp 65001 >nul && `"$exe`" < `"$tmp`"") | ForEach-Object { $_.TrimEnd() }

    $ok = ($actual.Count -eq $c.Expect.Count)
    if ($ok) { for ($i = 0; $i -lt $actual.Count; $i++) { if ($actual[$i] -ne $c.Expect[$i]) { $ok = $false } } }

    if ($ok) {
        Write-Host "[$n.cpp] 编译通过，输出与截图一致" -ForegroundColor Green
        $pass++
    } else {
        Write-Host "[$n.cpp] 输出与截图不一致" -ForegroundColor Yellow
        Write-Host ("    期望: " + ($c.Expect -join " | "))
        Write-Host ("    实际: " + ($actual -join " | "))
        $fail++
    }
}

Write-Host "`n自测结果：通过 $pass 个，未通过 $fail 个，待补全 $skip 个" -ForegroundColor Cyan
