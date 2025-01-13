/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 19:58:13 by dsamuel           #+#    #+#             */
/*   Updated: 2025/01/09 19:58:17 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
public:
  /**
   * @brief Default constructor.
   */
  WrongCat();
  /**
   * @brief Copy constructor.
   * @param other The other WrongCat to copy.
   */
  WrongCat(const WrongCat &other);
  /**
   * @brief Copy assignment operator.
   * @param other The other WrongCat to assign.
   * @return A reference to the assigned WrongCat.
   */
  WrongCat &operator=(const WrongCat &other);
  /**
   * @brief Destructor.
   */
  ~WrongCat();
  /**
   * @brief Prints a custom message with a Sound from this class.
   */
  void makeSound();
};

#endif // WRONGCAT_HPP
