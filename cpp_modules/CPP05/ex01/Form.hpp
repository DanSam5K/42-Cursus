/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 12:18:42 by dsamuel           #+#    #+#             */
/*   Updated: 2025/03/31 12:43:16 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX01_FORM_HPP
#define EX01_FORM_HPP

#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat; // Forward declaration of Bureaucrat class

class Form
{
    private:
        const std::string name; // const because it should not be changed
        bool isSigned; // true if the form is signed, false otherwise
        const int gradeToSign; // grade required to sign the form
        const int gradeToExecute; // grade required to execute the form

    public:
        //Exception classes 
        class GradeTooHighException : public std::exception
        {
            public:
                const char* what() const throw(); // custome err msg
        };

        class GradeTooLowException : public std::exception
        {
            public:
                const char* what() const throw();
        };

        // Constructor & Destructor
        Form(const std::string name, int gradeToSign, int gradeToExecute);
        ~Form();

        //Getters
        std::string getName() const;
        bool getIsSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;

        // Functions  Sign and Execute
        void beSigned(const Bureaucrat &bureaucrat);

        // Overload
        friend std::ostream& operator<<(std::ostream &out, const Form &form);
};


#endif  //EX01_FORM_HPP