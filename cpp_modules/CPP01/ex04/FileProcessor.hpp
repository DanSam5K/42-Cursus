/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileProcessor.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 19:04:59 by dsamuel           #+#    #+#             */
/*   Updated: 2024/12/24 13:36:13 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX04_FILEPROCESSOR_HPP
#define EX04_FILEPROCESSOR_HPP

#include <string>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <sstream>

class FileProcessor {
private:
    std::string _filename;
    std::string _stringToReplace;
    std::string _stringToReplaceWith;
    
    std::string replaceOccurrences(const std::string &content, const std::string &stringToReplace, const std::string &stringToReplaceWith);

public:
    FileProcessor(const std::string &filename, const std::string &stringToReplace, const std::string &stringToReplaceWith);
    
    void replaceAndSave();
};

#endif //EX04_FILEPROCESSOR_HPP
