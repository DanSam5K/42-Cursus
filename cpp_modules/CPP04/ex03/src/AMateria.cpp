/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 20:26:42 by dsamuel           #+#    #+#             */
/*   Updated: 2025/01/09 20:26:52 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() { std::cout << "[AMateria] Default constructor called" << std::endl; }

AMateria::AMateria(std::string const &type) : type_(type) {
  std::cout << "[AMateria] Constructor with parameter type called" << std::endl;
}
AMateria::AMateria(const AMateria &other) {
  (void)other;
  std::cout << "[AMateria] Copy constructor called" << std::endl;
}

AMateria &AMateria::operator=(const AMateria &other) {
  std::cout << "[AMateria] Copy assignment operator called" << std::endl;
  if (this == &other)
    return *this;
  return *this;
}

AMateria::~AMateria() { std::cout << "[AMateria] Destructor called" << std::endl; }

std::string const &AMateria::getType() const { return (this->type_); }

void AMateria::use(ICharacter &target) {
  std::cout << "I shouldn't be able to use this on " << target.getName()
            << std::endl;
}
