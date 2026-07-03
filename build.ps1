param(
    [string]$Configuration = 'Release',
    [string]$Platform = 'Win32',
    [switch]$Rebuild
)

$ErrorActionPreference = 'Stop'

$projectName = 'PngSupport'
$projectFile = Join-Path $PSScriptRoot "$projectName.vcxproj"
$msbuild = 'C:\Program Files\Microsoft Visual Studio\18\Enterprise\MSBuild\Current\Bin\MSBuild.exe'

if (-not (Test-Path $msbuild)) {
    $cmd = Get-Command MSBuild.exe -ErrorAction SilentlyContinue
    if ($cmd) {
        $msbuild = $cmd.Source
    } else {
        throw "MSBuild not found: $msbuild"
    }
}

if (-not (Test-Path $projectFile)) {
    throw "Project file not found: $projectFile"
}

$target = if ($Rebuild) { 'Rebuild' } else { 'Build' }
$args = @(
    $projectFile,
    "/t:$target",
    "/p:Configuration=$Configuration",
    "/p:Platform=$Platform",
    '/m'
)

Write-Host "Building $projectName ($Configuration|$Platform)..."
& $msbuild @args
if ($LASTEXITCODE -ne 0) {
    exit $LASTEXITCODE
}

$dll = Join-Path $PSScriptRoot "$Configuration\$projectName.dll"
if (Test-Path $dll) {
    Write-Host "Build output: $dll"
    Get-FileHash $dll -Algorithm MD5 | Format-Table -AutoSize
} else {
    Write-Warning "Build finished, but output was not found: $dll"
}
