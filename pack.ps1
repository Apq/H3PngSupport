param(
    [string]$Source,
    [string]$OutputDir
)

$ErrorActionPreference = 'Stop'

Add-Type -AssemblyName System.IO.Compression
Add-Type -AssemblyName System.IO.Compression.FileSystem
Add-Type -AssemblyName System.Text.Encoding.CodePages -ErrorAction SilentlyContinue
[System.Text.Encoding]::RegisterProvider([System.Text.CodePagesEncodingProvider]::Instance)

# 2026-10-10 用户裁定：打包不再读游戏部署目录；DLL 取项目 Release 构建产物，
# 配置取仓库源文件。$Source 参数保留只为兼容旧调用，已不参与取材。
if (-not $OutputDir) {
    $OutputDir = Join-Path $PSScriptRoot 'Release'
}

function Get-PackVersion {
    $rcPath = Join-Path $PSScriptRoot 'PngSupport.rc'
    if (-not (Test-Path -LiteralPath $rcPath)) { return 'unknown' }
    $text = [System.Text.Encoding]::GetEncoding(936).GetString(
        [System.IO.File]::ReadAllBytes($rcPath))
    $match = [regex]::Match($text,
        '(?m)^\s*VALUE\s+"FileVersion"\s*,\s*"([^"]+)"')
    if (-not $match.Success) { return 'unknown' }
    $parts = $match.Groups[1].Value.Split('.')
    return 'v' + ($parts[0..1] -join '.')
}

# 显式清单只取本插件需要的文件；包内容保持既有清单，不扩为整个 Release 目录；
# 包内顶层目录沿用原压缩包目录名（PNG支持/）。
$files = @(
    @{ Local = Join-Path $PSScriptRoot 'Release\PngSupport.dll'; Entry = 'PNG支持/PngSupport.dll' },
    @{ Local = Join-Path $PSScriptRoot 'PngSupport.ini';         Entry = 'PNG支持/PngSupport.ini' }
)

$version = Get-PackVersion
New-Item -ItemType Directory -Force -Path $OutputDir | Out-Null
$zipPath = Join-Path $OutputDir "PNG支持_$version.zip"
if (Test-Path -LiteralPath $zipPath) {
    Remove-Item -LiteralPath $zipPath -Force
}

$included = 0
$zip = [System.IO.Compression.ZipFile]::Open(
    $zipPath, [System.IO.Compression.ZipArchiveMode]::Create)
try {
    foreach ($file in $files) {
        if (-not (Test-Path -LiteralPath $file.Local)) {
            throw "打包文件缺失: $($file.Local)"
        }
        [void][System.IO.Compression.ZipFileExtensions]::CreateEntryFromFile(
            $zip, $file.Local, $file.Entry,
            [System.IO.Compression.CompressionLevel]::Optimal)
        $included++
        Write-Host "加入 $($file.Entry)"
    }
} finally {
    $zip.Dispose()
}

if ($included -eq 0) {
    Remove-Item -LiteralPath $zipPath -Force
    throw '没有可打包的文件。'
}

Write-Host "已打包 $included 个文件: $zipPath"
