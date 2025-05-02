/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 13:44:12 by dsamuel           #+#    #+#             */
/*   Updated: 2025/04/30 14:51:00 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(std::vector<int> containerList)
  : _vectorContainer(containerList), _dequeContainer(containerList.begin(), containerList.end()) {
  for (std::vector<int>::iterator it = _vectorContainer.begin(); it != _vectorContainer.end(); ++it) {
    std::vector<int>::iterator it_temp = it;
    while (it_temp != _vectorContainer.end()) {
      ++it_temp;
      if (it_temp != _vectorContainer.end() && *it_temp == *it) {
        std::cout << "Error: Duplicated number detected: " << *it << std::endl;
        throw DuplicatedNumbersException();
      }
    }
  }
}

PmergeMe::PmergeMe(const PmergeMe &other)
  : _vectorContainer(other._vectorContainer), _dequeContainer(other._dequeContainer) 
{
  
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
  if (this != &other) {
    _vectorContainer = other._vectorContainer;  
    _dequeContainer = other._dequeContainer;
  }
  return *this;
}

PmergeMe::~PmergeMe() {}




template <typename Container>
void PmergeMe::insertionSort(Container &container) {
    for (size_t i = 1; i < container.size(); ++i) {
        typename Container::value_type key = container[i];
        size_t j = i;
        while (j > 0 && container[j - 1] > key) {
            container[j] = container[j - 1];
            --j;
        }
        container[j] = key;
    }
}

template <typename Container>
void PmergeMe::fordJohnsonSort(Container &container) {
    // Use insertion sort for small subarrays
    if (container.size() <= 10) {
        insertionSort(container);
        return;
    }

    // Step 1: Pair elements and sort each pair
    Container pairs;
    for (size_t i = 0; i + 1 < container.size(); i += 2) {
        if (container[i] > container[i + 1]) {
            pairs.push_back(container[i + 1]);
            pairs.push_back(container[i]);
        } else {
            pairs.push_back(container[i]);
            pairs.push_back(container[i + 1]);
        }
    }

    // If odd number of elements, add the last element
    if (container.size() % 2 != 0) {
        pairs.push_back(container.back());
    }

    // Step 2: Recursively sort the first elements of each pair
    Container firstElements;
    for (size_t i = 0; i < pairs.size(); i += 2) {
        firstElements.push_back(pairs[i]);
    }
    fordJohnsonSort(firstElements);

    // Step 3: Merge the sorted first elements with the second elements
    Container sortedContainer;
    size_t firstIndex = 0, secondIndex = 1;

    // Merge the sorted first elements and the second elements of the pairs
    while (firstIndex < firstElements.size() && secondIndex < pairs.size()) {
        if (firstElements[firstIndex] <= pairs[secondIndex]) {
            sortedContainer.push_back(firstElements[firstIndex++]);
        } else {
            sortedContainer.push_back(pairs[secondIndex]);
            secondIndex += 2; // Move to the next second element
        }
    }

    // Add remaining elements from the first elements
    while (firstIndex < firstElements.size()) {
        sortedContainer.push_back(firstElements[firstIndex++]);
    }

    // Add remaining second elements from the pairs
    while (secondIndex < pairs.size()) {
        sortedContainer.push_back(pairs[secondIndex]);
        secondIndex += 2;
    }

    // Copy back the sorted elements
    container = sortedContainer;
}



void PmergeMe::sort() {
  // Display the unsorted sequence
  std::cout << "Before: ";
  for (std::vector<int>::iterator it = _vectorContainer.begin(); it != _vectorContainer.end(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;

  clock_t tStart = clock();

  // Sort the vector container using Ford-Johnson algorithm
  fordJohnsonSort(_vectorContainer);
  double vectorTime = static_cast<double>(clock() - tStart) / CLOCKS_PER_SEC;

  tStart = clock();

  // Sort the deque container using Ford-Johnson algorithm
  fordJohnsonSort(_dequeContainer);
  double dequeTime = static_cast<double>(clock() - tStart) / CLOCKS_PER_SEC;

  // Display the sorted sequence
  std::cout << "After: ";
  for (std::vector<int>::iterator it = _vectorContainer.begin(); it != _vectorContainer.end(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;

  // Display the time taken for each container
  std::cout << "Time to process a range of " << _vectorContainer.size()
            << " elements with std::[vector] : " << vectorTime * 1e6 << " us" << std::endl;

  std::cout << "Time to process a range of " << _dequeContainer.size()
            << " elements with std::[deque] : " << dequeTime * 1e6 << " us" << std::endl;
}

template <typename Container>
bool PmergeMe::confirmIsSorted(Container &container) {
  typename Container::iterator it = container.begin();
  int prev = *it;

  for (++it; it != container.end(); ++it) {
    if (*it < prev) {
      return false;
    }
    prev = *it;
  }
  return true;
}


const char *PmergeMe::DuplicatedNumbersException::what() const throw() 
{
  return "Error: Duplicated number detected";
}
