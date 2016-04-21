@echo off

REM Environment variables
SET MAMELOCATION=C:\MAME
SET INPLOCATION=%MAMELOCATION%\inp
SET DOWNLOCATION=%INPLOCATION%\MARP
SET DONELOCATION=%DOWNLOCATION%\Done
SET SRCLOCATION=E:\projects\MAME\dips

REM Expectations:
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

echo done environment change
pause