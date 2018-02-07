NAME = keypress_SDL
FILENAMES = keypress_SDL.cpp
CFLAGS = -Wall -Werror - Wextra -w -lSDL2 -o

INCLUDES = -I/usr/include/SDL2
SOURCES = $(addprefix srcs/, $(FILENAMES))
OBJECTS = $(addprefix build/, $(FILENAMES:.cpp=.o))

all: 
	g++ $(SOURCES) $(INCLUDES) $(CFLAGS) $(NAME)
clean:
	rm -f $(OBJECTS)
fclean: 
	rm -f $(NAME)
re:	flcean all
