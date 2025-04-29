/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 15:14:35 by dsamuel           #+#    #+#             */
/*   Updated: 2025/04/25 18:07:32 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>

int main() 
{
    // Test default constructor
    Array<int> emptyArray;
    std::cout << "Empty array size: " << emptyArray.size() << std::endl;

    // Test constructor with size
    Array<int> numbers(5);
    std::cout << "Initialized array of 5 ints: ";
    for (unsigned int i = 0; i < numbers.size(); ++i) {
        numbers[i] = i * 10;
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;

    // Test copy constructor
    Array<int> copyArray(numbers);
    std::cout << "Copied array contents: ";
    for (unsigned int i = 0; i < copyArray.size(); ++i) {
        std::cout << copyArray[i] << " ";
    }
    std::cout << std::endl;

    // Modify original and show copy is unaffected
    numbers[0] = 999;
    std::cout << "Modified original, numbers[0] = " << numbers[0]
              << ", copyArray[0] = " << copyArray[0] << std::endl;

    // Test assignment operator
    Array<int> assignedArray;
    assignedArray = numbers;
    std::cout << "Assigned array contents: ";
    for (unsigned int i = 0; i < assignedArray.size(); ++i) {
        std::cout << assignedArray[i] << " ";
    }
    std::cout << std::endl;

    // Test bounds check
    try {
        std::cout << "Trying to access out-of-bounds element: ";
        std::cout << numbers[100] << std::endl; // Should throw
    } catch (const std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}