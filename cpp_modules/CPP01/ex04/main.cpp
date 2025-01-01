/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 20:28:05 by dsamuel           #+#    #+#             */
/*   Updated: 2024/12/24 13:02:07 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileProcessor.hpp"

int main (int argc, char **argv)
{
    if (argc != 4)
    {
        std::cerr << "Usage: " << argv[0] << " filename stringToReplace stringToReplaceWith" << std::endl;
        return 1;
    }
    
    std::string filename = argv[1];
    std::string stringToReplace = argv[2];
    std::string stringToReplaceWith = argv[3];
    
    if(stringToReplace.empty() || stringToReplaceWith.empty())
    {
        std::cerr << "Error: stringToReplace or stringToReplaceWith is empty" << std::endl;
        return 1;
    }
    
    try
    {
        FileProcessor processor(filename, stringToReplace, stringToReplaceWith);
        processor.replaceAndSave();
        std::cout << "File " << filename << " has been successfully processed" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
