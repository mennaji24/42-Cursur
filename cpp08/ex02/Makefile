# Variables
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++98

# Targets
all: mutantstack_test

mutantstack_test: main.o
	$(CXX) $(CXXFLAGS) -o mutantstack_test main.o

main.o: main.cpp MutantStack.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

clean:
	rm -f *.o mutantstack_test

re: clean all
