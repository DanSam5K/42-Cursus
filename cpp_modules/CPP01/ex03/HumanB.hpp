/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 21:16:45 by dsamuel           #+#    #+#             */
/*   Updated: 2024/12/13 21:18:02 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX03_HUMANB_HPP
#define EX03_HUMANB_HPP

#include "Weapon.hpp"

class HumanB {
private:
    std::string _name;
    Weapon *_weapon;

public:
    HumanB(const std::string &name);
    
    void setWeapon(Weapon &weapon);
    
    void attack();
};

#endif //EX03_HUMANB_HPP