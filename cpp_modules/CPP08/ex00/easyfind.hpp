/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 17:15:26 by dsamuel           #+#    #+#             */
/*   Updated: 2025/04/26 17:19:10 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <exception>
#include <iostream>
#include <vector>

template <typename T>
void easyfind(T container, int valueToBeFound);

class ValueNotFoundException : public std::exception
{
    public:
        virtual const char *what() const throw();
};

#include "easyfind.tpp"
#endif