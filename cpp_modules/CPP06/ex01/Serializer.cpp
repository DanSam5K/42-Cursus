/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:01:21 by dsamuel           #+#    #+#             */
/*   Updated: 2025/04/23 16:03:13 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer() {}

Serializer::Serializer(const Serializer &other)
{
    *this = other;
}

Serializer &Serializer::operator=(const Serializer &other) 
{
    if (this != &other) {
        // No actual data members to copy
    }
    return *this;
}

Serializer::~Serializer() {}

uintptr_t Serializer::encode(GameStatus *ptr) 
{
    return reinterpret_cast<uintptr_t>(ptr);
}

GameStatus *Serializer::decode(uintptr_t raw)
{
    return reinterpret_cast<GameStatus *>(raw);
}