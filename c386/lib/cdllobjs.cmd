@echo off
echo   386 C Runtime Library DLL Build
echo   -------------------------------
setlocal
set OBJSLIB=CDLLOBJS
set SUPPLIB=CDLLSUPP
if %1.==. goto Message
set DESTIN=%1
if not %2.==. set LIBC=%2
if not %2.==. goto Start
for %%A in (%LIB%) do if exist %%A\CRTLIB.OBJ set LIBC=%%A& goto Start
echo Cannot find components in LIB directory
goto Exit
:Start
echo.
echo   Build dynamic link library.
echo.
echo LINK386 %LIBC%\CRTLIB.OBJ,%DESTIN%\CEXAMPLE.DLL/NOI,,%LIBC%\%OBJSLIB% OS2386/NOD/NOE,%LIBC%\CDLLOBJS.DEF;
LINK386 %LIBC%\CRTLIB.OBJ,%DESTIN%\CEXAMPLE.DLL/NOI,,%LIBC%\%OBJSLIB% OS2386/NOD/NOE,%LIBC%\CDLLOBJS.DEF;
echo.
echo   Build imports library.
echo.
for %%A in (%PATH%) do if exist %%A\IMPLIB.EXE goto Skip2
echo Cannot find IMPLIB.EXE in PATH
goto Exit
:Skip2
echo IMPLIB %LIBC%\CEXAMPLE.LIB %LIBC%\CDLLOBJS.DEF
IMPLIB %LIBC%\CEXAMPLE.LIB %LIBC%\CDLLOBJS.DEF
echo.
echo   Add supplemental library to CEXAMPLE.LIB. This library contains
echo   run-time routines that cannot be put in the dynamic link library.
echo.
echo LIB %LIBC%\CEXAMPLE.LIB+%LIBC%\%SUPPLIB%.LIB;
LIB %LIBC%\CEXAMPLE.LIB+%LIBC%\%SUPPLIB%.LIB;
DEL %LIBC%\CEXAMPLE.BAK
goto Exit
:Message
echo   This batch file creates a dynamic link library and a corresponding
echo   imports library containing the C run-time. The imports library (which
echo   is invoked at link time) specifies the symbols and routines that will
echo   be imported from the dynamic link library at run time.  Your PATH should
echo   point to the directory containing IMPLIB.EXE.  Your LIB environment
echo   variable should have a pathname for OS2386.LIB.	The files CDLLOBJS.DEF,
echo   %OBJSLIB%.LIB, and %SUPPLIB%.LIB should be in the same directory as CRTLIB.OBJ.
echo.
echo   The dynamic link library is named CEXAMPLE.DLL and the imports library
echo   is named CEXAMPLE.LIB. To build the libraries with a different name,
echo   edit this file (CDLLOBJS.CMD) and CDLLOBJS.DEF, and replace all
echo   occurrences of CEXAMPLE with the desired name.
echo.
echo   Syntax:
echo	    CDLLOBJS dlldir [libdir]
echo.
echo   Arguments:
echo	    dlldir    Destination directory for DLL (should be in LIBPATH
echo		      in CONFIG.SYS). Use . for the current directory.
echo	    libdir    Destination directory for LIB (Default is LIB
echo		      environment variable).
echo.
echo   Examples:
echo	    CDLLOBJS C:\OS2\DLL
echo		      Puts CEXAMPLE.DLL in C:\OS2\DLL and CEXAMPLE.LIB
echo		      in LIB directory.
echo	    CDLLOBJS . D:\LIBC
echo		      Puts CEXAMPLE.DLL in the current directory and
echo		      CEXAMPLE.LIB in D:\LIBC
:Exit
endlocal
