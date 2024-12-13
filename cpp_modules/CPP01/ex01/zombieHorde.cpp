/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 18:57:53 by dsamuel           #+#    #+#             */
/*   Updated: 2024/12/13 18:58:00 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name) {
    Zombie *zombieHorde = new Zombie[N];
    for (int i = 0; i < N; i++) {
        zombieHorde[i].setName(name);
    }
    return zombieHorde;
}