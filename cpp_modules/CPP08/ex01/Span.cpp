/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 17:46:07 by dsamuel           #+#    #+#             */
/*   Updated: 2025/04/26 18:05:03 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int n) : _maximumCapacity(n)
{
    std::cout << "Span created with max size " << _maximumCapacity << std::endl;
}


Span::Span() : _maximumCapacity(0) {
    std::cout << "Default constructor (private) invoked." << std::endl;
}


Span::Span(const Span& other) : _maximumCapacity(other._maximumCapacity), _elements(other._elements)
{
    std::cout << "Copy constructor called." << std::endl;
}


Span& Span::operator=(const Span& other) {
    std::cout << "Assignment operator invoked." << std::endl;
    if (this != &other)
    {
        this->_maximumCapacity = other._maximumCapacity;
        this->_elements = other._elements;
    }
    return *this;
}


Span::~Span()
{
    std::cout << "Span destroyed." << std::endl;
}


void Span::addNumber(int value) 
{
    if (_elements.size() >= _maximumCapacity)
        throw MaxCapacityExceededException();
    _elements.push_back(value);
}


void Span::addRandomNumbers(unsigned int amount)
{
    std::srand(static_cast<unsigned int>(std::time(NULL)));
    while (amount > 0)
    {
        int randomValue = std::rand() - (RAND_MAX / 2);
        addNumber(randomValue);
        std::cout << "Added random number: " << randomValue << std::endl;
        amount--;
    }
}


int Span::shortestSpan() const
{
    if (_elements.size() < 2)
        throw NoSpanPossibleException();

    std::vector<int> temp(_elements);
    std::sort(temp.begin(), temp.end());

    int shortest = std::abs(temp[1] - temp[0]);
    for (std::vector<int>::size_type i = 1; i < temp.size() - 1; ++i)
    {
        int diff = std::abs(temp[i + 1] - temp[i]);
        if (diff < shortest)
            shortest = diff;
    }
    return shortest;
}


int Span::longestSpan() const
{
    if (_elements.size() < 2)
        throw NoSpanPossibleException();

    int minValue = *std::min_element(_elements.begin(), _elements.end());
    int maxValue = *std::max_element(_elements.begin(), _elements.end());
    return std::abs(maxValue - minValue);
}


const char* Span::MaxCapacityExceededException::what() const throw()
{
    return "Error: Cannot add more numbers, span is full.";
}


const char* Span::NoSpanPossibleException::what() const throw()
{
    return "Error: Not enough numbers to find a span.";
}