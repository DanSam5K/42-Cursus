/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 20:10:39 by dsamuel           #+#    #+#             */
/*   Updated: 2025/01/09 20:10:41 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
private:
  Brain *DogBrain;

public:
  /**
   * @brief Default constructor.
   */
  Dog();
  /**
   * @brief Copy constructor.
   * @param other The other Dog to copy.
   */
  Dog(const Dog &other);
  /**
   * @brief Copy assignment operator.
   * @param other The other Dog to assign.
   * @return A reference to the assigned Dog.
   */
  Dog &operator=(const Dog &other);
  /**
   * @brief Destructor.
   */
  ~Dog();
  /**
   * @brief Prints a custom message with a Sound from this class.
   */
  void makeSound() const;
};

#endif // DOG_HPP