# Define the compiler and the flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iinclude

# Define the source directories
SRC_DIR = src
LIB_DIR = lib

# Define the object directory
OBJ_DIR = obj

# Define the executable name
EXEC = quizz_game

# Define the source files
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
LIB_FILES = $(wildcard $(LIB_DIR)/*.c)

# Define the object files
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES)) \
            $(patsubst $(LIB_DIR)/%.c, $(OBJ_DIR)/%.o, $(LIB_FILES))

# Default target
all: $(EXEC)

# Link the object files to create the executable
$(EXEC): $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $@ $^

# Compile the source files into object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(LIB_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean the build directory
clean:
	rm -rf $(OBJ_DIR) $(EXEC)

# Phony targets
.PHONY: all clean

