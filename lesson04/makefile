NAME = keypress_SDL
FILENAMES = keypress_SDL.cpp
CFLAGS = -Wall -Werror -Wextra -w -lSDL2 -o

INCLUDES = -I/usr/include/SDL2
SOURCES = $(addprefix srcs/, $(FILENAMES))
OBJECTS = $(addprefix build/, $(FILENAMES:.cpp=.o))

all: 
	g++ $(SOURCES) $(INCLUDES) $(CFLAGS) $(NAME)
run:	all
	./keypress_SDL
clean:
	rm -f $(OBJECTS)
fclean: clean 
	rm -f $(NAME)
re:	flcean all
