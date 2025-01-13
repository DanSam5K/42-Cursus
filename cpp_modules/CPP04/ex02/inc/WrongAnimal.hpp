/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 20:10:44 by dsamuel           #+#    #+#             */
/*   Updated: 2025/01/09 20:11:07 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal {
protected:
  std::string type;

public:
  /**
   * @brief Default constructor.
   */
  WrongAnimal();
  /**
   * @brief Copy constructor.
   * @param other The other WrongAnimal to copy.
   */
  WrongAnimal(const WrongAnimal &other);
  /**
   * @brief Copy assignment operator.
   * @param other The other WrongAnimal to assign.
   * @return A reference to the assigned WrongAnimal.
   */
  WrongAnimal &operator=(const WrongAnimal &other);
  /**
   * @brief Destructor.
   */
  ~WrongAnimal();
  /**
   * @brief Prints a custom message with a Sound from this class.
   */
  void makeSound() const;
  /**
   * @brief Get the Type of the Animal.
   * @return A std::string with the Type of the animal.
   */
  std::string getType() const;
};

#endif // WRONGANIMAL_HPP