/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 13:08:58 by dsamuel           #+#    #+#             */
/*   Updated: 2025/04/17 12:10:40 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    // Test Bureaucrat and Form classes
    try {
      Bureaucrat BureaucratA("Bureaucrat A", 124);
      Form FormA("Formâge A", 124,  123);
      std::cout << FormA << std::endl;
      FormA.beSigned(BureaucratA);
      std::cout << FormA << std::endl;
    } catch (std::exception &e) {
      std::cout << e.what() << std::endl;
    }
    std::cout << "============" << std::endl;
  
    // Test Form signing with correct grade
    try {
      Bureaucrat BureaucratA("Bureaucrat A", 124);
      Form FormB("Formâge B", 150,  123);
      FormB.beSigned(BureaucratA);
      std::cout << FormB << std::endl;
      BureaucratA.signForm(&FormB, "");
    } catch (std::exception &e) {
      std::cout << e.what() << std::endl;
    }
    std::cout << "============" << std::endl;
    
    // Incorrect grade
    try {
      Bureaucrat BureaucratA("Bureaucrat A", 124);
      Form FormB("Formâge B", 0,  123);
      FormB.beSigned(BureaucratA);
      std::cout << FormB << std::endl;
    } catch (std::exception &e) {
      std::cout << e.what() << std::endl;
    }
    
    std::cout << "============" << std::endl;
}
