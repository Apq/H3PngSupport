$ErrorActionPreference = 'Stop'
$projDir = $PSScriptRoot
Push-Location $projDir
try {
    & "C:\Program Files\Microsoft Visual Studio\18\Enterprise\MSBuild\Current\Bin\MSBuild.exe" PngSupport.vcxproj /p:Configuration=Release /p:Platform=Win32 /m
    if ($LASTEXITCODE -ne 0) { Write-Host "编译失败"; exit 1 }
    Write-Host "编译完成: $projDir\Release\PngSupport.dll"
} catch {
    Write-Host "编译错误: $_"
    exit 1
} finally {
    Pop-Location
}