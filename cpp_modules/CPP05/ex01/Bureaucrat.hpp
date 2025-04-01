/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 12:09:19 by dsamuel           #+#    #+#             */
/*   Updated: 2025/03/31 12:18:04 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX01_BUREAUCRAT_HPP
#define EX01_BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
#include "Form.hpp"

class Form; // Forward declaration of Form class CD

class Bureaucrat 
{
    private:
        const std::string name; // const because it should not be changed
        int grade; // grade(1=best, 150=worst) can be changed

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
        Bureaucrat(const std::string name, int grade);
        ~Bureaucrat();

        //Getters
        std::string getName() const;
        int getGrade() const;

        // Functions  Grade modifications
        void incrementGrade();
        void decrementGrade();

        // Functions to sign
        void signForm(Form &form);

        // Overload
        friend std::ostream& operator<<(std::ostream &out, const Bureaucrat &bureaucrat);
};


#endif //EX01_BUREAUCRAT_HPP