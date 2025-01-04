/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 20:39:29 by dsamuel           #+#    #+#             */
/*   Updated: 2025/01/02 20:43:38 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {
private:
    int _value;
    static const int _fractionalBits = 8;
    
public:
    Fixed(void);
    Fixed(const Fixed &other);

    Fixed &operator=(const Fixed &other);

    ~Fixed(void);
    
    int getRawBits(void) const;
    void setRawBits(int const raw);

};


#endif