/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 14:22:50 by dsamuel           #+#    #+#             */
/*   Updated: 2025/01/03 14:27:42 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
private:
    int _value;
    static const int _fractionalBits = 8;
    
public:
    Fixed();
    Fixed(const int value);
    Fixed(const float floatVal);
    Fixed(const Fixed &copy);
    ~Fixed();
    
    Fixed &operator=(const Fixed &copy);
    
    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat(void) const;
    int toInt(void) const;
    
};

std::ostream &operator<<(std::ostream &out, const Fixed &value);

#endif