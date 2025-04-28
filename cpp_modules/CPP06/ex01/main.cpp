/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:04:18 by dsamuel           #+#    #+#             */
/*   Updated: 2025/04/23 16:14:55 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main() {
    // Create a sample Data object
    GameStatus original;
    
    original.level = 5;
    original.health = 80;
    original.score = 1500;
    original.isCompleted = false;
    original.bossDefeated = true;

    // Display original data
    std::cout << "Original Data Address: " << &original << std::endl;
    std::cout << "Original Data Content:\n"
              << "Level: " << original.level << "\n"
              << "Health: " << original.health << "\n"
              << "Score: " << original.score << "\n"
              << "Game Complete: " << (original.isCompleted ? "Yes" : "No") << "\n"
              << "Boss Defeated: " << (original.bossDefeated ? "Yes" : "No") << "\n";

    // Serialize the pointer
    uintptr_t raw = Serializer::encode(&original);
    std::cout << "\nSerialized Pointer (uintptr_t): " << raw << std::endl;

    // Deserialize it back
    GameStatus *reconstructed = Serializer::decode(raw);
    std::cout << "\nReconstructed Data Address: " << reconstructed << std::endl;

    // Confirm data integrity
    std::cout << "Reconstructed Data Content:\n"
              << "Level: " << reconstructed->level << "\n"
              << "Health: " << reconstructed->health << "\n"
              << "Score: " << reconstructed->score << "\n"
              << "Game Complete: " << (reconstructed->isCompleted ? "Yes" : "No") << "\n"
              << "Boss Defeated: " << (reconstructed->bossDefeated ? "Yes" : "No") << "\n";

    return 0;
}
