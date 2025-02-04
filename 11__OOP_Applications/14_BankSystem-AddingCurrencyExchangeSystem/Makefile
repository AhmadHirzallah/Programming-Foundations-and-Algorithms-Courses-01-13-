# Compiler and Flags
CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -Wno-deprecated-copy \
            -I./Screens/Currency -I./Screens -I./Screens/Clients \
            -I./Screens/Transactions -I./Screens/Users -I./Core -I./Include

# Output Binary
TARGET := BankSystem

# Source Files
SRC := main.cpp \
       $(wildcard Core/*.cpp) \
       $(wildcard Screens/*.cpp) \
       $(wildcard Screens/Clients/*.cpp) \
       $(wildcard Screens/Currency/*.cpp) \
       $(wildcard Screens/Transactions/*.cpp) \
       $(wildcard Screens/Users/*.cpp)

# Object Files
OBJ := $(SRC:.cpp=.o)

# Detect OS
ifeq ($(OS),Windows_NT)
    RM := del /Q /F
    CLEAR := cls
else
    RM := rm -f
    CLEAR := clear
endif

# Compilation Rule
all: $(TARGET)
	@echo "✅ Compilation successful!"
	@echo "👉 You can run the program using: ./$(TARGET)"

# Linking Rule
$(TARGET): $(OBJ)
	@echo "🔗 Linking..."
	$(CXX) $(OBJ) -o $(TARGET)

# Object File Compilation Rule
%.o: %.cpp
	@echo "🛠️  Compiling $<..."
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean Rule
clean:
	@echo "🧹 Cleaning up..."
	$(RM) $(OBJ) $(TARGET)
	@echo "🧼 Cleanup complete!"

# Reset Rule (Full Rebuild)
re: clean all
	@echo "♻️  Full rebuild complete!"

