/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 11:11:39 by dsamuel           #+#    #+#             */
/*   Updated: 2025/04/29 16:00:00 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <exception>
#include <cstdlib>
#include <ctime>

class BitcoinExchange {
    private:
        std::map<std::string, float> _priceData;

        BitcoinExchange();
        void loadDatabase();
        void processInput(const char *filename);
        float lookupValue(const std::string &dateOfExchange);

        template <typename T>
        static std::string convertNumToString(T numValue);

        static bool confirmIsValidDate(const std::tm &dateStruct);

    public:
        explicit BitcoinExchange(const char* filename);
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);
        ~BitcoinExchange();

        // Custom exception classes
        class DatabaseFileError : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

        class AmountOutOfRange : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

        class InvalidDateError : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

        class InvalidFormatError : public std::exception 
        {
            public:
                virtual const char* what() const throw();
        };

        class WrongHeaderError : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

        class EmptyFileError : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

#endif
