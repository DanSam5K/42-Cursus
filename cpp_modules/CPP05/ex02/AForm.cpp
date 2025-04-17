/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:50:25 by dsamuel           #+#    #+#             */
/*   Updated: 2025/04/17 18:57:19 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(const std::string &formName, const unsigned int gradeToSign,
             const unsigned int gradeToExecute)
    : _formName(formName), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
  std::cout << "[AForm] Constructor invoked" << std::endl;
  if (gradeToSign < 1 || gradeToExecute< 1)
    throw GradeTooHighException();
  if (gradeToSign > 150 || gradeToExecute > 150)
    throw GradeTooLowException();
  this->_signedOrNot = false;
}

AForm::AForm()
    : _formName("default"), _signedOrNot(false), _gradeToSign(150), _gradeToExecute(150)
{
  std::cout << "[AForm] default constructor invoked" << std::endl;
}

AForm::AForm(const AForm &other)
    : _formName(other._formName), _signedOrNot(), _gradeToSign(other.getGradeToSign()),
      _gradeToExecute(other.getGradeToExecute())
{
  std::cout << "[AForm] Copy constructor invoked" << std::endl;
  this->_signedOrNot = other._signedOrNot;
}

AForm &AForm::operator=(const AForm &other)
{
  std::cout << "[AForm] assignment operator invoked" << std::endl;
  if (this != &other)
  {
    this->_signedOrNot = other._signedOrNot;
  }
  return *this;
}

AForm::~AForm() 
{
  std::cout << "[AForm] Destructor invoked." << std::endl; 
}

std::string AForm::getFormName() const
{
  return  this->_formName;
}

bool AForm::getSignedOrNot() const
{
  return this->_signedOrNot;
}

void AForm::setSignedOrNot(bool signedOrNot)
{
  this->_signedOrNot = signedOrNot;
}

unsigned int AForm::getGradeToSign() const
{
  return this->_gradeToSign;
}

unsigned int AForm::getGradeToExecute() const
{
    return this->_gradeToExecute;
}

void AForm::beSigned(Bureaucrat &bureauSigner)
{
  if (this->getSignedOrNot())
    bureauSigner.signForm(this, "already signed");
  if (bureauSigner.getGrade() > this->getGradeToSign())
  {
    bureauSigner.signForm(this, "grade too low");
    throw AForm::GradeTooLowException();
  }
  this->_signedOrNot = true;
  bureauSigner.signForm(this, "signed");
}

void AForm::execute(Bureaucrat const &executor) const {
  if (!this->getGradeToSign())
    throw AForm::FormIsNotSignedException();
  if (this->getGradeToSign() < executor.getGrade())
    throw AForm::GradeTooLowException();
  this->executer();
}

const char *AForm::GradeTooHighException::what() const throw()
{
  return ("[Form][Exception] Grade is too High!");
}

const char *AForm::GradeTooLowException::what() const throw()
{
  return ("[Form][Exception] Grade is too Low!");
}

const char *AForm::FormIsNotSignedException::what() const throw() {
  return ("[Form][Exception] The Form was not signed!");
}

std::ostream &operator<<(std::ostream &out, const AForm &form) {
  out << "[AForm] Form name: " << form.getFormName() << ", is signed: "
      << (form.getSignedOrNot() ? "true" : "false")
      << ", grade to sign: " << form.getGradeToSign()
      << ", grade to execute: " << form.getGradeToExecute();
  return out;
}
