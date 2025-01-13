/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 19:59:44 by dsamuel           #+#    #+#             */
/*   Updated: 2025/01/09 19:59:46 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal() {
  this->type = "Dog";
  this->DogBrain = new Brain();
  std::cout << "Dog -> Default constructor called!\n";
}

Dog::Dog(const Dog &other) : Animal(other) {
  std::cout << "Dog -> Default copy constructor called!\n";
  delete this->DogBrain;
  this->DogBrain = new Brain(*other.DogBrain);
}

Dog &Dog::operator=(const Dog &other) {
  std::cout << "Dog -> Copy assigment operator called!\n";
  if (this == &other)
    return *this;
  delete this->DogBrain;
  this->DogBrain = new Brain(*other.DogBrain);
  return *this;
}

Dog::~Dog() {
  delete this->DogBrain;
  std::cout << "Dog -> Destructor called!\n";
}

void Dog::makeSound() const {
  std::cout << "I am a auf auf auffff...." << std::endl;
}
