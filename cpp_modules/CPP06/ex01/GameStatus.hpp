/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:40:19 by dsamuel           #+#    #+#             */
/*   Updated: 2025/04/23 15:50:14 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX01_DATA_HPP
#define EX01_DATA_HPP

struct GameStatus {
    int level;
    int health;
    int score;
    bool isCompleted;
    bool bossDefeated; 
};

#endif