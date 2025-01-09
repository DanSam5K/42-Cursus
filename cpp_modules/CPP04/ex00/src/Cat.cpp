/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 19:10:15 by dsamuel           #+#    #+#             */
/*   Updated: 2025/01/09 19:45:20 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal() {
  this->type = "Cat";
  std::cout << "Cat -> Default constructor called!\n";
}

Cat::Cat(const Cat &other) : Animal(other) {
  std::cout << "Cat -> Default copy constructor called!\n";
  this->type = other.type;
}

Cat &Cat::operator=(const Cat &other) {
  std::cout << "Cat -> Copy assigment operator called!\n";
  if (this == &other)
    return *this;
  this->type = other.type;
  return *this;
}

Cat::~Cat() { std::cout << "Cat -> Destructorcalled!\n"; }

void Cat::makeSound() const {
  std::cout << "I am a Meow Meowwwww" << std::endl;
}
