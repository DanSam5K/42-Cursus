/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:21:03 by dsamuel           #+#    #+#             */
/*   Updated: 2025/04/23 16:26:13 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX02_BASE_HPP
#define EX02_BASE_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>

// Abstract base class intended for polymorphic behavior
class Base 
{
    public:
        virtual ~Base();
};

// Factory function that creates an instance of A, B, or C at random.
// Returns the object as a pointer to Base.
Base *generate();

// Identifies the actual derived type of a Base pointer.
// Outputs "A", "B", or "C" based on dynamic type.
void identify(Base *ptr);

// Identifies the actual derived type using a Base reference.
// Outputs "A", "B", or "C".
void identify(Base &ref);

#endif // EX02_BASE_HPP