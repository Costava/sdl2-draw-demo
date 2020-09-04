# sdl2-draw-demo

A simple drawing application made with SDL2.

Use the mouse to draw.
The color drifts randomly.
The drawing drifts in random directions in a pattern
when you hold the mouse button without moving the mouse.

The window defaults to 512x512 pixels and is resizable.
Resizing the window clears the drawing.

Feel free to ask a question by opening an issue.

![infinity](https://i.imgur.com/9FfAisq.gif)

![wander](https://i.imgur.com/LZj88uu.gif)

![DRAW](https://i.imgur.com/1Nfje0J.png)

## License

GNU GPL v3.
See file `LICENSE`.

## How to build and run

### Linux

Tested with SDL v2.0.12

1. Clone repo
2. `make run`

### Windows

Tested with SDL v2.0.9

- Download and install [Build Tools for Visual Studio 2017](https://www.visualstudio.com/downloads) to get the `CL` C/C++ compiler and `x64 Native Tools Command Prompt`. Use `x86 Native Tools Command Prompt` for 32-bit Windows. More information on these command prompts  [here](https://docs.microsoft.com/en-us/cpp/build/building-on-the-command-line).
- Download the Visual C++ [SDL2 development libraries](https://www.libsdl.org/download-2.0.php).
- Create a symbolic link named `SDL2-2.0.9` targeting the location of the downloaded `SDL2-2.0.9` folder. Likely use `mklink /D SDL2-2.0.9 C:\path\to\SDL2-2.0.9`. The `/D` argument is for directory symbolic link as opposed to the default file symbolic link.
- Switch `x64` to `x86` for `libpathsdl` in `build.bat` for 32-bit.
- Run `build.bat` in the command prompt from above to build. Run `build.bat dev` to get a console when the program runs.

## Contributing

Not currently accepting contributions.
Feel free to create an issue.
