/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 19:05:50 by dsamuel           #+#    #+#             */
/*   Updated: 2025/01/07 19:06:07 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(const std::string &Name)
    : ClapTrap(Name), FragTrap(Name), ScavTrap(Name) {
  this->Name_ = Name;
  this->ClapTrap::Name_ = Name + "_clap_name";
  this->HitPoints_ = 100;
  this->EnergyPoints_ = 50;
  this->AttackDamage_ = 30;
  std::cout << "[DiamondTrap] Default constructor called\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap &other)
    : ClapTrap(other.Name_), FragTrap(other.Name_), ScavTrap(other.Name_) {
  this->Name_ = other.Name_;
  std::cout << "[DiamondTrap] Copy constructor called\n";
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other) {
  std::cout << "[DiamondTrap] Copy assignment operator called\n";
  if (this == &other)
    return *this;
  this->Name_ = other.Name_;
  this->ClapTrap::Name_ = other.ClapTrap::Name_;
  this->HitPoints_ = other.HitPoints_;
  this->EnergyPoints_ = other.EnergyPoints_;
  this->AttackDamage_ = other.AttackDamage_;
  return *this;
}

DiamondTrap::~DiamondTrap() {
  std::cout << "[DiamondTrap] Destructor called\n";
}

void DiamondTrap::whoAmI() {
  std::cout << "WhoAmI?\n I am a DiamondTrap Named " << DiamondTrap::Name_
            << " and my parent ClapTrap name is " << ClapTrap::Name_
            << std::endl;
}
