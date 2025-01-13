/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 18:51:20 by dsamuel           #+#    #+#             */
/*   Updated: 2025/01/07 18:51:26 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
  ClapTrap MachineA("Roboto");
  ClapTrap MachineB("Roboto");
  MachineA.attack(MachineB.getName());
  MachineB.takeDamage(1000);
  MachineB.attack("Tests");
  return 0;
}
