/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 18:59:18 by dsamuel           #+#    #+#             */
/*   Updated: 2025/01/07 18:59:42 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string &Name) : ClapTrap(Name) {
  std::cout << "[FragTrap] Default constructor called\n";
  EnergyPoints_ = 100;
  AttackDamage_ = 30;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other) {
  std::cout << "[FragTrap] Copy constructor called\n";
}

FragTrap &FragTrap::operator=(const FragTrap &other) {
  std::cout << "[FragTrap] Copy assignment operator called\n";
  if (this == &other)
    return *this;
  this->Name_ = other.getName();
  this->HitPoints_ = other.getHitPoints();
  this->EnergyPoints_ = other.getEnergyPoints();
  this->AttackDamage_ = other.getAttackDamage();
  return *this;
}

FragTrap::~FragTrap() { std::cout << "[FragTrap] Destructor called\n"; }

void FragTrap::highFivesGuys() {
  std::cout << "[FragTrap] My name is " << getName()
            << " and I am sending a positive highFives for you <3!!";
}
