/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 12:18:42 by dsamuel           #+#    #+#             */
/*   Updated: 2025/04/17 11:15:56 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX01_FORM_HPP
#define EX01_FORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

class Bureaucrat; // Forward declaration of Bureaucrat class

class Form
{
    private:
        std::string const _name; // const because it should not be changed
        bool _signedOrNot; // true if the form is signed, false otherwise
        const unsigned int _gradeToSign; // grade required to sign the form
        const unsigned int _gradeToExecute; // grade required to execute the form

    public:
        // Constructor & Destructor
        Form(const std::string &name, unsigned int gradeToSign, unsigned int gradeToExecute);
        Form();
        Form(const Form &other);
        Form &operator=(const Form &other);
        ~Form();

        //Getters
        std::string getName() const;
        bool getSignedOrNot() const;
        unsigned int getGradeToSign() const;
        unsigned int getGradeToExecute() const;

        // Functions  Sign and Execute
        void beSigned(Bureaucrat &bureaucrat);
        
        //Exception classes 
        class GradeTooHighException : public std::exception
        {
            const char *what() const throw(); // custome err msg
        };

        class GradeTooLowException : public std::exception
        {
            const char *what() const throw();
        };
};

// Overload << operator
std::ostream &operator<<(std::ostream &out, const Form &form);

#endif  //EX01_FORM_HPP