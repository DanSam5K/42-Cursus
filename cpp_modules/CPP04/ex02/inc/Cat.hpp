/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 20:10:15 by dsamuel           #+#    #+#             */
/*   Updated: 2025/01/09 20:10:26 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
private:
  Brain *CatBrain;

public:
  /**
   * @brief Default constructor.
   */
  Cat();
  /**
   * @brief Copy constructor.
   * @param other The other Cat to copy.
   */
  Cat(const Cat &other);
  /**
   * @brief Copy assignment operator.
   * @param other The other Cat to assign.
   * @return A reference to the assigned Cat.
   */
  Cat &operator=(const Cat &other);
  /**
   * @brief Destructor.
   */
  virtual ~Cat();
  /**
   * @brief Prints a custom message with a Sound from this class.
   */
  void makeSound() const;
};

#endif // CAT_HPP