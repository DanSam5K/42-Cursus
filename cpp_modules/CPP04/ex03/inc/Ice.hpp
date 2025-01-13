/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 20:25:11 by dsamuel           #+#    #+#             */
/*   Updated: 2025/01/09 20:25:27 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class AMateria;

class Ice : public AMateria {
public:
  /**
   * @brief Default constructor.
   */
  Ice();
  /**
   * @brief Copy constructor.
   * @param other The other Ice to copy.
   */
  Ice(const Ice &other);
  /**
   * @brief Copy assignment operator.
   * @param other The other Ice to assign.
   * @return A reference to the assigned Ice.
   */
  Ice &operator=(const Ice &other);
  /**
   * @brief Destructor.
   */
  ~Ice();
  /**
   * @brief Creates a new instance of this type
   * @return New instance of Cure.
   */
  AMateria *clone() const;
  /**
   * @brief Shoot an Ice Bolt at the target
   *  @param target The target of the Ice
   */
  void use(ICharacter &target);
};

#endif // ICE_HPP
