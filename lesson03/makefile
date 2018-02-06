NAME = event_SDL
FILENAMES = event_SDL.cpp
CFLAGS = -Wall -Wextra -Werror

INCLUDES = -I/usr/include/SDL2
SOURCES = $(addprefix srcs/, $(FILENAMES))
OBJECTS = $(addprefix build/, $(FILENAMES:.cpp=.o))

all:
	g++ $(CFLAGS) $(SOURCES) $(INCLUDES) -w -lSDL2 -o $(NAME)
clean:
	rm -f $(OBJECTS)
fclean: clean 
	rm -f $(NAME)
re: fclean all
