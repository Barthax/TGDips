@echo off

REM Environment variables
SET MAMELOCATION=C:\MAME
SET INPLOCATION=%MAMELOCATION%\inp
SET DOWNLOCATION=%INPLOCATION%\MARP
SET DONELOCATION=%DOWNLOCATION%\Done
SET SRCLOCATION=E:\projects\MAME\dips
SET STOPWHENNOSRCTXT=true
SET DISPLAYSRCTXT=true
SET INCLUDEMAMEINFODUMP=true
SET FIRSTMAMEWITHCOMPRESSEDINP=129
SET FIRSTWOLFMAMEWITHDIPSONSHOW=149
SET RUNROMCHANGEDONMISSING=true
SET FIRSTMAMEREQUIRINGINPEXTENSION=107
SET DOSMAMECLI=-fs 0
SET WINMAMECLI=-nomax -nothrottle

REM Expectations:
REM INP Decompressor
SET INPDECOMP=inptest.exe

REM Gnu's CoreUtils installed
REM http://gnuwin32.sourceforge.net/packages/coreutils.htm
REM Gnu's Grep installed (install to same location!)
REM http://gnuwin32.sourceforge.net/packages/grep.htm
SET GNU=C:\Program Files\GnuWin32\bin

REM 7-Zip installation location
REM http://www.7-zip.org/download.html
SET ZIP=C:\Program Files\7-Zip\7z.exe
SET ZIPFLAGS=e -y -o%DOWNLOCATION%
SET ZIPTEST=t
SET ZIPLIST=l -slt

REM XD
REM https://www.fourmilab.ch/xd/
SET HEXDUMP=xd.exe
SET HEXDUMPFLAGS=-c
REM -or-
REM Rich Paso's HEXDump copied to MAMELOCATION
REM http://www.richpasco.org/utilities/hexdump.html
REM SET HEXDUMP=hexdump.exe
REM SET HEXDUMPFLAGS=

REM DOS Box installed
REM http://www.dosbox.com/download.php?main=1
SET DOSBOXEXE=C:\Program Files\DOSBox-0.74\DOSBox.exe
REM Default DOS Box configuration copied to:
SET DOSBOXCONF=%MAMELOCATION%\dosbox.conf

REM The output will be recorded in:
SET LOG=%MAMELOCATION%\CHECK.TXT
REM Junk information can go in:
SET TEMPFILE=Tempfile.txt
SET TEMPFILE2=Tempfile2.txt
SET TEMPFILE3=Tempfile3.txt

REM Whether to separate ini files on a per-version basis and where.
REM the path will be formed with the Base\PrefixVersionSuffix
SET USEINIDIR=true
SET INIDIRBASE=%MAMELOCATION%\ini
SET INIDIRPREFIX=ini
SET INIDIRSUFFIX=

REM Check for localised configuration changes
IF EXIST checkconf.bat @CALL checkconf.bat

:ENVIRONDONE
ECHO [B]*** DISCLAIMER ***>%LOG%
ECHO The following tests and reports are neither exhaustive nor definitive,>>%LOG%
ECHO and should not be assumed as such in order to verify authenticity of a submission.[/B]>>%LOG%
ECHO.>>%LOG%

ECHO Environment:
ECHO MAME Location: %MAMELOCATION%
ECHO INP Location: %INPLOCATION%
ECHO Download Location: %DOWNLOCATION%
ECHO Done Location: %DONELOCATION%
ECHO Source Location: %SRCLOCATION%
ECHO GNU: %GNU%
ECHO 7-Zip: %ZIP%
ECHO Hex: %HEXDUMP%
ECHO DOS Box: %DOSBOXEXE%
ECHO Log: %LOG%
ECHO Temp 1: %TEMPFILE%
ECHO Temp 2: %TEMPFILE2%
ECHO Temp 3: %TEMPFILE3%
ECHO Starting %0 on %DATE% at %TIME%>>%LOG%
ECHO.>>%LOG%

REM Get current working directory
cd>%MAMELOCATION%\%TEMPFILE%
SET /P CWD=<%MAMELOCATION%\%TEMPFILE%
ECHO Current location: %CWD%

REM Test, List and Extract the zip/rar file
SET INPEXIST=0
REM Check for an INP file
for %%f in ("%DOWNLOCATION%\*.inp") do SET INPEXIST=1
ECHO Zip test>>%LOG%
ECHO [CODE]>>%LOG%
ECHO Zip:>>%LOG%
"%ZIP%" %ZIPTEST% %DOWNLOCATION%\*.zip>>%LOG%
ECHO RAR:>>%LOG%
"%ZIP%" %ZIPTEST% %DOWNLOCATION%\*.rar>>%LOG%
ECHO [/CODE]>>%LOG%
ECHO.>>%LOG%
ECHO Zip list>>%LOG%
ECHO [CODE]>>%LOG%
"%ZIP%" %ZIPLIST% %DOWNLOCATION%\*.zip>>%LOG%
"%ZIP%" %ZIPLIST% %DOWNLOCATION%\*.rar>>%LOG%
IF %INPEXIST% GTR 0 ECHO INP listing:>>%LOG%
IF %INPEXIST% GTR 0 DIR /4 "%DOWNLOCATION%\*.inp">>%LOG%
ECHO [/CODE]>>%LOG%
ECHO.>>%LOG%
"%ZIP%" %ZIPFLAGS% %DOWNLOCATION%\*.zip >NUL 2>&1
SET ZIPERR=%ERRORLEVEL%
IF %ZIPERR% EQU 0 GOTO ZIPOK
"%ZIP%" %ZIPFLAGS% %DOWNLOCATION%\*.rar >NUL 2>&1
SET ZIPERR=%ERRORLEVEL%
IF %ZIPERR% EQU 0 GOTO ZIPOK
ECHO Zip exit code not zero: %ZIPERR%
IF %INPEXIST% GTR 0 GOTO ZIPOK
GOTO REALCLEANUP

:ZIPOK
cd "%DOWNLOCATION%"
IF %INPEXIST% GTR 0 COPY "%DOWNLOCATION%\*.inp" "%DONELOCATION%\"
IF %INPEXIST% GTR 0 COPY "%DOWNLOCATION%\*.wlf" "%DONELOCATION%\"
RENAME *.inp %2.inp >NUL 2>&1
RENAME *.wlf %2.wlf >NUL 2>&1
cd %CWD%
ECHO Checking Down location %DOWNLOCATION%
DIR "%DOWNLOCATION%\%2.inp"
MOVE "%DOWNLOCATION%\%2.inp" "%INPLOCATION%\" >NUL 2>&1
ECHO After moving to INP location %INPLOCATION%
DIR "%INPLOCATION%\%2.inp"
IF EXIST "%DOWNLOCATION%\%2.wlf" MOVE "%DOWNLOCATION%\%2.wlf" "%INPLOCATION%\"

REM Work out the version of MAME
REM WolfMAMEs are expected to have no suffix (or -1/u1 where multiple of same version)
REM b suffix is expected for DOS versions
REM o suffix is expected for Original versions
REM w suffix for MAME32 versions of whatever
REM should support others without need of further.. but I'm lazy.
SET MEXE=%1
SET MVER=%1
IF "%MVER:~2,1%" == "b" GOTO MVERTHIRD
IF "%MVER:~2,1%" == "o" GOTO MVERTHIRD
IF "%MVER:~2,1%" == "u" GOTO MVERTHIRD
IF "%MVER:~2,1%" == "w" GOTO MVERTHIRD
IF "%MVER:~2,1%" == "-" GOTO MVERTHIRD
IF "%MVER:~3,1%" == "o" GOTO MVERFOURTH
IF "%MVER:~3,1%" == "u" GOTO MVERFOURTH
IF "%MVER:~3,1%" == "w" GOTO MVERFOURTH
IF "%MVER:~3,1%" == "-" GOTO MVERFOURTH
GOTO MVERNUMERIC

REM 91u1, for example
:MVERTHIRD
SET MVER=%MVER:~0,2%
GOTO MVERNUMERIC

REM 102u1, for example
:MVERFOURTH
SET MVER=%MVER:~0,3%
GOTO MVERNUMERIC

:MVERNUMERIC
ECHO MAME Major Version %MVER%
ECHO MAME Major Version %MVER%>>%LOG%
ECHO.>>%LOG%
SET MAMEEXE=MAME%MEXE%.EXE

REM Default to no -nvram_directory paramater
SET NVRAM=

REM Determine NVRAM options
IF %MVER% GTR 135 GOTO NVRAM
GOTO NONVRAM

:NVRAM
SET NVRAM=-nvram_directory NUL

:NONVRAM
IF NOT EXIST "%INPLOCATION%\%2.inp" GOTO MISSINGINP

REM Determine INP options
IF %MVER% GTR %FIRSTMAMEREQUIRINGINPEXTENSION% GOTO WITHINP
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
REM Determine which command-line to use for getting source files.
SET LISTSOURCE=-listsource
IF %MVER% GTR 99 GOTO LISTNEWSOURCE
ECHO Extracting source knowledge (pre-v99)
SET LISTSOURCE=-listsourcefile

:LISTNEWSOURCE
REM Check for early WolfMAMEs with mameplib.dll requirement
REM Assumes the relevant mameplib.dll will exist as mamep<ver>lib.dll like the newer ones.
REM - not required: IF %MVER% GTR 82 GOTO PLIBDONE
IF EXIST mameplib.dll DEL mameplib.dll
SET MLIB=mamep%MVER%lib.dll
IF EXIST %MLIB% COPY %MLIB% mameplib.dll

:PLIBDONE
REM Don't check for a version-specific file after 148
IF %MVER% GEQ %FIRSTWOLFMAMEWITHDIPSONSHOW% GOTO NOVERSPECDIAGTXT
REM Check for a version-specific file
if not exist %SRCLOCATION%\%MVER%\%GAME%.txt GOTO NODIAGTXT
GOTO HAVEDIAGTXT

:NOVERSPECDIAGTXT
if not exist %SRCLOCATION%\%GAME%.txt GOTO NOGENDIAGTXT
GOTO HAVEDIAGTXT

:NOGENDIAGTXT
ECHO Do not have %SRCLOCATION%\%GAME%.txt for diagnostic
IF "%RUNROMCHANGEDONMISSING%" == "true" call romchanged %GAME%

:NODIAGTXT
IF "%STOPWHENNOSRCTXT%" == "true" GOTO NODIAGAVAIL

:HAVEDIAGTXT
IF "%DISPLAYSRCTXT%"=="true" start notepad "%SRCLOCATION%\%GAME%.txt"
REM Backup current configuration for game
if exist cfg\%GAME% move cfg\%GAME% cfg\%GAME%.dir
if exist cfg\%GAME%.cfg move cfg\%GAME%.cfg cfg\%GAME%.bak
if exist hi\%GAME% move hi\%GAME% hi\%GAME%.dir
if exist hi\%GAME%.hi move hi\%GAME%.hi hi\%GAME%.bak
if exist nvram\%GAME% move nvram\%GAME% nvram\%GAME%.dir
if exist nvram\%GAME%.nv move nvram\%GAME%.nv nvram\%GAME%.bak
if exist diff\%GAME% move diff\%GAME% diff\%GAME%.dir
if exist diff\%GAME%.dif move diff\%GAME%.dif diff\%GAME%.bak

IF %MVER% GTR 37 GOTO WINDOWS
REM Use DOSBox
SET MAMEEXE=M%MEXE%.EXE
IF NOT EXIST %MAMEEXE% GOTO WINDOWS
ECHO DOS MAME Executable: %MAMEEXE%
COPY %DOSBOXCONF% TEMP.CONF
echo MOUNT C: %MAMELOCATION%>>TEMP.CONF
echo C:>>TEMP.CONF
echo %MAMEEXE% %GAME% %DOSMAMECLI% -playback %GAME% -soundcard 1 %3 %4 %5 %6 %7 %8 %9>>TEMP.CONF
echo exit>>TEMP.CONF
GOTO RUNDOSBOX

:RUNDOSBOX
"%DOSBOXEXE%" -conf TEMP.CONF
GOTO HEXDUMP

:WINDOWS
SET MAMEEXE=mame%MEXE%.EXE
IF NOT EXIST %MAMEEXE% GOTO MISSINGMAME

REM Prepare -inipath if necessary
IF %USEINIDIR%==true GOTO PREPAREINIPATH
SET INIPATH=
GOTO NOINIPATH

:PREPAREINIPATH
SET INIPATH=-inipath "%INIDIRBASE%\%INIDIRPREFIX%%MVER%%INIDIRSUFFIX%"

:NOINIPATH
ECHO MAME Executable: %MAMEEXE%
ECHO What MAME thinks:>>%LOG%
ECHO [CODE]>>%LOG%

REM Check for early WolfMAMEs and MAME Plus! with mameplib.dll requirement
REM Assumes the relevant mameplib.dll will exist as mamep<ver>lib.dll like the newer ones.
IF EXIST mameplib.dll DEL mameplib.dll
SET MLIB=mamep%MVER%lib.dll
ECHO MAMEPLIB: %MLIB%
IF EXIST %MLIB% COPY %MLIB% mameplib.dll

REM 0.85 introduced the -iv option.
IF %MVER% GTR 84 GOTO WITHIV

:PLIBDONE
echo Starting MAME - you may need to press a key for older versions
%MAMEEXE% -w %INIPATH% %WINMAMECLI% -playback %INPNAME% %GAME% %4 %5 %6 %7 %8 %9 %NVRAM%| find /v "INPVIEW" | find /v "OpenGL" | "%GNU%\tee.exe" -a %LOG%
GOTO CLEANUPWIN

:WITHIV
echo Starting MAME - you may need to press a key for older versions like 0.106
%MAMEEXE% -w %INIPATH% %WINMAMECLI% -iv 1 -playback %INPNAME% %GAME% %4 %5 %6 %7 %8 %9 %NVRAM%| find /v "INPVIEW" | find /v "OpenGL" | "%GNU%\tee.exe" -a %LOG%
GOTO CLEANUPWIN

:CLEANUPWIN
ECHO [/CODE]>>%LOG%
ECHO.>>%LOG%
IF EXIST "%INPLOCATION%\%GAME%.wlf" GOTO WLFVIEW
GOTO CLEANUPWIN2

:WLFVIEW
ECHO Checking with Wlfview
ECHO.>>%LOG%
ECHO What wlfview thinks:>>%LOG%
echo [CODE]>>%LOG%
wlfview%MVER%.exe "%INPLOCATION%\%GAME%.wlf" "%INPLOCATION%\%GAME%.inp">>%LOG%
echo [/CODE]>>%LOG%
GOTO CLEANUPWIN2


:CLEANUPWIN2
ECHO.>>%LOG%
ECHO Source driver:>>%LOG%
SET SOURCEFILE=
ECHO Extracting source knowledge
%MAMEEXE% %LISTSOURCE% %GAME%
%MAMEEXE% %LISTSOURCE% %GAME%>>%LOG%
%MAMEEXE% %LISTSOURCE% %GAME%| "%GNU%\cut.exe" "-d " -f2->%TEMPFILE%

:SOURCECLEAN
SET /P SOURCEFILE=<%TEMPFILE%
FOR /f "tokens=* delims= " %%a in ("%SOURCEFILE%") DO SET SOURCEFILE=%%a
IF "%SOURCEFILE%" == "" GOTO NOSOURCE
REM Remove any directory structure
"%GNU%\basename.exe" %SOURCEFILE% >%TEMPFILE%
SET /P SOURCEFILE=<%TEMPFILE%

IF EXIST %SRCLOCATION%\%MVER%\%GAME%.TXT GOTO TYPEGAMEVER
IF EXIST %SRCLOCATION%\%GAME%.TXT GOTO TYPEGAME
IF EXIST %SRCLOCATION%\%SOURCEFILE% GOTO TYPESRC
ECHO DIP Info from source not acquired (%SRCLOCATION%\%SOURCEFILE%).>>%LOG%
ECHO.>>%LOG%
GOTO HEXDUMP

:NOSOURCE
ECHO List source option %LISTSOURCE% option failed to indicate for %GAME%
GOTO HEXDUMP

:TYPEGAMEVER
ECHO DIP Info from source:>>%LOG%
ECHO [CODE]>>%LOG%
TYPE %SRCLOCATION%\%MVER%\%GAME%.TXT>>%LOG%
ECHO [/CODE]>>%LOG%
ECHO.>>%LOG%
IF EXIST %SRCLOCATION%\%GAME%.txt GOTO TYPEGAME
GOTO HEXDUMP

:TYPEGAME
ECHO Generic Info for game:>>%LOG%
ECHO [CODE]>>%LOG%
TYPE %SRCLOCATION%\%GAME%.TXT>>%LOG%
ECHO [/CODE]>>%LOG%
ECHO.>>%LOG%
GOTO HEXDUMP

:TYPESRC
ECHO DIP Info from source:>>%LOG%
ECHO [CODE]>>%LOG%
TYPE %SRCLOCATION%\%SOURCEFILE%>>%LOG%
ECHO [/CODE]>>%LOG%
ECHO.>>%LOG%
GOTO HEXDUMP

:HEXDUMP
SET INPNAME=%INPLOCATION%\%2.inp
IF %MVER% GEQ %FIRSTWOLFMAMEWITHDIPSONSHOW% GOTO NOHEXDUMP
IF %MVER% GEQ %FIRSTMAMEWITHCOMPRESSEDINP% GOTO DECOMPRESSINP
GOTO PERFORMHEXDUMP

:DECOMPRESSINP
%INPDECOMP% %INPNAME% %TEMPFILE%
MOVE %TEMPFILE% %INPNAME%
GOTO PERFORMHEXDUMP

:PERFORMHEXDUMP
ECHO Generating hexdump sections
REM HEX Dump the header, middle and tail
%HEXDUMP% %INPNAME% | "%GNU%\wc.exe" -l >%TEMPFILE%
SET /P LINES=<%TEMPFILE%
REM Work out half-way plus ten lines
SET /a LINES=(%LINES%/2+10)

%HEXDUMP% %HEXDUMPFLAGS% %INPNAME% >%TEMPFILE%
REM Dump first 20 lines of hex
echo - Head
echo INP Header:>>%LOG%
echo [CODE]>>%LOG%
"%GNU%\head.exe" -n 21 %TEMPFILE% | "%GNU%\tail.exe" -n 20>>%LOG%
echo [/CODE]>>%LOG%

REM Dump mid 20 lines of hex
echo.>>%LOG%
echo - Mid
echo INP Mid-section:>>%LOG%
echo [CODE]>>%LOG%
"%GNU%\head.exe" -n %LINES% %TEMPFILE% | "%GNU%\tail.exe" -n 20>>%LOG%
echo [/CODE]>>%LOG%

REM Dump last 20 lines of hex
echo.>>%LOG%
echo - Tail
echo INP Tail-end:>>%LOG%
echo [CODE]>>%LOG%
"%GNU%\tail.exe" -n 20 %TEMPFILE% >>%LOG%
echo.>>%LOG%
echo [/CODE]>>%LOG%
GOTO MAMEINFODAT

:NOHEXDUMP
echo INP dump not relevant>>%LOG%

:MAMEINFODAT
IF NOT EXIST %MAMELOCATION%\MAMEINFO.DAT GOTO CLEANUP
IF "%INCLUDEMAMEINFODUMP%" == "false" GOTO CLEANUPNOCODECLOSE

REM ToDo: Try to extract the history from MAMEInfo
ECHO.>>%LOG%
ECHO.>>%LOG%
ECHO MAME Info>>%LOG%
REM Use mame.exe -listclones <game>
%MAMEEXE% -listclones %GAME%| "%GNU%\grep.exe" -v "Clone"| "%GNU%\wc.exe" -l | "%GNU%\head.exe" -n1 >%TEMPFILE%
MOVE %TEMPFILE% %TEMPFILE2%
"%GNU%\cut.exe" "-d " -f2- "%TEMPFILE2%"  >%TEMPFILE%
SET /P NUMCLONES=<%TEMPFILE%
REM Assume this is the parent initially
SET PARENT=%GAME%
REM If only one line, this is the parent (no clones)
IF %NUMCLONES% EQU 0 GOTO HAVEPARENT
REM If more than two lines, this is the parent.
IF %NUMCLONES% GTR 1 GOTO HAVEPARENT
GOTO CHECKPARENT

:CHECKPARENT
REM If only one line, the parent is in the second column.
%MAMEEXE% -listclones %GAME%| "%GNU%\grep.exe" -v "Clone"| "%GNU%\head.exe" -n1 >%TEMPFILE%
SET /P CLONEINFO=<%TEMPFILE%
echo %CLONEINFO% | "%GNU%\cut.exe" "-d " -f2->%TEMPFILE%
SET /P CLONEINFO=<%TEMPFILE%
FOR /f "tokens=* delims= " %%a in ("%CLONEINFO%") DO SET CLONEINFO=%%a
SET CLONEINFO=%CLONEINFO%##
SET CLONEINFO=%CLONEINFO:      ##=##%
SET CLONEINFO=%CLONEINFO:     ##=##%
SET CLONEINFO=%CLONEINFO:    ##=##%
SET CLONEINFO=%CLONEINFO:   ##=##%
SET CLONEINFO=%CLONEINFO:  ##=##%
SET CLONEINFO=%CLONEINFO: ##=##%
SET CLONEINFO=%CLONEINFO:##=%
IF "%GAME%" == "%CLONEINFO%" GOTO ISPARENT
ECHO %GAME% is clone of: %CLONEINFO%>>%LOG%
GOTO PARENTCHECKED
:ISPARENT
ECHO %GAME% is the parent set.>>%LOG%
:PARENTCHECKED
REM Right-trim the clone info
SET PARENT=%CLONEINFO%
GOTO HAVEPARENT

:HAVEPARENT
REM Search MAMEInfo.dat for a line beginning $info=<parent>
REM This section completes with a single line $end
ECHO MAMEInfo.dat entries: %PARENT% and %SOURCEFILE%>>%LOG%
ECHO [CODE]>>%LOG%
ECHO Search MAMEInfo.dat for %PARENT%
"%GNU%\grep.exe" -n "\$info=%PARENT%" mameinfo.dat | "%GNU%\cut.exe" "-d:" -f1 >%TEMPFILE2%
"%GNU%\grep.exe" -n "\$info=%PARENT%" mameinfo.dat >%TEMPFILE3%
IF "%PARENT%" == "%GAME%" GOTO MAMEINFOSOURCE
ECHO Search MAMEInfo.dat for %GAME%
"%GNU%\grep.exe" -n "\$info=%GAME%" mameinfo.dat | "%GNU%\cut.exe" "-d:" -f1 >>%TEMPFILE2%
"%GNU%\grep.exe" -n "\$info=%GAME%" mameinfo.dat >>%TEMPFILE3%
:MAMEINFOSOURCE
ECHO Search MAMEInfo.dat for %SOURCEFILE%
"%GNU%\grep.exe" -n "\$info=%SOURCEFILE%" mameinfo.dat | "%GNU%\cut.exe" "-d:" -f1 >>%TEMPFILE2%
"%GNU%\grep.exe" -n "\$info=%SOURCEFILE%" mameinfo.dat >>%TEMPFILE3%
"%GNU%\sort.exe" -u %TEMPFILE2% >%TEMPFILE%
"%GNU%\sort.exe" -u %TEMPFILE3% >%TEMPFILE2%
"%GNU%\cut.exe" "-d=" -f2- %TEMPFILE2%>%TEMPFILE3%
ECHO MAMEInfo.dat entries for:>>%LOG%
TYPE %TEMPFILE3%>>%LOG%
ECHO ---->>%LOG%
REM Now have the line numbers of relevant information in %TEMPFILE%
SET PREVLINE=0

:CYCLELINENUMS
"%GNU%\wc.exe" -l %TEMPFILE% | "%GNU%\cut.exe" "-d " -f1 | "%GNU%\head.exe" -n1 >%TEMPFILE3%
SET /P TOGO=<%TEMPFILE3%
IF %TOGO% EQU 0 GOTO CLEANUP
SET /P LINENUM=<%TEMPFILE%
DEL %TEMPFILE2% >NUL 2>&1
MOVE %TEMPFILE% %TEMPFILE2%
"%GNU%\tail.exe" -n+2 %TEMPFILE2%>%TEMPFILE%
REM Skip the file formatting lines
SET /A LINENUM=%LINENUM%+2
"%GNU%\tail.exe" -n+%LINENUM% mameinfo.dat>%TEMPFILE2%
REM Redirect cut's error output to nul as it will whinge when head cuts off the pipe.
"%GNU%\grep.exe" -n "\$end" %TEMPFILE2% | "%GNU%\cut.exe" "-d:" -f1 2>nul | "%GNU%\head.exe" -n1 >%TEMPFILE3%
SET /P LINENUM=<%TEMPFILE3%
REM Don't include the $end line
SET /A LINENUM=%LINENUM%-1
"%GNU%\head.exe" -n%LINENUM% %TEMPFILE2%>>%LOG%
echo ---->>%LOG%
GOTO CYCLELINENUMS

:CLEANUP
echo [/CODE]>>%LOG%
:CLEANUPNOCODECLOSE
echo.>>%LOG%
echo Human interpretation:>>%LOG%
echo Achievement accomplished: >>%LOG%
echo WolfMAME used: >>%LOG%
echo Recorded speed: >>%LOG%
echo DIP-switches: >>%LOG%
echo Time calc: >>%LOG%
echo Dates: >>%LOG%
echo Autofire detected?: >>%LOG%
echo ROM set changed?: >>%LOG%
:REALCLEANUP
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
if exist %TEMPFILE% del %TEMPFILE%
if exist %TEMPFILE2% del %TEMPFILE2%
if exist %TEMPFILE3% del %TEMPFILE3%
del %DOWNLOCATION%\*.png>NUL 2>&1
move "%DOWNLOCATION%\*.zip" "%DONELOCATION%\"
move "%DOWNLOCATION%\*.rar" "%DONELOCATION%\"
start notepad %LOG%
GOTO EOF

:MISSINGINP
echo INP not found for %2
GOTO EOF

:MISSINGMAME
echo MAME executable (%MAMEEXE%) not found.
GOTO EOF

:NODIAGAVAIL
ECHO Getting source information for %GAME% using %MAMEEXE%
%MAMEEXE% %LISTSOURCE% %GAME%

:EOF
