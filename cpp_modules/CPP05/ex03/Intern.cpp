/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 19:57:12 by dsamuel           #+#    #+#             */
/*   Updated: 2025/04/22 14:00:34 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {
    std::cout << "[Intern] Default constructor invoked." << std::endl;
}

Intern::Intern(const Intern &other) {
    std::cout << "[Intern] Copy constructor invoked." << std::endl;
    (void)other;
}

Intern &Intern::operator=(const Intern &other) {
    std::cout << "[Intern] Assignment operator invoked." << std::endl;
    (void)other;
    return *this;
}

Intern::~Intern() {
    std::cout << "[Intern] Destructor invoked." << std::endl;
}

AForm *Intern::createForm(const std::string &formName, const std::string &target) {
    const std::string formTypes[] = {"PresidentialPardon", "RobotomyRequest", "ShrubberyCreation"};
    AForm *(*formCreators[])(const std::string &) = {
        &Intern::createPresidentialPardonForm,
        &Intern::createRobotomyRequestForm,
        &Intern::createShrubberyCreationForm
    };

    for (size_t i = 0; i < 3; ++i) {
        if (formTypes[i] == formName) {
            std::cout << "[Intern] Creating form: " << formName << std::endl;
            return formCreators[i](target);
        }
    }

    throw FormNotFoundException();
}

AForm *Intern::createPresidentialPardonForm(const std::string &target) {
    return new PresidentialPardonForm(target);
}

AForm *Intern::createRobotomyRequestForm(const std::string &target) {
    return new RobotomyRequestForm(target);
}

AForm *Intern::createShrubberyCreationForm(const std::string &target) {
    return new ShrubberyCreationForm(target);
}

const char *Intern::FormNotFoundException::what() const throw() {
    return "[Intern] Error: Requested form not found.";
}
