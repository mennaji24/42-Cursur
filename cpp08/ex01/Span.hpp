#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <stdexcept> // For std::runtime_error
#include <algorithm> // For std::sort, std::min_element, std::max_element
#include <iterator>  // For std::distance

class Span {
public:
    // Constructor
    Span(unsigned int N);
    
    // Destructor
    ~Span();

    // Add a single number
    void addNumber(int number);

    // Add a range of numbers using iterators
    template <typename InputIterator>
    void addNumbers(InputIterator begin, InputIterator end);

    // Find the shortest span
    int shortestSpan() const;

    // Find the longest span
    int longestSpan() const;

private:
    std::vector<int> _numbers; // Container to store numbers
    unsigned int _maxSize;     // Maximum size (N)
};

#endif
