/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 13:12:30 by dsamuel           #+#    #+#             */
/*   Updated: 2025/04/29 18:51:54 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(char* input) : _expression(input) {
    float a = 0.0f;
    float b = 0.0f;

    for (std::size_t i = 0; i < _expression.length(); ++i) {
        if (std::isdigit(_expression[i])) {
            _stack.push(static_cast<float>(std::strtof(&_expression[i], NULL)));
        }
        else if (_expression.find_first_of("+-/*", i) == i)
        {
            if (_stack.size() < 2)
                throw InsufficientNumbersException();
            b = _stack.top();
            _stack.pop();
            a = _stack.top();
            _stack.pop();

            switch (_expression[i]) {
                case '+':
                    _stack.push(a + b);
                    break;
                case '-':
                    _stack.push(a - b);
                    break;
                case '*':
                    _stack.push(a * b);
                    break;
                case '/':
                    if (b == 0.0f) {
                        throw DivisionByZeroException();
                    }
                    _stack.push(a / b);
                    break;
            }
        }
    }

    if (_stack.size() != 1)
        throw InsufficientOperatorsException();

    std::cout << "Result is: " << _stack.top() << std::endl;
}

RPN::RPN(const RPN& other) : _expression(other._expression), _stack(other._stack) {}

RPN& RPN::operator=(const RPN &other) {
    if (this != &other) {
        _expression = other._expression;
        _stack = other._stack;
    }
    return *this;
}

RPN::~RPN() {}

const char* RPN::DivisionByZeroException::what() const throw()
{
    return "Error: Division by zero is not allowed.";
}

const char* RPN::InsufficientNumbersException::what() const throw()
{
    return "Error: Not enough numbers to perform the operation.";
}

const char* RPN::InsufficientOperatorsException::what() const throw()
{
    return "Error: Not enough operators in the expression.";
}