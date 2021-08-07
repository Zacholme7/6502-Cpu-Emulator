OBJS = ./src/main.cpp # which files to be compiled
CC = g++ # what compiler is being used
COMPILER_FLAGS = -w # addition options for compiler
LINKER_FLAGS = -lSDL2 # libraries that are being linked
OBJ_NAME = main # what the name of the executable is

# ran with make all
all : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
