/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 12:09:19 by dsamuel           #+#    #+#             */
/*   Updated: 2025/04/16 18:25:32 by dsamuel          ###   ########.fr       */
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

#endif // BUREAUCRAT_HPP













// #ifndef EX01_BUREAUCRAT_HPP
// #define EX01_BUREAUCRAT_HPP

// #include "AForm.hpp"
// #include <iostream>
// #include <string>

// class AForm; // Forward declaration of Form class CD

// class Bureaucrat 
// {
//     private:
//         std::string const   _name; // const because it should not be changed
//         int                 _grade; // grade(1=best, 150=worst) can be changed

//     public:
//         Bureaucrat();
//         Bureaucrat(std::string const &name, int const &grade);
//         Bureaucrat(const Bureaucrat &other);
//         Bureaucrat &operator=(const Bureaucrat &other);

//         ~Bureaucrat();

//         void incrementGrade();
//         void decrementGrade();
        
//         //Getters
//         std::string getName() const;
//         int getGrade() const;

//         // Functions to sign
//         void signForm(const AForm *form, const std::string &reason);

//         void executeForm(AForm const &form);

//         // Exception classes
//         class GradeTooHighException : public std::exception
//         {
//             const char *what() const throw();
//         };

//         class GradeTooLowException : public std::exception
//         {
//             const char *what() const throw();
//         };

// };

// std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

// #endif //EX01_BUREAUCRAT_HPP