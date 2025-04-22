/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 12:51:18 by dsamuel           #+#    #+#             */
/*   Updated: 2025/04/17 11:11:36 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// Constructor with grade validation
Bureaucrat::Bureaucrat() : _name("Default"), _grade(150)
{
    std::cout << "[Bureaucrat] default constructor invoked" << std::endl;
}

// Copy constructor
Bureaucrat::Bureaucrat(std::string const &name, int const &grade) : _name(name)
{
    std::cout << "[Bureaucrat] constructor invoked" << std::endl;
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
    this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : _name(src._name), _grade()
{
    std::cout << "[Bureaucrat] copy constructor invoked" << std::endl;
    *this = src;
}

// Assignment operator
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs)
{
    std::cout << "[Bureaucrat] assignment operator invoked" << std::endl;
    if (this != &rhs)
    {
        this->_grade = rhs._grade;
    }
    return *this;
}

// Destructor
Bureaucrat::~Bureaucrat()
{
    std::cout << "[Bureaucrat] destructor invoked" << std::endl;
}

// Getters
std::string Bureaucrat::getName() const
{
    return this->_name;
}

unsigned int Bureaucrat::getGrade() const
{
    return this->_grade;
}

// Member functions
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

// Functions to sign
void Bureaucrat::signForm(const Form *form, const std::string &signReason)
{
    if (signReason.empty())
        std::cout << this->getName() << " signed " << form->getName() << std::endl;
    else
        std::cout << this->getName() << " couldn't sign " << form->getName() << " because " << signReason << std::endl;
}

// Exception messages
const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Bureaucrat: Grade is too high!";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Bureaucrat: Grade is too low!";
}

// Overload << operator
std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureau_obj)
{
    out << bureau_obj.getName() << ", bureaucrat grade " << bureau_obj.getGrade() << ".";
    return out;
}
