/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 19:59:18 by dsamuel           #+#    #+#             */
/*   Updated: 2025/01/09 19:59:33 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal() {
  this->type = "Cat";
  this->CatBrain = new Brain();
  std::cout << "Cat -> Default constructor called!\n";
}

Cat::Cat(const Cat &other) : Animal(other) {
  std::cout << "Cat -> Default copy constructor called!\n";
  delete this->CatBrain;
  this->CatBrain = new Brain(*other.CatBrain);
}

Cat &Cat::operator=(const Cat &other) {
  std::cout << "Cat -> Copy assigment operator called!\n";
  if (this == &other)
    return *this;
  delete this->CatBrain;
  this->CatBrain = new Brain(*other.CatBrain);
  return *this;
}

Cat::~Cat() {
  delete this->CatBrain;
  std::cout << "Cat -> Destructor called!\n";
}

void Cat::makeSound() const {
  std::cout << "I am a Meow Meowwwww" << std::endl;
}
