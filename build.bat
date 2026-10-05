@echo off
chcp 936 >nul
rem 结束后是否停住窗口：1=pause 等按键（默认，保持原行为），0=直接关闭。
rem 双击前可在本文件改默认值；命令行可覆盖：set PAUSE_ON_SUCCESS=0 && build.bat
if not defined PAUSE_ON_SUCCESS set PAUSE_ON_SUCCESS=1
pwsh.exe -NoProfile -ExecutionPolicy Bypass -File "%~dp0build.ps1" %*
if "%PAUSE_ON_SUCCESS%"=="1" pause