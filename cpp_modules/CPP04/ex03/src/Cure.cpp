/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 20:27:24 by dsamuel           #+#    #+#             */
/*   Updated: 2025/01/09 20:27:26 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {
  std::cout << "[Cure] Default constructor called" << std::endl;
}

Cure::Cure(const Cure &other) : AMateria(other) {
  std::cout << "[Cure] Copy constructor called" << std::endl;
}

Cure &Cure::operator=(const Cure &other) {
  std::cout << "[Cure] Copy assignment operator called" << std::endl;
  if (this == &other)
    return (*this);
  this->type_ = other.type_;
  return *this;
}

Cure::~Cure() { std::cout << "[Cure] Destructor called" << std::endl; }

AMateria *Cure::clone() const {
  Cure *clone = new Cure;
  return clone;
}

void Cure::use(ICharacter &target) {
  std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}
