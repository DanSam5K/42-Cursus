/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 21:13:10 by dsamuel           #+#    #+#             */
/*   Updated: 2024/12/13 21:14:04 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(const std::string &name, Weapon &weapon) : _name(name), _weapon(weapon) {}

void HumanA::attack() {
    std::cout << _name << " attacks with his " << _weapon.getType() << std::endl;
}