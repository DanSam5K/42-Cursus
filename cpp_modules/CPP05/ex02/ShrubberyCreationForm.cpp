/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 16:20:58 by dsamuel           #+#    #+#             */
/*   Updated: 2025/04/17 18:53:17 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("", 145, 137), _targetName("") 
{
  std::cout << "[ShrubberyCreationForm] Default constructor invoked." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &targetName)
    : AForm(targetName, 145, 137), _targetName(targetName)
{
  std::cout << "[ShrubberyCreationForm] Constructor invoked." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : AForm(other.getFormName(), other.getGradeToSign(), other.getGradeToExecute()),
      _targetName(other._targetName) 
{
  std::cout << "[ShrubberyCreationForm] Copy constructor invoked." << std::endl;
  this->setSignedOrNot(other.getSignedOrNot());
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
  std::cout << "[ShrubberyCreationForm] Copy assignment operator invoked." << std::endl;
  if (this != &other) {
    this->setSignedOrNot(other.getSignedOrNot());
    this->_targetName = other._targetName;
  }
  return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() 
{
  std::cout << "[ShrubberyCreationForm] Destructor invoked." << std::endl;
}

void ShrubberyCreationForm::executer() const 
{
    std::ofstream file((this->_targetName + "_shrubbery").c_str());
    
    if (!file.is_open()) {
        std::cerr << "[ShrubberyCreationForm] Error: Could not create file " 
                  << this->_targetName + "_shrubbery" << std::endl;
        return;
    }

    file << "         ccee88oo\n"
            "      C8O8O8Q8PoOb o8oo\n"
            "   dOB69QO8PdUOpugoO9bD\n"
            "CgggbU8OU qOp qOdoUOdcb\n"
            "    6OuU  /p u gcoUodpP\n"
            "      \\\\//  /douUP\n"
            "        ||  ||\n"
            "        ||  ||\n"
            "        ||  ||\n"
            "  jgs   ||  ||\n"
            "        ||  ||\n"
            "   __||__||__||__\n";

    file.close();
    std::cout << "[ShrubberyCreationForm] File created successfully: " 
              << this->_targetName + "_shrubbery" << std::endl;
}