$gameDir = 'D:\Heroes3\Heroes3_2026.05.01'
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
