/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:31:05 by dsamuel           #+#    #+#             */
/*   Updated: 2025/04/16 17:40:53 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

class Bureaucrat;

class AForm
{
	private:
		std::string const _formName;
		bool	_signedOrNot;
		const unsigned int _gradeToSign;
		const unsigned int _gradeToExecute;

public:
	AForm(const std::string &formName, unsigned int gradeToSign, unsigned int gradeToExecute);
	AForm();
	AForm(const AForm &other);
	AForm &operator=(const AForm &other);
	
	virtual ~AForm() = 0;
	
	std::string getFormName() const;
	
	bool getIsSignedOrNot() const;
	void setIsSignedOrNot(bool signedorNot);
	
	unsigned int getGradeToSign() const;
	unsigned int getGradeToExecute() const;
	
	void beSigned(Bureaucrat &bureauSigner);

	void execute(Bureaucrat const &executor) const;

	virtual void executer() const = 0;

	class GradeTooHighException : public std::exception
	{
		const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		const char *what() const throw();
	};

	class FormIsNotSignedException : public std::exception 
	{
		const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &out, const AForm &form);

#endif // AFORM_HPP
