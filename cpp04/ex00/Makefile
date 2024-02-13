CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
TARGET = ex00
SRC = *.cpp

all: $(TARGET)

$(TARGET):
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

fclean:
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean re