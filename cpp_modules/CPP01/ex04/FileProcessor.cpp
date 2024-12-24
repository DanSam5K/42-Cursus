/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileProcessor.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 11:09:07 by dsamuel           #+#    #+#             */
/*   Updated: 2024/12/24 13:36:59 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileProcessor.hpp"

FileProcessor::FileProcessor(const std::string &filename, const std::string &stringToReplace, const std::string &stringToReplaceWith)
    : _filename(filename), _stringToReplace(stringToReplace), _stringToReplaceWith(stringToReplaceWith) {}

std::string FileProcessor::replaceOccurrences(const std::string &content, const std::string &stringToReplace, const std::string &stringToReplaceWith)
{
    std::string result;
    size_t startPos = 0;
    size_t pos = 0;

    while ((pos = content.find(stringToReplace, startPos)) != std::string::npos)
    {
        result += content.substr(startPos, pos - startPos);
        result += stringToReplaceWith;
        startPos = pos + stringToReplace.length();
    }
    result += content.substr(startPos, content.length() - startPos);

    return result;
}

void FileProcessor::replaceAndSave()
{
    std::ifstream inputFile(_filename.c_str());
    if (!inputFile.is_open()) {
        throw std::runtime_error("Cannot open file " + _filename);
    }

    std::ostringstream buffer;
    buffer << inputFile.rdbuf();
    std::string content = buffer.str();
    inputFile.close();

    std::string newContent = replaceOccurrences(content, _stringToReplace, _stringToReplaceWith);
    std::ofstream outputFile((_filename + ".replace").c_str());
    if (!outputFile.is_open()) {
        throw std::runtime_error("Cannot create file " + _filename + ".replace");
    }
    
    outputFile << newContent;
    outputFile.close();
}