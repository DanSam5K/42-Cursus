/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 13:22:35 by dsamuel           #+#    #+#             */
/*   Updated: 2025/04/03 17:35:56 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX00_BUREAUCRAT_HPP
#define EX00_BUREAUCRAT_HPP

#include <iostream>
#include <string>

class Bureaucrat
{
    private:
        std::string const   _name; // const because it should not be changed
        unsigned int        _grade; // grade(1=best, 150=worst) can be changed
    
    public:
        Bureaucrat();
        Bureaucrat(std::string const &name, int const &grade);
        Bureaucrat(const Bureaucrat &other);
        Bureaucrat &operator=(const Bureaucrat &other);
        ~Bureaucrat();
        
        //Getters
        std::string getName() const;
        unsigned int getGrade() const;
        
        // Functions  Grade modifications
        void incrementGrade();
        void decrementGrade();
        
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
std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

#endif //EX00_BUREAUCRAT_HPP