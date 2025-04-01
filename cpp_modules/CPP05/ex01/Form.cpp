/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 12:30:25 by dsamuel           #+#    #+#             */
/*   Updated: 2025/03/31 12:48:56 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

// Constructor with calidation
Form::Form(const std::string name, int gradeToSign, int gradeToExecute)
    : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

// Destructor
Form::~Form() {}

// Getters
std::string Form::getName() const
{
    return name;
}

bool Form::getIsSigned() const
{
    return isSigned;
}

int Form::getGradeToSign() const
{
    return gradeToSign;
}

int Form::getGradeToExecute() const
{
    return gradeToExecute;
}

// Bureaucrat attempt to sign the form
void Form::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > gradeToSign)
        throw GradeTooLowException();
    isSigned = true;
}

// Exception Messages
const char* Form::GradeTooHighException::what() const throw()
{
    return "Form: Grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Form: Grade is too low!";
}

// Overload << operator for printing
std::ostream& operator<<(std::ostream &out, const Form &form)
{
    out << "Form Name: " << form.getName() << ", Signed: " << (form.getIsSigned() ? "Yes" : "No")
        << ", Grade to Sign: " << form.getGradeToSign() << ", Grade to Execute: " << form.getGradeToExecute();
    return out;
}