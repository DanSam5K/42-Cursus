/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 21:10:38 by dsamuel           #+#    #+#             */
/*   Updated: 2024/12/13 21:12:50 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX03_HUMANA_HPP
#define EX03_HUMANA_HPP

#include "Weapon.hpp"
#include <string>

class HumanA {
private:
    std::string _name;
    Weapon &_weapon;
    
public:
    HumanA(const std::string &name, Weapon &weapon);
    
    void attack();
};

#endif //EX03_HUMANA_HPP