/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 16:52:09 by dsamuel           #+#    #+#             */
/*   Updated: 2024/12/13 18:08:14 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX00_ZOMBIE_HPP
#define EX00_ZOMBIE_HPP

#include <iostream>

class Zombie {
private:
    std::string name;

public:
    void announce(void);
    
    Zombie(const std::string &inputname);
    
    ~Zombie();
};

void randomChump(std::string name);

Zombie *newZombie(std::string name);

#endif //EX00_ZOMBIE_HPP