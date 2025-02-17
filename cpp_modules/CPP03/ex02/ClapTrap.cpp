/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 18:57:10 by dsamuel           #+#    #+#             */
/*   Updated: 2025/01/07 18:57:14 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string &Name) {
  std::cout << "[ClapTrap] Default Constructor called\n";
  this->Name_ = Name;
  this->HitPoints_ = 10;
  this->EnergyPoints_ = 10;
  this->AttackDamage_ = 0;
}

ClapTrap::ClapTrap(const ClapTrap &other)
    : HitPoints_(), EnergyPoints_(), AttackDamage_() {
  std::cout << "[ClapTrap] Copy constructor called\n";
  *this = other;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
  std::cout << "[ClapTrap] Copy assignment operator called\n";
  if (this == &other)
    return *this;
  this->Name_ = other.getName();
  this->HitPoints_ = other.getHitPoints();
  this->EnergyPoints_ = other.getEnergyPoints();
  this->AttackDamage_ = other.getAttackDamage();
  return *this;
}

ClapTrap::~ClapTrap() {
  std::cout << "[ClapTrap] Destructor called\n";
}

std::string ClapTrap::getName() const { return (this->Name_); }

int ClapTrap::getHitPoints() const { return (this->HitPoints_); }

int ClapTrap::getEnergyPoints() const { return (this->EnergyPoints_); }
int ClapTrap::getAttackDamage() const { return (this->AttackDamage_); }

void ClapTrap::attack(const std::string &target) {
  if (!this->isFunctional()) {
    std::cout << this->getName() << " can't attack." << std::endl;
    return;
  }
  std::cout << "ClapTrap " << this->getName() << " attacks " << target
            << ", causing " << this->getAttackDamage() << " points of damage !"
            << std::endl;
  addEnergyPoints(-1);
}

void ClapTrap::takeDamage(unsigned int amount) {
  addHitPoints(-(int(amount)));
  std::cout << "OUCH!!! I got a " << amount << " HitDamage." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
  if (!this->isFunctional()) {
    std::cout << this->getName() << " can't be repaired." << std::endl;
    return;
  }
  addHitPoints(int(amount));
  addEnergyPoints(-1);
  std::cout << this->getName() << " himself repaired for " << amount
            << " of HitPoints" << std::endl;
}

bool ClapTrap::isFunctional() const {
  if (getEnergyPoints() > 0 && getHitPoints() > 0)
    return true;
  return false;
}

void ClapTrap::addEnergyPoints(int amount) { this->EnergyPoints_ += amount; }

void ClapTrap::addHitPoints(int amount) { this->HitPoints_ += amount; }
