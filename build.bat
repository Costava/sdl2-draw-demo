@ECHO OFF
SETLOCAL

:: Download the Visual C++ development libraries from
:: https://www.libsdl.org/download-2.0.php
:: And create symbolic link SDL2-2.0.8 (in the same directory as this file)
::  to the location of the downloaded SDL2-2.0.8 directory
SET includesdl=SDL2-2.0.8\include
SET libpathsdl=SDL2-2.0.8\lib\x64

SET subsystem=WINDOWS

IF "%1"=="dev" (
	SET subsystem=CONSOLE
)

CL /FeDraw main.c /EHsc /MD /I %includesdl% /link /LIBPATH:%libpathsdl% SDL2.lib SDL2main.lib /SUBSYSTEM:%subsystem%
