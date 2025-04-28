/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 11:16:55 by dsamuel           #+#    #+#             */
/*   Updated: 2025/04/23 12:59:07 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <cstdlib>
#include <iostream>
#include <limits>
#include <string>

#define DIGITS "0123456789"

enum ScalarType { TYPE_CHAR, TYPE_INT, TYPE_FLOAT, TYPE_DOUBLE, TYPE_INF };

class ScalarConverter 
{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &source);
        ScalarConverter &operator=(const ScalarConverter &source);
        virtual ~ScalarConverter() = 0;

        static bool checkCharacter(const std::string &str);
        static bool checkInteger(const std::string &str);
        static bool checkFloat(const std::string &str);
        static bool checkDouble(const std::string &str);
        static bool checkInfinite(const std::string &str);
        
        static void convertToNumber(const std::string &str, long double value);
        static void convertFromInfinite(const std::string &str);
        static void convertFromCharacter(const std::string &str);
        static void convertToCharacter(const char &c);

    public:
        static void convert(const std::string &str);
};

#endif // SCALAR_CONVERTER_HPP