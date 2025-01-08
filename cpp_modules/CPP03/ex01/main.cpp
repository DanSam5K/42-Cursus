/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 18:55:03 by dsamuel           #+#    #+#             */
/*   Updated: 2025/01/07 18:55:06 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
  ClapTrap MachineA("Roboto");
  ClapTrap MachineB("Roboto");
  MachineA.attack(MachineB.getName());
  MachineB.takeDamage(5);
  MachineA.beRepaired(1);

  std::cout << std::endl << std::endl;

  ScavTrap ScavA("Robert");
  ScavA.guardGate();
  ScavA.attack("Pigeon");
  ScavA.takeDamage(10);

  ScavTrap ScavB(ScavA);
  ScavB.beRepaired(5);
  ScavB.beRepaired(1);

  ScavTrap ScavC = ScavA;
  ScavC.takeDamage(100);
  ScavC.takeDamage(100);
  ScavC.attack("Perry");
  return 0;
}