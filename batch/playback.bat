@echo off

REM Environment variables
SET MAMELOCATION=C:\MAME
SET INPLOCATION=%MAMELOCATION%\inp
SET DOWNLOCATION=C:\MAME\inp\MARP
SET DONELOCATION=C:\MAME\inp\MARP\Done
SET DOSBOXEXE=C:\Program Files\DOSBox-0.74\DOSBox.exe
SET DOSBOXCONF=%MAMELOCATION%\dosbox.conf
SET ZIP=C:\Program Files\7-Zip\7z.exe
SET ZIPFLAGS=e -y -o%DOWNLOCATION%
SET MAMEFLAGSOLD=-w -nomax -nodd -nothrottle -fs 0 -noafs
SET MAMEFLAGSFULLSCREEN=-nomax -nothrottle -fs 0 -noafs
SET MAMEFLAGS=-w %MAMEFLAGSFULLSCREEN%

REM Which range of MAME versions is best to start in full screen
REM Note: if you want all to start in full screen, remove the "-w" from MAMEFLAGS
SET MVERFSLOW=36
SET MVERFSHIGH=60

REM Get current working directory
cd>%MAMELOCATION%\cwd.txt
SET /P CWD=<%MAMELOCATION%\cwd.txt

REM Extract the zip file
"%ZIP%" %ZIPFLAGS% %DOWNLOCATION%\*.zip
"%ZIP%" %ZIPFLAGS% %DOWNLOCATION%\*.rar
SET ZIPERR=%ERRORLEVEL%
IF %ZIPERR% EQU 0 GOTO ZIPOK
ECHO Zip exit code not zero: %ZIPERR%
GOTO EOF

:ZIPOK
cd "%DOWNLOCATION%"
RENAME *.inp %2.inp
RENAME *.wlf %2.wlf
cd %CWD%
MOVE "%DOWNLOCATION%\%2.inp" "%INPLOCATION%\"
IF EXIST "%DOWNLOCATION%\%2.wlf" MOVE "%DOWNLOCATION%\%2.wlf" "%INPLOCATION%\"

REM Work out the version of MAME
SET MEXE=%1
SET MVER=%1
SET MREM=%MVER:~2,1%
SET TARGET=MVERTHIRD
SET RETURN=TESTTHIRD
GOTO MVERCHECK
:TESTTHIRD
SET TARGET=MVERFOURTH
SET MREM=%MVER:~3,1%
SET RETURN=MVERNUMERIC
GOTO MVERCHECK


:MVERCHECK
IF "%MREM%" == "b" GOTO %TARGET%
IF "%MREM%" == "o" GOTO %TARGET%
IF "%MREM%" == "u" GOTO %TARGET%
IF "%MREM%" == "w" GOTO %TARGET%
GOTO %RETURN%

REM 91u1, for example
:MVERTHIRD
SET MREM=%MVER:~2,9%
SET MVER=%MVER:~0,2%
GOTO MVERNUMERIC

REM 102u1, for example
:MVERFOURTH
SET MREM=%MVER:~3,9%
SET MVER=%MVER:~0,3%
GOTO MVERNUMERIC

:MVERNUMERIC
ECHO MAME Version %MVER%
ECHO MAME remainder information: %MREM%

REM Default to no -nvram_directory paramater
SET NVRAM=

REM Determine NVRAM options
IF %MVER% GTR 135 GOTO NVRAM
GOTO NONVRAM

:NVRAM
SET NVRAM=-nvram_directory NUL

:NONVRAM

REM Determine INP options
IF %MVER% GTR 100 GOTO WITHINP
SET INPNAME=%2
IF %MVER% GTR 30 GOTO NOINP
REM MAME 0.30 requires INP folder prefix but no extension
SET INPNAME=INP\%2
GOTO NOINP

:WITHINP
SET INPNAME=%2.inp

:NOINP
REM Determine game options
IF "%3" == "" GOTO DEFAULTGAME
SET GAME=%3
GOTO HAVEGAME

:DEFAULTGAME
SET GAME=%2

:HAVEGAME
REM Backup current configuration for game
if exist cfg\%GAME% move cfg\%GAME% cfg\%GAME%.dir
if exist cfg\%GAME%.cfg move cfg\%GAME%.cfg cfg\%GAME%.bak
if exist hi\%GAME% move hi\%GAME% hi\%GAME%.dir
if exist hi\%GAME%.hi move hi\%GAME%.hi hi\%GAME%.bak
if exist nvram\%GAME% move nvram\%GAME% nvram\%GAME%.dir
if exist nvram\%GAME%.nv move nvram\%GAME%.nv nvram\%GAME%.bak
if exist diff\%GAME% move diff\%GAME% diff\%GAME%.dir
if exist diff\%GAME%.dif move diff\%GAME%.dif diff\%GAME%.bak

IF %MVER% GTR 37 GOTO WINDOWSCHECK
:DOSBOXENTRY
REM Use DOSBox
SET MAMEEXE=M%MEXE%.EXE
IF NOT EXIST %MAMEEXE% GOTO WINDOWS
COPY %DOSBOXCONF% TEMP.CONF
echo MOUNT C: %MAMELOCATION%>>TEMP.CONF
echo C:>>TEMP.CONF
IF %MVER% LEQ 34 GOTO DOSWITHRES
echo %MAMEEXE% %GAME% -fs 0 -playback %INPNAME% -soundcard 1 %3 %4 %5 %6 %7 %8 %9>>TEMP.CONF
GOTO DOSEXIT
:DOSWITHRES
echo %MAMEEXE% %GAME% -fs 0 -playback %INPNAME% -soundcard 1 -640x480 %3 %4 %5 %6 %7 %8 %9>>TEMP.CONF
:DOSEXIT
echo exit>>TEMP.CONF
GOTO RUNDOSBOX

:RUNDOSBOX
"%DOSBOXEXE%" -conf TEMP.CONF
GOTO CLEANUP

:WINDOWSCHECK
IF EXIST M%MEXE%.EXE GOTO DOSBOXENTRY
:WINDOWS
SET MAMEEXE=mame%MEXE%.EXE
IF NOT EXIST %MAMEEXE% GOTO MISSINGMAME

REM Check if full-screen: MAMEs 55 & 56 have blit issues when starting in a window
IF %MVER% GTR %MVERFSHIGH% GOTO FLAGSFINE
IF %MVER% LEQ %MVERFSLOW% GOTO FLAGSFINE
SET MAMEFLAGS=%MAMEFLAGSOLD%
GOTO FLAGSFINE

:FLAGSFINE
REM Check for early WolfMAMEs with mameplib.dll requirement
REM Assumes the relevant mameplib.dll will exist as mamep<ver>lib.dll like the newer ones.
REM - not required: IF %MVER% GTR 82 GOTO PLIBDONE
IF EXIST mameplib.dll DEL mameplib.dll
SET MLIB=mamep%MVER%lib.dll
IF EXIST %MLIB% COPY %MLIB% mameplib.dll
IF %MVER% GTR 84 GOTO WITHIV

:PLIBDONE
%MAMEEXE% %MAMEFLAGS% -playback %INPNAME% %GAME% %4 %5 %6 %7 %8 %9 %NVRAM%
GOTO CLEANUPWIN

:WITHIV
REM o = original: they don't have -iv option.
IF "%MREM:~0,1%" == "o" GOTO PLIBDONE
IF "%MREM:~0,1%" == "w" GOTO PLIBDONE
%MAMEEXE% %MAMEFLAGS% -iv 1 -playback %INPNAME% %GAME% %4 %5 %6 %7 %8 %9 %NVRAM%
GOTO CLEANUPWIN

:CLEANUPWIN
IF EXIST "%INPLOCATION%\%GAME%.wlf" GOTO WLFVIEW
GOTO CLEANUP

:WLFVIEW
ECHO Checking if wlfview%MEXE%.exe exists
IF NOT EXIST wlfview%MEXE%.exe GOTO CLEANUP
ECHO Checking with Wlfview
wlfview%MEXE%.exe "%INPLOCATION%\%GAME%.wlf" "%INPLOCATION%\%GAME%.inp"
GOTO CLEANUP

:CLEANUP
REM if %MVER% GTR 124 analinp2.exe %INPLOCATION%\%2.inp
if exist cfg\%GAME%.dir move cfg\%GAME%.dir cfg\%GAME%
if exist cfg\%GAME%.bak move cfg\%GAME%.bak cfg\%GAME%.cfg
if exist hi\%GAME%.dir move hi\%GAME%.dir hi\%GAME%
if exist hi\%GAME%.bak move hi\%GAME%.bak hi\%GAME%.hi
if exist nvram\%GAME%.dir move nvram\%GAME%.dir nvram\%GAME%
if exist nvram\%GAME%.bak move nvram\%GAME%.bak nvram\%GAME%.nv
if exist diff\%GAME%.dir move diff\%GAME%.dir diff\%GAME%
if exist diff\%GAME%.bak move diff\%GAME%.bak diff\%GAME%.dif
if exist %INPLOCATION%\%2.inp del %INPLOCATION%\%2.inp
if exist %INPLOCATION%\%2.wlf del %INPLOCATION%\%2.wlf
del %DOWNLOCATION%\*.png>NUL
move "%DOWNLOCATION%\*.zip" "%DONELOCATION%\"
move "%DOWNLOCATION%\*.rar" "%DONELOCATION%\"
GOTO EOF

:MISSINGMAME
dir M%MVER%*.* MAME%MVER%*.* /w
echo MAME executable (%MAMEEXE%) not found.
GOTO EOF

:EOF