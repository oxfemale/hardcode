@echo off
cls
echo.
echo                    Kostomobiili 2 // C鶲鶺鶤鶵鶧  1�9�9�5
echo.
echo.
echo Mit剆 pannaan?
echo.
echo [1] GUS / GUS MAX
echo [2] None
echo [3] Quit to DOS
echo.
choice /c:123 /n
if errorlevel 3 goto end
if errorlevel 2 goto 2
if errorlevel 1 goto 1
:1
if exist spirit.mod del spirit.mod >nul
03.exe >nul
02.exe spirit.mod 01.exe
del spirit.mod >nul
goto end
:2
01.exe
goto end
:end
echo copywrong (c) C鶲鶺鶤鶵鶧  1�9�9�5
