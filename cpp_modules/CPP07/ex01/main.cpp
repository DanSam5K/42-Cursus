/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 14:56:39 by dsamuel           #+#    #+#             */
/*   Updated: 2025/04/24 15:04:01 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

// A simple function to increment numbers
void increment(int &x) {
    x += 1;
}

// A function that prints any type (can work with const or non-const T&)
template <typename T>
void print(const T &element) {
    std::cout << element << " ";
}

int main()
{
    // Test with integers
    int intArr[] = {1, 2, 3, 4, 5};
    std::size_t intSize = sizeof(intArr) / sizeof(intArr[0]);

    std::cout << "Original int array: ";
    iter(intArr, intSize, print<int>);
    std::cout << "\n";

    iter(intArr, intSize, increment);

    std::cout << "After incrementing: ";
    iter(intArr, intSize, print<int>);
    std::cout << "\n\n";

    // Test with strings
    std::string strArr[] = {"alpha", "beta", "gamma"};
    std::size_t strSize = sizeof(strArr) / sizeof(strArr[0]);

    std::cout << "String array: ";
    iter(strArr, strSize, print<std::string>);
    std::cout << "\n\n";

    // Test with const array (read-only case)
    const float floatArr[] = {3.14f, 2.71f, 0.577f};
    std::size_t floatSize = sizeof(floatArr) / sizeof(floatArr[0]);

    std::cout << "Const float array: ";
    iter(floatArr, floatSize, print<float>);
    std::cout << "\n";

    return 0;
}