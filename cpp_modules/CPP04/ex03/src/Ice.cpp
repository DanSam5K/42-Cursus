/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 20:27:36 by dsamuel           #+#    #+#             */
/*   Updated: 2025/01/09 20:27:57 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {
  std::cout << "[Ice] Default constructor called" << std::endl;
}

Ice::Ice(const Ice &other) : AMateria(other) {
  std::cout << "[Ice] Copy constructor called" << std::endl;
}

Ice &Ice::operator=(const Ice &other) {
  std::cout << "[Ice] Copy assignment operator called" << std::endl;
  if (this == &other)
    return (*this);
  this->type_ = other.type_;
  return *this;
}

Ice::~Ice() { std::cout << "[Ice] Destructor called" << std::endl; }

AMateria *Ice::clone() const {
  Ice *clone = new Ice;
  return clone;
}

void Ice::use(ICharacter &target) {
  std::cout << "* shoots an ice bolt at " << target.getName() << std::endl;
}
