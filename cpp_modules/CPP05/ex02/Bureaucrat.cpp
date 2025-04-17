/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 12:51:18 by dsamuel           #+#    #+#             */
/*   Updated: 2025/04/17 13:36:10 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150)
{
  std::cout << "[Bureaucrat] Default constructor invoked" << std::endl;
}

Bureaucrat::Bureaucrat(std::string const &name, int const &grade)
    : _name(name) 
{
  std::cout << "[Bureaucrat] Constructor invoked" << std::endl;
  if (grade < 1)
    throw Bureaucrat::GradeTooHighException();
  if (grade > 150)
    throw Bureaucrat::GradeTooLowException();
  this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade()
{
  std::cout << "[Bureaucrat] Copy constructor invoked" << std::endl;
  *this = other;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
  std::cout << "[Bureaucrat] Copy assignment invoked" << std::endl;
  if (this != &other)
  {
    this->_grade = other._grade;
  }
  return *this;
}

Bureaucrat::~Bureaucrat()
{
  std::cout << "[Bureaucrat] Destructor invoked" << std::endl;
}

void Bureaucrat::decrementGrade()
{
  if (this->_grade + 1 > 150)
    throw GradeTooLowException();
  this->_grade++;
}

void Bureaucrat::incrementGrade() 
{
  if (this->_grade - 1 < 1)
    throw GradeTooHighException();
  this->_grade--;
}

unsigned int Bureaucrat::getGrade() const
{ 
  return this->_grade; 
}

std::string Bureaucrat::getName() const 
{ 
  return this->_name; 
}

const char *Bureaucrat::GradeTooHighException::what() const throw() 
{
  return ("Grade is too High!");
}

const char *Bureaucrat::GradeTooLowException::what() const throw() 
{
  return ("Grade is too Low!");
}

void Bureaucrat::signForm(const AForm *signedForm, const std::string &signReason) 
{
  if (signReason.empty())
    std::cout << this->getName() << " signed " << signedForm->getFormName() << std::endl;
  else
    std::cout << this->getName() << " couldn't sign " << signedForm->getFormName() 
              << " because " << signReason << std::endl;
}

void Bureaucrat::executeForm(AForm const &form) 
{
  try
  {
    form.executer();
    std::cout << this->getName() << " executed " << form.getFormName() << std::endl;
  }
  catch (std::exception &e)
  {
    std::cout << this->_name << " couldn't execute " << form.getFormName() 
              << " because " << e.what() << std::endl;
  }
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureau_obj)
{
  out << "[Bureaucrat] " << bureau_obj.getName() << ", bureaucrat grade " 
      << bureau_obj.getGrade() << ".";
  return out;
}
