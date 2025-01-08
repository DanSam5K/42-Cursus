/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 18:50:51 by dsamuel           #+#    #+#             */
/*   Updated: 2025/01/08 16:34:03 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX00_CLAPTRAP_HPP
#define EX00_CLAPTRAP_HPP

#include <iostream>
#include <string>

/**
 * @class ClapTrap
 * @brief This class represents a ClapTrap.
 */
class ClapTrap {
  
private:
  std::string Name_;
  int HitPoints_;
  int EnergyPoints_;
  int AttackDamage_;

public:
  explicit ClapTrap(std::string Name);
  
  ClapTrap(const ClapTrap &other);
  
  ClapTrap &operator=(const ClapTrap &other);

  ~ClapTrap();

  std::string getName() const;

  int getHitPoints() const;

  int getEnergyPoints() const;

  int getAttackDamage() const;

  void attack(const std::string &target);

  void takeDamage(unsigned int amount);

  void beRepaired(unsigned int amount);

  bool isFunctional() const;

  void addHitPoints(int amount);

  void addEnergyPoints(int amount);
};

#endif // EX00_CLAPTRAP_HPP
