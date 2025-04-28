/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:27:55 by dsamuel           #+#    #+#             */
/*   Updated: 2025/04/23 16:34:55 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

#include "Base.hpp"

class D : public Base {

};

int main() 
{
  Base *derivedClass = generate();
  identify(derivedClass);
  identify(*derivedClass);

  Base *wrongClass = new D;
  identify(wrongClass);
  identify(*wrongClass);
}

// int main() 
// {
//     // Generate a random derived instance (A, B, or C) and assign it to a Base pointer
//     Base* randomInstance = generate();

//     std::cout << std::endl << "[IDENTIFY USING POINTER]" << std::endl;
//     identify(randomInstance); // Identify using Base pointer

//     std::cout << std::endl << "[IDENTIFY USING REFERENCE]" << std::endl;
//     identify(*randomInstance); // Identify using Base reference

//     // Clean up to avoid memory leak
//     delete randomInstance;

//     return 0;
// }