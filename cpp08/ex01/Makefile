# Variables
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++98

# Targets
all: span_test

span_test: main.o Span.o
	$(CXX) $(CXXFLAGS) -o span_test main.o Span.o

main.o: main.cpp Span.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

Span.o: Span.cpp Span.hpp
	$(CXX) $(CXXFLAGS) -c Span.cpp

clean:
	rm -f *.o span_test

re: clean all
