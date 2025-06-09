#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <sstream>
#include <ctime>
#include <algorithm>

class PmergeMe {
public:
    PmergeMe(char **args, int count);
    void sortAndDisplay();

private:
    std::vector<int> vectorSequence;
    std::deque<int> dequeSequence;

    bool isPositiveInteger(const std::string &str);
    void parseInput(char **args, int count);

    void mergeInsertSort(std::vector<int>& seq);
    void mergeInsertSort(std::deque<int>& seq);

    template <typename T>
    void mergeSort(T &container, int left, int right);

    template <typename T>
    void merge(T &container, int left, int mid, int right);
};

#endif
