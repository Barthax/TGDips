@echo off
if "%1" == "" goto GetGameName
set GameName=%1
SHIFT
goto CheckInpName

:RepeatGetGameName
echo If you wish to exit this loop, use CTRL+C keyboard combination or just close this window.
echo If you wish to record, please type in the short name of the game on the next line.
:GetGameName
SET GameName=
set /p GameName="Enter game name to record:  "
echo Game selected: `%GameName%`
IF "%GameName%" == "" GOTO RepeatGetGameName

:CheckInpName
if "%1" == "" goto GetInpName
set InpName=%1
SHIFT
goto DoRecording

:RepeatGetInpName
echo If you wish to exit this loop, use CTRL+C keyboard combination or just close this window.
echo Please type in the name of the inp file you wish MAME to create.
:GetInpName
SET InpName=
set /p InpName="Enter inp name: "
IF "%InpName%" == "" GOTO RepeatGetInpName


:DoRecording
if exist cfg\%GameName%.cfg move cfg\%GameName%.cfg cfg\%GameName%.bak
if exist hi\%GameName%.hi move hi\%GameName%.hi hi\%GameName%.bak
if exist nvram\%GameName%.nv move nvram\%GameName%.nv nvram\%GameName%.bak
if exist diff\%GameName%.dif move diff\%GameName%.dif diff\%GameName%.bak

mame %GameName% -record %InpName%.inp %1 %2 %3 %4 %5 %6 %7 %8 %9 -nvram_directory NUL

if exist cfg\%GameName%.bak move cfg\%GameName%.bak cfg\%GameName%.cfg
if exist hi\%GameName%.bak move hi\%GameName%.bak hi\%GameName%.hi
if exist nvram\%GameName%.bak move nvram\%GameName%.bak nvram\%GameName%.nv
if exist diff\%GameName%.bak move diff\%GameName%.bak diff\%GameName%.dif
