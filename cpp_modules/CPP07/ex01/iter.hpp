/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 14:47:48 by dsamuel           #+#    #+#             */
/*   Updated: 2025/04/25 15:08:42 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>
#include <iostream>
#include <string>
#include <functional>

template <typename T, typename F>
void iter(T *array, std::size_t length, void (*func)(F)) {
    for (std::size_t index = 0; index < length; ++index) {
        func(array[index]);
    }
}

#endif