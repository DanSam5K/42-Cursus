/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 19:10:30 by dsamuel           #+#    #+#             */
/*   Updated: 2025/01/09 19:10:43 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal() {
  this->type = "Dog";
  std::cout << "Dog -> Default constructor called!\n";
}

Dog::Dog(const Dog &other) : Animal(other) {
  std::cout << "Dog -> Default copy constructor called!\n";
  this->type = other.type;
}

Dog &Dog::operator=(const Dog &other) {
  std::cout << "Dog -> Copy assigment operator called!\n";
  if (this == &other)
    return *this;
  this->type = other.type;
  return *this;
}

Dog::~Dog() { std::cout << "Dog -> Destructor called!\n"; }

void Dog::makeSound() const {
  std::cout << "I am a auf auf auffff...." << std::endl;
}
