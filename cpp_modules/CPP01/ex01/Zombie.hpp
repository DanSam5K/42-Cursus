/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 18:56:53 by dsamuel           #+#    #+#             */
/*   Updated: 2024/12/13 18:57:42 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX01_ZOMBIE_HPP
#define EX01_ZOMBIE_HPP

#include <iostream>

class Zombie {
private:
    std::string name;
    
public:
    void announce(void);
    
    void setName(const std::string &InputName);
    
    ~Zombie();
};

Zombie *zombieHorde(int N, std::string name);

#endif //EX01_ZOMBIE_HPP