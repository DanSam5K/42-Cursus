/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 16:49:30 by dsamuel           #+#    #+#             */
/*   Updated: 2024/12/13 16:51:58 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
    Zombie *Zombie1 = newZombie("Zombienn");
    Zombie1->announce();
    randomChump("me no zombie");
    delete Zombie1;
}
