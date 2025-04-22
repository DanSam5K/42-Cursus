/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 12:09:19 by dsamuel           #+#    #+#             */
/*   Updated: 2025/04/17 18:04:30 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "AForm.hpp"

#include <string>
#include <iostream>

class AForm;

class Bureaucrat 
{
  private:
    std::string const _name;
    unsigned int _grade;

  public:
    Bureaucrat();
    Bureaucrat(std::string const &name, int const &grade);
    Bureaucrat(const Bureaucrat &other);
    Bureaucrat &operator=(const Bureaucrat &other);
    ~Bureaucrat();
    
    void incrementGrade();
    void decrementGrade();

    std::string getName() const;
    
    unsigned int getGrade() const;
  
    void signForm(const AForm *signedForm, const std::string &signReason);

    void executeForm(AForm const &form);

    class GradeTooHighException : public std::exception 
    {
      const char *what() const throw();
    };

    class GradeTooLowException : public std::exception 
    {
      const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureau_obj);

#endif
