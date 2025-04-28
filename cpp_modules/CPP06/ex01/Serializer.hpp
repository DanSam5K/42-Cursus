/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:53:40 by dsamuel           #+#    #+#             */
/*   Updated: 2025/04/23 16:06:43 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX01_SERIALIZER_HPP
#define EX01_SERIALIZER_HPP

#include "GameStatus.hpp"
#include <stdint.h>
#include <iostream>

class Serializer 
{
    private:
        Serializer();
        Serializer(const Serializer &other);
        Serializer &operator=(const Serializer &other);
        
        ~Serializer();

    public:
        static uintptr_t encode(GameStatus *ptr);
        static GameStatus *decode(uintptr_t raw);
};

#endif