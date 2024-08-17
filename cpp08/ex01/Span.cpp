#include "Span.hpp"

// Constructor
Span::Span(unsigned int N) : _maxSize(N) {}

// Destructor
Span::~Span() {}

// Add a single number to the Span
void Span::addNumber(int number) {
    if (_numbers.size() >= _maxSize) {
        throw std::runtime_error("Cannot add more numbers: Span is full");
    }
    _numbers.push_back(number);
}

// Add a range of numbers to the Span
template <typename InputIterator>
void Span::addNumbers(InputIterator begin, InputIterator end) {
    if (std::distance(begin, end) + _numbers.size() > _maxSize) {
        throw std::runtime_error("Cannot add more numbers: Span will exceed its maximum size");
    }
    _numbers.insert(_numbers.end(), begin, end);
}

// Find the shortest span
int Span::shortestSpan() const {
    if (_numbers.size() < 2) {
        throw std::runtime_error("Cannot find span: Not enough numbers");
    }
    std::vector<int> sortedNumbers = _numbers;
    std::sort(sortedNumbers.begin(), sortedNumbers.end());

    int minSpan = sortedNumbers[1] - sortedNumbers[0];
    for (unsigned int i = 1; i < sortedNumbers.size() - 1; ++i) {
        int span = sortedNumbers[i + 1] - sortedNumbers[i];
        if (span < minSpan) {
            minSpan = span;
        }
    }
    return minSpan;
}

// Find the longest span
int Span::longestSpan() const {
    if (_numbers.size() < 2) {
        throw std::runtime_error("Cannot find span: Not enough numbers");
    }
    int minElement = *std::min_element(_numbers.begin(), _numbers.end());
    int maxElement = *std::max_element(_numbers.begin(), _numbers.end());
    return maxElement - minElement;
}
