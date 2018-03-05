# SDL
An intro to Simple Directmedia Layer for C++ Game Development

The purpose of this was to design a simple game engine using C++ & SDL2 to build simple 2D games on top of

To install and use SDL on  your local machine (OSX/Linux):

1. Install SDL:  `sudo apt-get install libsdl2-dev`
2. Install SDL_image:  `sudo apt-get install libsdl2-image-dev`
3. Install SDL_ttf:  `sudo apt-get install libsdl2-ttf-dev`
4. Install SDL_mixer:  `sudo apt-get install libsdl2-mixer-dev`

## Makefile commands

All Projects/lessons compile using `make`

`make` / `make all`    Compiles all source files into object code and then links to executable

`make run`             Runs executable file

`make clean`           Removes `.o` files

`make fclean`          Removes executable file

`make re`              Runs `fclean` then `all` 
