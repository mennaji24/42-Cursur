#include "PmergeMe.hpp"

PmergeMe::PmergeMe(char **args, int count) {
    parseInput(args, count);
}

bool PmergeMe::isPositiveInteger(const std::string &str) {
    if (str.empty())
        return false;
    for (size_t i = 0; i < str.size(); ++i) {
        if (!isdigit(str[i]))
            return false;
    }
    std::istringstream iss(str);
    long val;
    iss >> val;
    return val > 0;
}

void PmergeMe::parseInput(char **args, int count) {
    for (int i = 0; i < count; ++i) {
        std::string token(args[i]);
        if (!isPositiveInteger(token))
            throw std::runtime_error("Error");
        int num;
        std::istringstream(token) >> num;
        vectorSequence.push_back(num);
        dequeSequence.push_back(num);
    }
}

void PmergeMe::mergeInsertSort(std::vector<int>& seq) {
    mergeSort(seq, 0, static_cast<int>(seq.size()) - 1);
}

void PmergeMe::mergeInsertSort(std::deque<int>& seq) {
    mergeSort(seq, 0, static_cast<int>(seq.size()) - 1);
}

template <typename T>
void PmergeMe::mergeSort(T &container, int left, int right) {
    if (left >= right)
        return;
    int mid = left + (right - left) / 2;
    mergeSort(container, left, mid);
    mergeSort(container, mid + 1, right);
    merge(container, left, mid, right);
}

template <typename T>
void PmergeMe::merge(T &container, int left, int mid, int right) {
    T leftPart;
    T rightPart;
    for (int i = left; i <= mid; ++i)
        leftPart.push_back(container[i]);
    for (int i = mid + 1; i <= right; ++i)
        rightPart.push_back(container[i]);

    int i = 0, j = 0, k = left;
    while (i < static_cast<int>(leftPart.size()) && j < static_cast<int>(rightPart.size())) {
        if (leftPart[i] <= rightPart[j])
            container[k++] = leftPart[i++];
        else
            container[k++] = rightPart[j++];
    }
    while (i < static_cast<int>(leftPart.size()))
        container[k++] = leftPart[i++];
    while (j < static_cast<int>(rightPart.size()))
        container[k++] = rightPart[j++];
}


void PmergeMe::sortAndDisplay() {
    std::cout << "Before: ";
    for (size_t i = 0; i < vectorSequence.size(); ++i)
        std::cout << vectorSequence[i] << " ";
    std::cout << std::endl;

    // Run once to sort and print final result
    mergeInsertSort(vectorSequence);

    std::cout << "After: ";
    for (size_t i = 0; i < vectorSequence.size(); ++i)
        std::cout << vectorSequence[i] << " ";
    std::cout << std::endl;

    int runs = 1000; // for more precise timing

    // Time std::vector sorting
    clock_t startVec = clock();
    for (int i = 0; i < runs; ++i) {
        std::vector<int> temp = vectorSequence;
        mergeInsertSort(temp);
    }
    clock_t endVec = clock();

    // Time std::deque sorting
    clock_t startDeq = clock();
    for (int i = 0; i < runs; ++i) {
        std::deque<int> temp = dequeSequence;
        mergeInsertSort(temp);
    }
    clock_t endDeq = clock();

    // Calculate average time in seconds (with microsecond precision)
    double vecTime = static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC / runs;
    double deqTime = static_cast<double>(endDeq - startDeq) / CLOCKS_PER_SEC / runs;

    std::cout.setf(std::ios::fixed);
    std::cout.precision(6);

    std::cout << "Time to process a range of " << vectorSequence.size()
              << " elements with std::this->vector : " << vecTime << "s" << std::endl;
    std::cout << "Time to process a range of " << dequeSequence.size()
              << " elements with std::this->deque : " << deqTime << "s" << std::endl;
}
