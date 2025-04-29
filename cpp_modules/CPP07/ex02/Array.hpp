/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42wolfsburg.de    +#+  +:+       +#+        */

/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 15:09:08 by dsamuel           #+#    #+#             */
/*   Updated: 2025/04/25 18:02:37 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>
#include <iostream>

template <typename T>
class Array
{
    private:
        T* _data;
        unsigned int _length;
        
    public:
        Array();
        Array(unsigned int n);
        Array(const Array &other);
        Array &operator=(const Array& other);
    
        ~Array();
        
        unsigned int size() const;
        T &operator[](unsigned int index);
        
        class OutOfBoundsException : public std::exception 
        {
            public:
            virtual const char* what() const throw();
        };
 };

#include "Array.tpp"

#endif