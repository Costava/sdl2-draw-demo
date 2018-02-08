@ECHO OFF
SETLOCAL

:: Download the Visual C++ development libraries from https://www.libsdl.org/download-2.0.php
:: And set these paths for where you save it
SET includesdl=D:\SDL2-2.0.7\include
SET libpathsdl=D:\SDL2-2.0.7\lib\x64

SET subsystem=WINDOWS

IF "%1"=="dev" (
	SET subsystem=CONSOLE
)

CL /FeDraw main.cpp /EHsc /MD /I %includesdl% /link /LIBPATH:%libpathsdl% SDL2.lib SDL2main.lib /SUBSYSTEM:%subsystem%
