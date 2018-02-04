NAME = hello_SDL
SRC = hello_SDL.cpp
HEADER = /usr/include/SDL2
OBJECTS = hello_SDL.o
CFLAGS = -Wall -Wextra -Werror
all: $(OBJS) 
	g++ $(CFLAGS) $(SRC) -I $(HEADER) -w -lSDL2 -o $(NAME)
clean: 
	rm -f $(OBJECTS)
fclean: clean
	rm -f $(NAME)
re: fclean all
