/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 17:47:02 by dsamuel           #+#    #+#             */
/*   Updated: 2025/04/26 18:06:18 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <exception>
#include <iostream>
#include <vector>

class Span
{
    private:
        unsigned int _maximumCapacity;
        std::vector<int> _elements;

        Span();

    public:
    
        explicit Span(unsigned int n);
        Span(const Span& other);
        Span& operator=(const Span& other);
        
        ~Span();

        void addNumber(int value);
        void addRandomNumbers(unsigned int amount);

        int shortestSpan() const;
        int longestSpan() const;

        class MaxCapacityExceededException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

        class NoSpanPossibleException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

#endif