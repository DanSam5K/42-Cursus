/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 16:53:54 by dsamuel           #+#    #+#             */
/*   Updated: 2025/04/17 18:55:52 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
  // Demonstrating expected flow for different forms
  try {
    Bureaucrat user1("example_user", 144);
    ShrubberyCreationForm form1("greeting");
    form1.execute(user1);
    std::cout << form1 << std::endl;
    form1.beSigned(user1);
    // Uncomment to test execution post-signature
    // form1.execute(user1);
    std::cout << form1 << std::endl;
  } catch (const std::exception &err) {
    std::cout << err.what() << std::endl;
  }

  std::cout << "============" << std::endl;

  try {
    Bureaucrat user2("example_user", 72);
    RobotomyRequestForm form2("greeting");
    std::cout << form2 << std::endl;
    form2.beSigned(user2);
    std::cout << form2 << std::endl;
    user2.executeForm(form2);
  } catch (const std::exception &err) {
    std::cout << err.what() << std::endl;
  }

  std::cout << "============" << std::endl;

  try {
    Bureaucrat user3("example_user", 25);
    PresidentialPardonForm form3("greeting");
    std::cout << form3 << std::endl;
    form3.beSigned(user3);
    std::cout << form3 << std::endl;
    // You can add execution here if needed
  } catch (const std::exception &err) {
    std::cout << err.what() << std::endl;
  }

  std::cout << "============" << std::endl;
}