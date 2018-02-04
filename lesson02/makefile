NAME = hello_SDL
FILENAMES = hello_SDL.cpp init.cpp loadmedia.cpp close_SDL.cpp
HEADERS = ft.h
CFLAGS = -Wall -Wextra -Werror

INLCUDES = /usr/include/SDL2 $(addprefix includes/, $(HEADERS))
SOURCES = $(addprefix srcs/, $(FILENAMES))
OBJECTS = $(addprefix build/, $(FILENAMES:.cpp=.o))

all:
	g++ $(CFLAGS) $(SOURCES) -I $(INCLUDES)-w -lSDL -o $(NAME)
clean:
	rm -f $(OBJECTS)
fclean: clean
	rm -f $(NAME)
re: fclean all
