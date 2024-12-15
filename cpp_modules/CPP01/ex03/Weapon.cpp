/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 20:59:14 by dsamuel           #+#    #+#             */
/*   Updated: 2024/12/13 21:01:19 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string &typeName){
    type = typeName;
}

const std::string &Weapon::getType() const {
    return type;
}

void Weapon::setType(const std::string &newType) {
    type = newType;
}
