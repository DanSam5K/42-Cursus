/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 19:56:03 by dsamuel           #+#    #+#             */
/*   Updated: 2025/01/09 19:56:31 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal {
protected:
  std::string type;

public:
  /**
   * @brief Default constructor.
   */
  explicit Animal();
  /**
   * @brief Copy constructor.
   * @param other The other Animal to copy.
   */
  Animal(const Animal &other);
  /**
   * @brief Copy assignment operator.
   * @param other The other Animal to assign.
   * @return A reference to the assigned Animal.
   */
  Animal &operator=(const Animal &other);
  /**
   * @brief Destructor.
   */
  virtual ~Animal();
  /**
   * @brief It will print the approriate sound of the animal.
   */
  virtual void makeSound() const;
  /**
   * @brief Get the type of the animal.
   */
  std::string getType() const;
};

#endif // ANIMAL_HPP