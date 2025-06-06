/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 19:11:01 by dsamuel           #+#    #+#             */
/*   Updated: 2025/01/09 19:11:15 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
  std::cout << "[WrongAnimal] Default constructor called.\n";
  this->type = "WrongAnimal";
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) {
  std::cout << "[WrongAnimal] Copy constructor called.\n";
  this->type = other.type;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other) {
  std::cout << "[WrongAnimal] Copy assignment operator called.\n";
  if (this == &other)
    return *this;
  this->type = other.type;
  return *this;
}

WrongAnimal::~WrongAnimal() {
  std::cout << "[WrongAnimal] Destructor called.\n";
}

void WrongAnimal::makeSound() const {
  std::cout << "I'm just a WrongAnimal, I can't make proper sounds!"
            << std::endl;
}

std::string WrongAnimal::getType() const { return this->type; }
