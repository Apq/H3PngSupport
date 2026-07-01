$ErrorActionPreference = 'Stop'
$root = Split-Path -Parent $MyInvocation.MyCommand.Path
$dll = Join-Path $root 'Release\PngSupport.dll'
$ini = Join-Path $root 'PngSupport.ini'

if (!(Test-Path $dll)) { throw "DLL not found: $dll" }

# 按本机常用路径部署；不存在则只输出构建产物位置。
$candidates = @(
  'D:\Games\Heroes3\_HD3_Data\Packs\H3PngSupport',
  'D:\Games\Heroes3\Mods\H3PngSupport'
)
$target = $candidates | Where-Object { Test-Path (Split-Path $_ -Parent) } | Select-Object -First 1
if ($target) {
  New-Item -ItemType Directory -Force -Path $target | Out-Null
  Copy-Item $dll $target -Force
  if (Test-Path $ini) { Copy-Item $ini $target -Force }
  Write-Host "Deployed to $target"
} else {
  Write-Host "Built: $dll"
  Write-Host "No known Heroes3 target directory found."
}
