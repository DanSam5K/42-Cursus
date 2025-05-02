/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 11:16:51 by dsamuel           #+#    #+#             */
/*   Updated: 2025/04/23 14:39:22 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() 
{   
}

ScalarConverter::ScalarConverter(const ScalarConverter &source) 
{
    *this = source;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &source) 
{
    if (this != &source)
    {
        std::cout << "Copy assignment operator called" << std::endl;
        // No action needed stateless class
    }
    return *this;
}

ScalarConverter::~ScalarConverter() 
{
    std::cout << "Destructor called" << std::endl;
}

bool ScalarConverter::checkCharacter(const std::string &input_str) 
{
    return input_str.length() == 1 && std::isprint(input_str[0] && !std::isdigit(input_str[0]));
}

bool ScalarConverter::checkInteger(const std::string &input_str) 
{
    size_t start = (input_str[0] == '-') ? 1 : 0;

    if (start == 1 && input_str.length() == 1)
        return false;
    return input_str.find_first_not_of(DIGITS, start) == std::string::npos;
}

bool ScalarConverter::checkFloat(const std::string &input_str) 
{
    if (input_str.empty() || input_str[input_str.length() - 1] != 'f')
        return false;
    size_t start = (input_str[0] == '-') ? 1 : 0;
    size_t dotCount = input_str.find('.', start);
    
    if (dotCount == std::string::npos || dotCount == start || dotCount == input_str.length() - 2)
        return false;

    std::string intPart = input_str.substr(start, dotCount - start);
    std::string fracPart = input_str.substr(dotCount + 1, input_str.length() - dotCount - 2);

    return (intPart.find_first_not_of(DIGITS) == std::string::npos 
            && fracPart.find_first_not_of(DIGITS) == std::string::npos 
            && (intPart.length() > 0 || fracPart.length() > 0));
}

bool ScalarConverter::checkDouble(const std::string &input_str) 
{
    size_t start = (input_str[0] == '-') ? 1 : 0;
    size_t dotCount = input_str.find('.', start);
    
    if (dotCount == std::string::npos || dotCount == start || dotCount == input_str.length() - 1)
        return false;
        
    std::string intPart = input_str.substr(start, dotCount - start);
    std::string fracPart = input_str.substr(dotCount + 1);

    return (intPart.find_first_not_of(DIGITS) == std::string::npos 
            && fracPart.find_first_not_of(DIGITS) == std::string::npos 
            && (intPart.length() > 0 || fracPart.length() > 0));
}


bool ScalarConverter::checkInfinite(const std::string &input_str) 
{
    return (input_str == "inf" || input_str == "-inf" || input_str == "+inf" || input_str == "nanf" ||
            input_str == "inff" || input_str == "-inff" || input_str == "+inff" || input_str == "nan");
}

void ScalarConverter::convertToNumber(const std::string &input_str, long double value)
{
    if (value < std::numeric_limits<char>::min() || value > std::numeric_limits<char>::max())
      std::cout << "char: overflows" << std::endl;
    else
      convertToCharacter(static_cast<char>(value));
  
    if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
      std::cout << "int: overflows" << std::endl;
    else
      std::cout << "int: " << std::atoi(input_str.c_str()) << std::endl;
  
    if (value < -std::numeric_limits<float>::max() || value > std::numeric_limits<float>::max())
      std::cout << "float: overflows" << std::endl;
    else
      std::cout << "float: " << std::strtof(input_str.c_str(), NULL) << "f" << std::endl;
  
    if (value < -std::numeric_limits<double>::max() || value > std::numeric_limits<double>::max())
      std::cout << "double: overflows" << std::endl;
    else
      std::cout << "double: " << strtod(input_str.c_str(), NULL) << std::endl;
}
  

void ScalarConverter::convertFromInfinite(const std::string &input_str)
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
  
    if (input_str.find("nan") != std::string::npos)
    {
      std::cout << "float: nanf" << std::endl;
      std::cout << "double: nan" << std::endl;
    }
    else
    {
      char sign = input_str[0];
      std::cout << "float: " << sign << "inff" << std::endl;
      std::cout << "double: " << sign << "inf" << std::endl;
    }
}

void ScalarConverter::convertFromCharacter(const std::string &input_str)
{
    char c = input_str[0];
    convertToCharacter(c);
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(c) << std::endl;
}

void ScalarConverter::convertToCharacter(const char &c) 
{
    if (std::isprint(c))
        std::cout << "char: '" << c << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
}


void ScalarConverter::convert(const std::string &input_str) 
{
    if (checkCharacter(input_str))
        convertFromCharacter(input_str);
    else if (checkInteger(input_str))
        convertToNumber(input_str, std::strtold(input_str.c_str(), NULL));
    else if (checkFloat(input_str))
        convertToNumber(input_str, std::strtold(input_str.c_str(), NULL));
    else if (checkDouble(input_str))
        convertToNumber(input_str, std::strtold(input_str.c_str(), NULL));
    else if (checkInfinite(input_str))
        convertFromInfinite(input_str);
    else
        std::cout << "Unknown Input Type" << std::endl;
}