/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 11:17:22 by dsamuel           #+#    #+#             */
/*   Updated: 2025/04/29 18:30:50 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

template <typename T>
std::string BitcoinExchange::convertNumToString(T value)
{
    std::ostringstream stream;
    stream << value;
    return stream.str();
}

float BitcoinExchange::lookupValue(const std::string &dateOfExchange)
{
    std::map<std::string, float>::iterator it = _priceData.begin();

    while (it != _priceData.end()) {
        if (dateOfExchange <= it->first) {
            if (dateOfExchange < it->first && it != _priceData.begin())
                --it;
            return it->second;
        }
        ++it;
    }
    if (!_priceData.empty())
        --it;
    return it->second;
}

void BitcoinExchange::loadDatabase()
{
    std::ifstream dbFile("data.csv", std::ifstream::in);
    std::string line;

    if (!dbFile.is_open())
        throw DatabaseFileError();

    int lineCount = 0;
    while (std::getline(dbFile, line)) {
        if (line == "date,exchange_rate" && lineCount++ == 0)
            continue;

        std::string dateOfExchange = line.substr(0, line.find(','));
        std::string valueStr = line.substr(line.find(',') + 1);

        _priceData.insert(std::make_pair(dateOfExchange, atof(valueStr.c_str())));
        ++lineCount;
    }

    if (lineCount == 0)
        throw EmptyFileError();
}

void BitcoinExchange::processInput(const char* filename)
{
    std::ifstream inputFile(filename, std::ifstream::in);
    std::string line;
    int lineNumber = 0;

    while (std::getline(inputFile, line)) {
        try {
            if (lineNumber == 0) {
                if (line != "date | value")
                    throw WrongHeaderError();
                ++lineNumber;
                continue;
            }

            if (line.find(" | ") == std::string::npos)
            {
                std::cout << "Error at line " << (lineNumber + 1) << ": " << line << std::endl;
                throw InvalidFormatError();
            }

            std::string dateStr = line.substr(0, line.find(" | "));
            std::string amountStr = line.substr(line.find(" | ") + 3);

            if (dateStr.empty() || amountStr.empty())
            {
                std::cout << "Error at line " << (lineNumber + 1) << ": " << line << std::endl;
                throw InvalidFormatError();
            }

            struct tm timeStruct = {};
            if (!strptime(dateStr.c_str(), "%Y-%m-%d", &timeStruct) || !confirmIsValidDate(timeStruct))
            {
                std::cout << "Error at line " << (lineNumber + 1) << ": " << line << std::endl;
                throw InvalidDateError();
            }

            float amount = atof(amountStr.c_str());
            if (amount < 0.0f || amount > 1000.0f)
            {
                std::cout << "Error at line " << (lineNumber + 1) << ": " << line << std::endl;
                throw AmountOutOfRange();
            }

            float exchangeRate = lookupValue(dateStr);
            std::cout << dateStr << " => " << amountStr << " = " << (exchangeRate * amount) << std::endl;
        }
        catch (std::exception& e) {
            std::cout << "Error at line " << (lineNumber + 1) << ": " << e.what() << std::endl;
        }
        ++lineNumber;
    }

    if (lineNumber == 0)
        throw EmptyFileError();
}

bool BitcoinExchange::confirmIsValidDate(const std::tm& date)
{
    switch (date.tm_mon) {
        case 1: // February
            if ((date.tm_year % 4 == 0 && date.tm_year % 100 != 0) || (date.tm_year % 400 == 0))
                return date.tm_mday <= 29;
            else
                return date.tm_mday <= 28;
        case 3: case 5: case 8: case 10: // April, June, September, November
            return date.tm_mday <= 30;
        default:
            return date.tm_mday <= 31;
    }
}

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const char* filename)
{
    loadDatabase();
    processInput(filename);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) 
{
    (void)other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &other) 
{
    (void)other;
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

// Exception implementations
const char* BitcoinExchange::DatabaseFileError::what() const throw()
{
    return "Error: Unable to open database file (data.csv).";
}

const char* BitcoinExchange::AmountOutOfRange::what() const throw()
{
    return "Error: Amount must be between 0 and 1000.";
}

const char* BitcoinExchange::InvalidDateError::what() const throw()
{
    return "Error: Invalid date format.";
}

const char* BitcoinExchange::InvalidFormatError::what() const throw()
{
    return "Error: Line format invalid (expected 'date | value').";
}

const char* BitcoinExchange::WrongHeaderError::what() const throw() 
{
    return "Error: Incorrect header in input file.";
}

const char* BitcoinExchange::EmptyFileError::what() const throw()
{
    return "Error: No data to process in input file.";
}