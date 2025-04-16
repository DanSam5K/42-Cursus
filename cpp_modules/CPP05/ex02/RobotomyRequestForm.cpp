/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 16:26:44 by dsamuel           #+#    #+#             */
/*   Updated: 2025/04/16 18:45:43 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// Created by tde-sous on 26-02-2024.
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("", 72, 45), _targetName("") {
  std::cout << "[RobotomyRequestForm] Default constructor invoked" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &targetName)
    : AForm(targetName, 72, 45), _targetName(targetName) {
  std::cout << "[RobotomyRequestForm] Constructor invoked" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
    : AForm(other._targetName, 72, 45)
{
  std::cout << "[RobotomyRequestForm] Copy constructor constructor invoked"<< std::endl;
  this->setIsSignedOrNot(other.getIsSignedOrNot());
  this->_targetName = other._targetName;
}

RobotomyRequestForm &
RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
  std::cout << "[RobotomyRequestForm] Copy assignment operator invoked" << std::endl;
  if (this != &other)
  {
    this->setIsSignedOrNot(other.getIsSignedOrNot());
    this->_targetName = other._targetName;
  }
  return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() 
{
  std::cout << "[RobotomyRequestForm] Destructor invoked" << std::endl;
}

void RobotomyRequestForm::executer() const
{
  std::cout << "[RobotomyRequestForm] " << this->_targetName << " has been robotomized successfully 50% of the time." << std::endl;
  std::srand(std::time(0));
  int random = std::rand() % 2;
  if (random == 0)
    std::cout << "[RobotomyRequestForm] " << this->_targetName << " has been robotomized successfully." << std::endl;
  else
    std::cout << "[RobotomyRequestForm] " << this->_targetName << " has failed to be robotomized." << std::endl;
}