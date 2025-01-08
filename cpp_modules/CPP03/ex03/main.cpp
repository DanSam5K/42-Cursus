/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 19:07:36 by dsamuel           #+#    #+#             */
/*   Updated: 2025/01/07 19:07:40 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main() {
  DiamondTrap ClassA("Name");

  std::cout << "I am " << ClassA.getName() << std::endl
            << "HitPoints: " << ClassA.getHitPoints() << std::endl
            << "EnergyPoints: " << ClassA.getEnergyPoints() << std::endl
            << "AttackDamage: " << ClassA.getAttackDamage() << std::endl;
  ClassA.attack("Pigeon");
  ClassA.whoAmI();
  return 0;
}
