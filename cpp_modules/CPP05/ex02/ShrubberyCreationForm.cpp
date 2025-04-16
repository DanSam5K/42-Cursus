/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 16:20:58 by dsamuel           #+#    #+#             */
/*   Updated: 2025/04/16 19:03:57 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



// Created by tde-sous on 26-02-2024.
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
  this->setIsSignedOrNot(other.getIsSignedOrNot());
}

ShrubberyCreationForm &
ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
  std::cout << "[ShrubberyCreationForm] Copy assignment operator invoked." << std::endl;
  if (this != &other) {
    this->setIsSignedOrNot(other.getIsSignedOrNot());
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
    std::cerr << "Error opening file" << std::endl;
    return;
  }
  file << "       _-_\n"
          "    /~~   ~~\\\n"
          "  /~~         ~~\\\n"
          " /~~           ~~\\\n"
          "/~~             ~~\\\n"
          "       |||\n"
          "       |||\n";
  file.close();
}
