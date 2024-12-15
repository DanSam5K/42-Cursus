/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 18:48:39 by dsamuel           #+#    #+#             */
/*   Updated: 2024/12/13 18:58:51 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
    Zombie *Zombie1 = zombieHorde(5, "Zombienn");
    for (int i = 0; i < 5; i++) {
        Zombie1[i].announce();
    }
    delete[] Zombie1;
}
