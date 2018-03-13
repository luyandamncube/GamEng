###################################################################### 
#								     #	
#           ██╗     ███████╗███╗   ███╗ ██████╗ ███╗   ██╗	     #
#  	    ██║     ██╔════╝████╗ ████║██╔═══██╗████╗  ██║	     #
#  	    ██║     █████╗  ██╔████╔██║██║   ██║██╔██╗ ██║	     #
#           ██║     ██╔══╝  ██║╚██╔╝██║██║   ██║██║╚██╗██║	     #
#  	    ███████╗███████╗██║ ╚═╝ ██║╚██████╔╝██║ ╚████║	     #
#  	    ╚══════╝╚══════╝╚═╝     ╚═╝ ╚═════╝ ╚═╝  ╚═══╝	     #
#				MAKEFILE			     #
#	CREATED BY:	lmncube					     #
#	https://github.com/lmncube				     #
#								     #
###################################################################### 

#############################  MACROS  ###############################
#								     #
#	patsubst is a pattern matcher, where % is the wildcard	     #
#	$(patsubst pattern,replacement pattern,text)		     #
#	DEPS sets directory for header file dependancies	     #	
#	LDIR set directory for external libraries		     #
#	ODIR is the .o file temp directory			     #
#								     #
##############################  MACROS  ##############################

NAME = 			texturemanager_SDL
FILENAMES = 		Game.cpp Main.cpp TextureManager.cpp
CC =			g++

CFLAGS = 		-Wall -Werror -Wextra -w
LFLAGS = 		-lSDL2 -lSDL2_image
HFLAGS =		-I$(HDIR)
IFLAGS =		-I/usr/include/SDL2

HDIR =			./includes
ODIR =			obj
SDIR = 			srcs

_DEPS =			Game.h TextureManager.h
DEPS =			$(patsubst %,$(HDIR)/%,$(_DEPS))	        
_OBJ = 			$(FILENAMES:.cpp=.o)  		        
 OBJ = 			$(patsubst %,$(ODIR)/%,$(_OBJ))
SRCS = 			$(patsubst %,$(SDIR)/%,$(FILENAMES))

##############################  TARGETS  ############################## 
#								      # 
#	Using % instead of * allows us to refer to MULTIPLE targets   #
#       -c flag generates object file			      	      #
#       -o $@ puts output in file named LEFT of :		      #
#       $@ is the LEFT of :				      	      #
#       $^ is the RIGHT of :					      #
#       $< is the first item on the dependencies list	      	      #
#								      #
##############################  TARGETS  ##############################

all: $(NAME)

$(ODIR)/%.o: $(SDIR)/%.cpp $(DEPS)
			$(CC) $< $(HFLAGS) $(IFLAGS) $(CFLAGS) $(LFLAGS) -c -o $@  
$(NAME): $(OBJ)
	@echo		Object files generated!
	@echo 		Compiling library...
			$(CC) $^ $(HFLAGS) $(IFLAGS) $(CFLAGS) $(LFLAGS) -o $@ 
	@echo		Done! Type \"make run\" to run executable
run:
	@echo 		Running program excecutable...
			@./texturemanager_SDL
clean:
	@echo 		Cleaning object files...
			@rm -f $(OBJ)
fclean: clean
	@echo 		Cleaning program excecutable...
			@rm -f $(NAME)
	@echo		Done!
re: 	fclean all

.PHONY: all clean fclean re
