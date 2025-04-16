/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 16:28:10 by dsamuel           #+#    #+#             */
/*   Updated: 2025/04/16 17:57:02 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
    : AForm("", 25, 5), _targetName("")
{
  std::cout << "[PresidentialPardonForm] Default constructor invoked" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &targetName)
    : AForm(_targetName, 25, 5), _targetName(targetName) 
{
  std::cout << "[PresidentialPardonForm] Constructor invoked" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
    : AForm(other._targetName, 25, 5), _targetName(other._targetName)
{
  std::cout << "[PresidentialPardonForm] Copy constructor invoked" << std::endl;
  this->setIsSignedOrNot(other.getIsSignedOrNot());
}

PresidentialPardonForm &
PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
  std::cout << "[PresidentialPardonForm] Copy assigment operator invoked" << std::endl;
  if (this != &other)
  {
    this->setIsSignedOrNot(other.getIsSignedOrNot());
    this->_targetName = other._targetName;
  }
  return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
  std::cout << "[PresidentialPardonForm] Destructor invoked" << std::endl;
}

void PresidentialPardonForm::executer() const
{
  std::cout << "Informs that " << this->_targetName << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
