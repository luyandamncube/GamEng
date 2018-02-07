NAME = event_SDL
FILENAMES = event_SDL.cpp
CFLAGS = -Wall -Wextra -Werror -w -lSDL2 -o

INCLUDES = -I/usr/include/SDL2
SOURCES = $(addprefix srcs/, $(FILENAMES))
OBJECTS = $(addprefix build/, $(FILENAMES:.cpp=.o))

all:
	g++ $(SOURCES) $(INCLUDES) $(CFLAGS) $(NAME)
run: all
	./event_SDL
clean:
	rm -f $(OBJECTS)
fclean: clean 
	rm -f $(NAME)
re: fclean all
