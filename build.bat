@echo off
pwsh.exe -NoProfile -ExecutionPolicy Bypass -File "%~dp0build.ps1" %*
pause
