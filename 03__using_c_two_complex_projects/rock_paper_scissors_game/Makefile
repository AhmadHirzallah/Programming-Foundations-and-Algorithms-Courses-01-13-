################################################################################
#                          Rock-Paper-Scissors Game Makefile                   #
#                                                                              #
# Description:                                                               #
#   This Makefile builds the Rock-Paper-Scissors game by compiling source      #
#   files from the 'src' and 'lib' directories, then linking them into an        #
#   executable.                                                              #
#                                                                              #
# Platforms:                                                                 #
#   - Linux                                                                  #
#   - Windows (using MinGW or a similar environment)                         #
#                                                                              #
# Usage:                                                                     #
#   To build the project, run:                                                 #
#       make                                                                 #
#                                                                              #
#   To clean up the compiled objects and the executable, run:                #
#       make clean                                                           #
#                                                                              #
#   To rebuild from scratch, run:                                              #
#       make re                                                              #
#                                                                              #
# Enjoy your game!                                                           #
################################################################################

# Detect Operating System for cross-platform support
OS := $(shell uname 2>/dev/null || echo Unknown)
ifeq ($(OS),Windows_NT)
    RM = del /Q /F
    EXEC_EXT = .exe
else
    RM = rm -f
    EXEC_EXT =
endif

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iinclude

# Source files (order can be adjusted if needed)
SRCS = lib/game.c lib/round.c lib/utils.c src/main.c

# Derive object files from source files by replacing .c with .o
OBJS = $(SRCS:.c=.o)

# Executable name (append .exe on Windows)
EXEC = game$(EXEC_EXT)

# Default target: Build the executable
all: $(EXEC)
	@echo "------------------------------------------------------"
	@echo "✅ Build successful! Run the game with: ./$(EXEC)"
	@echo "------------------------------------------------------"

# Link object files to create the executable
$(EXEC): $(OBJS)
	@echo "🔗 Linking object files..."
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJS)

# Rule: Compile any .c file to its corresponding .o file
%.o: %.c
	@echo "🛠️  Compiling: $<"
	$(CC) $(CFLAGS) -c $< -o $@

# Clean target: Remove object files and the executable
clean:
	@echo "🧹 Cleaning up build artifacts..."
	$(RM) $(OBJS) $(EXEC)
	@echo "🧼 Cleanup complete!"

# fclean target: Alias to clean (can be expanded if needed)
fclean: clean

# re target: Rebuild the project from scratch
re: fclean all

# Declare phony targets to avoid conflicts with files of the same name
.PHONY: all clean fclean re

