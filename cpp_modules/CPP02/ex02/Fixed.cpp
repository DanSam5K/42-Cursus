/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:02:39 by dsamuel           #+#    #+#             */
/*   Updated: 2025/01/03 15:02:51 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Constructors
Fixed::Fixed() : _value(0) {}
Fixed::Fixed(const int intVal) : _value(intVal << _fractionalBits) {}
Fixed::Fixed(const float floatVal) : _value(roundf(floatVal * (1 << _fractionalBits))) {}
Fixed::Fixed(const Fixed &other) : _value(other._value) {}

// Destructor
Fixed::~Fixed() {}

// Assignment operator
Fixed &Fixed::operator=(const Fixed &other) {
    if (this != &other) {
        _value = other._value;
    }
    return *this;
}

// Comparison operators
bool Fixed::operator>(const Fixed &other) const { return _value > other._value; }
bool Fixed::operator<(const Fixed &other) const { return _value < other._value; }
bool Fixed::operator>=(const Fixed &other) const { return _value >= other._value; }
bool Fixed::operator<=(const Fixed &other) const { return _value <= other._value; }
bool Fixed::operator==(const Fixed &other) const { return _value == other._value; }
bool Fixed::operator!=(const Fixed &other) const { return _value != other._value; }

// Arithmetic operators
Fixed Fixed::operator+(const Fixed &other) const {
    return Fixed(this->toFloat() + other.toFloat());
}
Fixed Fixed::operator-(const Fixed &other) const {
    return Fixed(this->toFloat() - other.toFloat());
}
Fixed Fixed::operator*(const Fixed &other) const {
    return Fixed(this->toFloat() * other.toFloat());
}
Fixed Fixed::operator/(const Fixed &other) const {
    if (other._value == 0) {
        throw std::runtime_error("Division by zero");
    }
    return Fixed(this->toFloat() / other.toFloat());
}

// Increment/Decrement operators
Fixed &Fixed::operator++() {
    _value++;
    return *this;
}
Fixed Fixed::operator++(int) {
    Fixed temp(*this);
    _value++;
    return temp;
}
Fixed &Fixed::operator--() {
    _value--;
    return *this;
}
Fixed Fixed::operator--(int) {
    Fixed temp(*this);
    _value--;
    return temp;
}

// Static member functions
Fixed &Fixed::min(Fixed &a, Fixed &b) {
    return (a < b) ? a : b;
}
const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
    return (a < b) ? a : b;
}
Fixed &Fixed::max(Fixed &a, Fixed &b) {
    return (a > b) ? a : b;
}
const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
    return (a > b) ? a : b;
}

// Member functions
int Fixed::getRawBits(void) const { return _value; }
void Fixed::setRawBits(int const raw) { _value = raw; }
float Fixed::toFloat(void) const { return static_cast<float>(_value) / (1 << _fractionalBits); }
int Fixed::toInt(void) const { return _value >> _fractionalBits; }

// Overload of insertion (<<) operator
std::ostream &operator<<(std::ostream &os, const Fixed &fixed) {
    os << fixed.toFloat();
    return os;
}