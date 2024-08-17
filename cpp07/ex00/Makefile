# Makefile

# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Target executable
TARGET = main

# Source files
SRC = main.cpp

# Object files
OBJ = $(SRC:.cpp=.o)

# Default rule
all: $(TARGET)

# Rule to build the target
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

# Rule to clean up the object files and executable
clean:
	rm -f $(OBJ) $(TARGET)

# Rule to recompile everything
re: clean all
