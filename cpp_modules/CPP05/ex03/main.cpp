/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 16:53:54 by dsamuel           #+#    #+#             */
/*   Updated: 2025/04/17 20:14:30 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
  // Expected behavior
  try {
    Intern someRandomIntern;
    AForm* rrf;
    rrf = someRandomIntern.createForm("PresidentialPardon", "Bender");
    std::cout << rrf->getFormName() << std::endl;
    rrf->executer();
    delete rrf;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  std::cout << "============" << std::endl;
}