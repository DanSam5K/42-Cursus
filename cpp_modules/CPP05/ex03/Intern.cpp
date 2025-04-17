/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 19:57:12 by dsamuel           #+#    #+#             */
/*   Updated: 2025/04/17 20:14:17 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

// Intern::Intern() {
//   std::cout << "[Intern] Default constructor called." << std::endl;
// }

// Intern::Intern(const Intern &other) {
//   std::cout << "[Intern] Copy constructor called." << std::endl;
//   (void)other;
// }

// Intern &Intern::operator=(const Intern &other) {
//   std::cout << "[Intern] Copy assigment operator called." << std::endl;
//   (void)other;
//   return *this;
// }

// Intern::~Intern() { std::cout << "[Intern] Destructor called." << std::endl; }

// AForm *Intern::makeForm(const std::string &formName,
//                         const std::string &formTargetName) {
//   std::string names[3] = {"PresidentialPardon", "RobotomyRequest",
//                           "ShrubberyCreation"};
//   int number = 0;
//   while (number <= 3) {
//     if (names[number] == formName)
//       break;
//     number++;
//   }
//   switch (number) {
//   case 0:
//     return (makePresidentialPardonForm(formTargetName));
//   case 1:
//     return (makeRobotomyRequestForm(formTargetName));
//   case 2:
//     return (makeShrubberyCreationForm(formTargetName));
//   default:
//     throw FormNotFoundException();
//   }
// }

// AForm *Intern::makePresidentialPardonForm(const std::string &target) {
//   return (new PresidentialPardonForm(target));
// }

// AForm *Intern::makeRobotomyRequestForm(const std::string &target) {
//   return (new RobotomyRequestForm(target));
// }

// AForm *Intern::makeShrubberyCreationForm(const std::string &target) {
//   return (new ShrubberyCreationForm(target));
// }

// const char *Intern::FormNotFoundException::what() const throw() {
//   return "Form not found.";
// }


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
