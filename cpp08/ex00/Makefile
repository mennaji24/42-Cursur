# Variables
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++98

# Targets
all: easyfind_test

easyfind_test: main.o
	$(CXX) $(CXXFLAGS) -o easyfind_test main.o

main.o: main.cpp easyfind.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

clean:
	rm -f *.o easyfind_test

re: clean all
