# SDL
An intro to Simple Directmedia Layer for C++ Game Development

The purpose of this was to design a simple game engine using C++ & SDL2 to build simple 2D games on top of

To install and use SDL on  your local machine:

1. Enter terminal and type `sudo apt-get install libsdl2-dev`
2. In compilation use the flags `-w lSDL2`

`-w`              supresses all warnings

`-lSDL2`          specifies libraries we're linking against, i.e. SDL2

All Projects/lessons compile using `make`

## Makefile commands

`make` / `make all`    Compiles all source files into object code and then links to executable

`make run`             Runs executable file

`make clean`           Removes `.o` files

`make fclean`          Removes executable file

`make re`              Runs `fclean` then `all` 
