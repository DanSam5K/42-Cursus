/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:24:51 by dsamuel           #+#    #+#             */
/*   Updated: 2025/04/23 16:31:51 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

// Virtual destructor definition
Base::~Base() {}

// Generates an instance of one of the derived classes (A, B, or C)
Base* generate() 
{
    std::srand(std::time(NULL)); // Seed the random generator

    int randValue = std::rand() % 3;

    switch (randValue)
    {
        case 0:
            std::cout << "Generated class: A" << std::endl;
            return new A();
        case 1:
            std::cout << "Generated class: B" << std::endl;
            return new B();
        case 2:
            std::cout << "Generated class: C" << std::endl;
            return new C();
        default:
            std::cerr << "Unexpected error occurred during generation." << std::endl;
            std::exit(1);
    }
}

// Identifies the dynamic type of the object using a pointer
void identify(Base *ptr) 
{
    if (dynamic_cast<A*>(ptr))
        std::cout << "Identified type: A" << std::endl;
    else if (dynamic_cast<B*>(ptr))
        std::cout << "Identified type: B" << std::endl;
    else if (dynamic_cast<C*>(ptr))
        std::cout << "Identified type: C" << std::endl;
    else
        std::cout << "Type could not be identified from pointer." << std::endl;
}

// Identifies the dynamic type of the object using a reference
void identify(Base &ref) 
{
    try
    {
        (void)dynamic_cast<A&>(ref);
        std::cout << "Identified type by reference: A" << std::endl;
        return;
    } catch (const std::exception&) {}

    try
    {
        (void)dynamic_cast<B&>(ref);
        std::cout << "Identified type by reference: B" << std::endl;
        return;
    } catch (const std::exception&) {}

    try
    {
        (void)dynamic_cast<C&>(ref);
        std::cout << "Identified type by reference: C" << std::endl;
        return;
    } catch (const std::exception&) 
    {
        std::cout << "Type could not be identified from reference." << std::endl;
    }
}
