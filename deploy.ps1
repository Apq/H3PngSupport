$ErrorActionPreference = 'Stop'
# 共享部署目标：$env:H3_GAME_DIR > 仓库根 H3Env.ps1 > 内置默认值（换版本改 H3Env.ps1）。
$h3root = Split-Path -Parent $PSScriptRoot
if (Test-Path -LiteralPath "$h3root\H3Env.ps1") { . "$h3root\H3Env.ps1" }
if (-not (Get-Command Get-H3GameDir -ErrorAction SilentlyContinue)) {
    function Get-H3GameDir {
        if ($env:H3_GAME_DIR -and (Test-Path -LiteralPath $env:H3_GAME_DIR)) { $env:H3_GAME_DIR }
        else { 'D:\Heroes3\Heroes3_2026.10.09' }
    }
}
$gameDir = Get-H3GameDir
$packsDst = "$gameDir\_HD3_Data\Packs\PNG支持"
# $PSScriptRoot 是 PowerShell 自动变量，表示当前 deploy.ps1 所在目录。
$src = "$PSScriptRoot\Release"

# --- PngSupport 插件 ---
if (-not (Test-Path $packsDst)) {
    New-Item -ItemType Directory -Path $packsDst -Force | Out-Null
}
Copy-Item "$src\PngSupport.dll" $packsDst -Force
Copy-Item "$PSScriptRoot\PngSupport.ini" $packsDst -Force

Write-Host "已部署到 $packsDst"
