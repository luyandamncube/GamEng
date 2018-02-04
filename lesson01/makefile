NAME = hello_SDL
FILENAMES = hello_SDL.cpp
CFLAGS = -Wall -Wextra -Werror

INCLUDES = /usr/include/SDL2
SOURCES = $(addprefix srcs/,$(FILENAMES))
OBJECTS = $(addprefix build/,$(FILENAMES:.cpp=.o))

all:
	g++ $(CFLAGS) $(SOURCES) -I $(INCLUDES) -w -lSDL2 -o $(NAME)
clean: 
	rm -f $(OBJECTS)
fclean: clean
	rm -f $(NAME)
re:	fclean all
