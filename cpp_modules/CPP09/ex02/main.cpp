/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 13:52:29 by dsamuel           #+#    #+#             */
/*   Updated: 2025/04/30 14:17:53 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"


int main(int argc, char** argv) 
{
    if (argc < 2)
    {
        std::cerr << "Usage: " << argv[0] << " <positive integers>" << std::endl;
        return 1;
    }
    std::vector<int> numbers;
    for (int i = 1; i < argc; ++i)
    {
        std::string token(argv[i]);
        // Check if the string contains only digits
        
        if (token.find_first_not_of("0123456789") != std::string::npos)
        {
            std::cerr << "Invalid input: " << token << std::endl;
            return 1;
        }
        // Convert to long to safely check bounds
        char* end;
        long value = std::strtol(token.c_str(), &end, 10);
        if (*end != '\0') 
        {
            std::cerr << "Invalid numeric format: " << token << std::endl;
            return 1;
        }

        if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
        {
            std::cerr << "Value out of range: " << token << std::endl;
            return 1;
        }
        
        numbers.push_back(static_cast<int>(value));
    }
    try
    {
        PmergeMe sorter(numbers);
        sorter.sort();
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
