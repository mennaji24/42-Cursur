CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
TARGET = ScavTrap
SRC = main.cpp ClapTrap.cpp ScavTrap.cpp

all: $(TARGET)

$(TARGET):
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)

re: clean all

.PHONY: all clean re
