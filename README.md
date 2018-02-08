# sdl2-draw-demo

A simple drawing application made with SDL2. Run `Draw.exe` with `SDL2.dll` in the same folder (64-bit Windows). `build.bat` builds the executable for 64-bit Windows, but the project can be built for 32-bit and 64-bit Windows/Linux/macOS with an appropriate compiler and SDL2 distribution.

Use the mouse to draw. The color drifts randomly. The drawing drifts randomly in a dither pattern when you hold the mouse button without moving the mouse.

The window defaults to 512x512 pixels and is resizable. Resizing the window clears the drawing.

![infinity](https://i.imgur.com/9FfAisq.gif)

![wander](https://i.imgur.com/LZj88uu.gif)

![DRAW](https://i.imgur.com/1Nfje0J.png)

## Development

This covers building on Windows 64-bit and 32-bit. On Linux and macOS, use your favorite C/C++ compiler and the appropriate SDL2 distribution.

Download and install [Build Tools for Visual Studio 2017](https://www.visualstudio.com/downloads) to get the `CL` C/C++ compiler and `x64 Native Tools Command Prompt`. Use `x86 Native Tools Command Prompt` for 32-bit Windows. More information on these command prompts  [here](https://docs.microsoft.com/en-us/cpp/build/building-on-the-command-line).

Download the Visual C++ [SDL2 development libraries](https://www.libsdl.org/download-2.0.php) and update the two paths in `build.bat` for where you save it (also switch `x64` to `x86` in the second path for 32-bit). This project uses the current stable version `2.0.7`.

Run `build.bat` in the command prompt from above to build. Run `build.bat dev` to get a console when the program runs.
