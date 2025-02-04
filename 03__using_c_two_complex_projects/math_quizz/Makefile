################################################################################
#                                Quizz Game Makefile                           #
#                                                                              #
# Description:                                                               #
#   This Makefile builds the Quizz Game project by compiling source files      #
#   from the 'src' and 'lib' directories, then links them into an executable.  #
#                                                                              #
# Platforms:                                                                 #
#   - Linux (or any POSIX system)                                              #
#   - Windows (using MinGW or a similar environment)                           #
#                                                                              #
# Usage:                                                                     #
#   To build the project, run:                                                 #
#       make                                                                 #
#                                                                              #
#   To clean the build artifacts, run:                                         #
#       make clean                                                           #
#                                                                              #
#   On Windows, the executable will be named 'quizz_game.exe'; on Linux,       #
#   it will be 'quizz_game'.                                                   #
#                                                                              #
# Enjoy building your project!                                               #
################################################################################

# Detect Operating System
OS := $(shell uname 2>/dev/null || echo Unknown)
ifeq ($(OS),Windows_NT)
    RM         = del /Q /F
    EXEC_EXT   = .exe
    MKDIR_CMD  = if not exist $(OBJ_DIR) mkdir $(OBJ_DIR)
else
    RM         = rm -rf
    EXEC_EXT   =
    MKDIR_CMD  = mkdir -p $(OBJ_DIR)
endif

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iinclude

# Directories
SRC_DIR = src
LIB_DIR = lib
OBJ_DIR = obj

# Executable name
EXEC = quizz_game$(EXEC_EXT)

# Source Files
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
LIB_FILES = $(wildcard $(LIB_DIR)/*.c)

# Object Files (maps source files to object files in the obj directory)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES)) \
            $(patsubst $(LIB_DIR)/%.c, $(OBJ_DIR)/%.o, $(LIB_FILES))

# Default target: Build the executable
all: $(EXEC)
	@echo "---------------------------------------------------------"
	@echo "✅ Build successful! You can now run the Quizz Game:"
	@echo "   ./$(EXEC)"
	@echo "---------------------------------------------------------"

# Link object files to create the executable
$(EXEC): $(OBJ_FILES)
	@echo "🔗 Linking object files..."
	$(CC) $(CFLAGS) -o $@ $^

# Rule for compiling source files from src directory
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@echo "🛠️  Compiling [SRC]: $<"
	$(CC) $(CFLAGS) -c $< -o $@

# Rule for compiling source files from lib directory
$(OBJ_DIR)/%.o: $(LIB_DIR)/%.c | $(OBJ_DIR)
	@echo "🛠️  Compiling [LIB]: $<"
	$(CC) $(CFLAGS) -c $< -o $@

# Create the object directory if it doesn't exist
$(OBJ_DIR):
	@echo "📂 Creating object directory '$(OBJ_DIR)'..."
	$(MKDIR_CMD)

# Clean target: Remove compiled objects and the executable
clean:
	@echo "🧹 Cleaning up build artifacts..."
	$(RM) $(OBJ_DIR) $(EXEC)
	@echo "🧼 Cleanup complete!"

# Declare phony targets (not associated with files)
.PHONY: all clean

