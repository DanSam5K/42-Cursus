/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 12:30:25 by dsamuel           #+#    #+#             */
/*   Updated: 2025/04/03 18:32:01 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(const std::string &name, const unsigned int gradeToSign,
    const unsigned int gradeToExecute)
: _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    std::cout << "[Form] Constructor called." << std::endl;
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw Form::GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw Form::GradeTooLowException();
    this->_isSigned = false;
}

Form::Form() : _name("Default"), _isSigned(false),
    _gradeToSign(150), _gradeToExecute(150) 
{
    std::cout << "[Form] Default constructor called." << std::endl;
}

Form::Form(const Form &other)
    : _name(other._name), _isSigned(), _gradeToSign(other.getGradeToSign()), _gradeToExecute(other.getGradeToExecute())
{
    std::cout << "[Form] Copy constructor called." << std::endl;
    this->_isSigned = other._isSigned;
}

Form &Form::operator=(const Form &other)
{
    std::cout << "[Form] Assignment operator called." << std::endl;
    if (this != &other)
    {
        this->_isSigned = other._isSigned;
    }
    return *this;
}

Form::~Form()
{
    std::cout << "[Form] Destructor called." << std::endl;
}

std::string Form::getName() const 
{ 
    return this->_name; 
}

bool Form::getIsSigned() const
{ 
    return this->_isSigned; 
}

unsigned int Form::getGradeToSign() const
{ 
    return (this->_gradeToSign); 
}

unsigned int Form::getGradeToExecute() const 
{ 
    return (this->_gradeToExecute); 
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
    if (this->getIsSigned())
        bureaucrat.signForm(this, "already signed");
    if (bureaucrat.getGrade() > this->getGradeToSign())
    {
        bureaucrat.signForm(this, "grade too low");
        throw Form::GradeTooLowException();
    }
    this->_isSigned = true;
    bureaucrat.signForm(this, "signed");
}

const char *Form::GradeTooHighException::what() const throw()
{
    return "[Form Exception] Grade is too High!";
}

const char *Form::GradeTooLowException::what() const throw() 
{
    return "[Form Exception] Grade is too Low!";
}

std::ostream &operator<<(std::ostream &out, const Form &form)
{
    out << form.getName() << ", Form grade to sign: " << form.getGradeToSign()
        << ", Form grade to execute: " << form.getGradeToExecute()
        << ", Form is signed: " << (form.getIsSigned() ? "yes" : "no");
    return out;
}
