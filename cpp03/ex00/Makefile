CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
TARGET = ClapTrap
SRC = main.cpp ClapTrap.cpp

all: $(TARGET)

$(TARGET):
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)

re: clean all

.PHONY: all clean re
