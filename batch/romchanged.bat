@ECHO OFF
SET USEMAMEEXES=true
SET USEPROGETTOSNAP=true
SET USEPROGETTOEMMA=true
SET USELISTFULL=false
SET USEXML=true
SET USENOTEPAD=true

SET FIRSTMAME=106
SET LASTMAME=200
SET LOG=ROMCHANGED-%1.TXT

REM ProgettoSNAPs' RenameSet
REM http://www.progettosnaps.net/renameset/
REM only the two files required: allMAMErenamed.txt and allMAMEremoved.txt
SET PS_RENAMEALLMAME=allMAMErenamed.txt
SET PS_REMOVEALLMAME=allMAMEremoved.txt

REM Addition URL option - assumes %1 can be appended
SET ADDITURL=http://www.progettoemma.net/index.php?gioco=

REM Gnu's Grep installed
REM http://gnuwin32.sourceforge.net/packages/grep.htm
SET GNU=C:\Program Files\GnuWin32\bin

REM XML changes
REM 0.106 outputs the resolution in video tag
REM 0.107+ output the resolution in display tag
SET VIDEOISDISPLAY=107
SET VIDEOORDISPLAY=video
REM 0.106-0.161 output the information as game tag
REM 0.162+ output the information as machine tag
SET GAMEISMACHINE=162
SET GAMEORMACHINE=game

SET MAMEPREFIX=MAME
SET TASK=
SET TEMPFILE1=%1tempfile1.txt

REM XMLStarlet from sourceforge
REM http://sourceforge.net/projects/xmlstar/files/xmlstarlet/1.6.1/
SET XML=xml.exe

IF NOT "%USEPROGETTOEMMA%" == "true" GOTO NOEMMA
REM Fire up the additional URL
start %ADDITURL%%1

:NOEMMA

IF NOT "%USEPROGETTOSNAP%" == "true" GOTO NOSNAP
ECHO Checking %PS_RENAMEALLMAME% for %1>%LOG%
"%GNU%\grep.exe" %1 %PS_RENAMEALLMAME% >>%LOG%
"%GNU%\grep.exe" %1 %PS_RENAMEALLMAME%
ECHO Checking %PS_REMOVEALLMAME% for removed %1>>%LOG%
"%GNU%\grep.exe" %1 %PS_REMOVEALLMAME% >>%LOG%
"%GNU%\grep.exe" %1 %PS_REMOVEALLMAME%

:NOSNAP

ECHO Checking versions for %1>>%LOG%

IF NOT "%USEMAMEEXES%" == "true" GOTO NOEXES
GOTO NEXTTASK

:PREPFIRSTMAME
SET CURRENT=%FIRSTMAME%
IF "%2" == "" GOTO CHECKMAME
SET CURRENT=%2

:CHECKMAME
REM Check for early WolfMAMEs with mameplib.dll requirement
REM Assumes the relevant mameplib.dll will exist as mamep<ver>lib.dll like the newer ones.
REM - not required: IF %MVER% GTR 82 GOTO PLIBDONE
IF EXIST mameplib.dll DEL mameplib.dll
SET MLIB=mamep%CURRENT%lib.dll
IF EXIST %MLIB% COPY %MLIB% mameplib.dll

IF EXIST %MAMEPREFIX%%CURRENT%.exe GOTO PROCESSVERSION

ECHO MAME Version missing: %CURRENT%
GOTO NEXTVERSION

:PROCESSVERSION
REM Work out if need to dig for game tag or machine tag
SET GAMEORMACHINE=game
IF %CURRENT% GEQ %GAMEISMACHINE% SET GAMEORMACHINE=machine
REM Work out if need to dig for video tag or display tag
SET VIDEOORDISPLAY=video
IF %CURRENT% GEQ %VIDEOISDISPLAY% SET VIDEOORDISPLAY=display

ECHO MAME Version %CURRENT%
GOTO %TASK%

:VERSIONREENTRY

:NEXTVERSION
SET /a CURRENT=%CURRENT%+1
IF %CURRENT% GTR %LASTMAME% GOTO NEXTTASK
GOTO CHECKMAME


REM the -listfull functionality
:LISTFULL
ECHO MAME Version %CURRENT%>>%LOG%
%MAMEPREFIX%%CURRENT%.exe -listfull %1 >>%LOG%
%MAMEPREFIX%%CURRENT%.exe -listclones %1 >>%LOG%
ECHO.>>%LOG%
GOTO VERSIONREENTRY

REM the extraction of the description from the XML
:ROMSETNAME
ECHO ROM Set name for %CURRENT%
SET GAMEDESCRIPTION=
%MAMEPREFIX%%CURRENT%.exe -listxml %1 | %XML% sel -t -c "mame/%GAMEORMACHINE%[@name='%1']" | %XML% sel -t -v "%GAMEORMACHINE%/description" >%TEMPFILE1%
SET /P GAMEDESCRIPTION=<%TEMPFILE1%
DEL %TEMPFILE1%
ECHO 0.%CURRENT%: %1 - "%GAMEDESCRIPTION%">>%LOG%
GOTO VERSIONREENTRY

REM the extraction of the resolution from the XML
:ROMSETRES
SET GAMEDESCRIPTION=
%MAMEPREFIX%%CURRENT%.exe -listxml %1 | %XML% sel -t -c "mame/%GAMEORMACHINE%[@name='%1']" | %XML% sel -t -m "%GAMEORMACHINE%/%VIDEOORDISPLAY%" -v "concat(@width,'x',@height,' @ ',@refresh,'Hz')" >%TEMPFILE1%
SET /P GAMEDESCRIPTION=<%TEMPFILE1%
DEL %TEMPFILE1%
ECHO 0.%CURRENT%: %GAMEDESCRIPTION%>>%LOG%
GOTO VERSIONREENTRY

:NEXTTASK
echo "Finished task %TASK%"
IF "%TASK%"=="" GOTO NEXTTASKLISTFULL
IF "%TASK%"=="LISTFULL" GOTO NEXTTASKROMSETNAME
IF "%TASK%"=="ROMSETNAME" GOTO NEXTTASKROMSETRES
GOTO EOF

:NEXTTASKLISTFULL
SET TASK=LISTFULL
IF NOT %USELISTFULL%==true GOTO NEXTTASK
GOTO PREPFIRSTNAME

:NEXTTASKROMSETNAME
SET TASK=ROMSETNAME
IF NOT %USEXML%==true GOTO NEXTTASK
GOTO PREPFIRSTMAME

:NEXTTASKROMSETRES
SET TASK=ROMSETRES
IF NOT %USEXML%==true GOTO NEXTTASK
GOTO PREPFIRSTMAME



:NOEXES

:EOF
IF "%USENOTEPAD%"=="true" START NOTEPAD %LOG%
