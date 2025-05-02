/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 13:26:41 by dsamuel           #+#    #+#             */
/*   Updated: 2025/04/29 18:50:10 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <algorithm>
#include <exception>

class RPN {
private:
    std::string _expression;
    std::stack<float> _stack;

    RPN();

public:
    explicit RPN(char *input);
    RPN(const RPN& other);
    RPN& operator=(const RPN& other);

    ~RPN();

    class DivisionByZeroException : public std::exception 
    {
        public:
            virtual const char* what() const throw();
    };

    class InsufficientNumbersException : public std::exception 
    {
        public:
            virtual const char* what() const throw();
    };

    class InsufficientOperatorsException : public std::exception 
    {
        public:
            virtual const char* what() const throw();
    };
};

#endif
