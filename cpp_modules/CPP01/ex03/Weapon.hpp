/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 20:44:25 by dsamuel           #+#    #+#             */
/*   Updated: 2024/12/13 20:58:47 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX03_WEAPON_HPP
#define EX03_WEAPON_HPP

#include <string>
#include <iostream>

class Weapon {
private:
    std::string type;

public:
    Weapon(const std::string &typeName);
    
    const std::string &getType() const;
    
    void setType(const std::string &newType);
};

#endif //EX03_WEAPON_HPP
