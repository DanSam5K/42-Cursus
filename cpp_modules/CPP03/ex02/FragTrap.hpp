/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 18:59:54 by dsamuel           #+#    #+#             */
/*   Updated: 2025/01/07 18:59:57 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX02_FRAGTRAP_HPP
#define EX02_FRAGTRAP_HPP

#include "ScavTrap.hpp"

class FragTrap : public ClapTrap {
public:
  /**
   * @brief Default constructor.
   */
  explicit FragTrap(const std::string &Name);
  /**
   * @brief Copy constructor.
   * @param other The other FragTrap to copy.
   */
  FragTrap(const FragTrap &other);
  /**
   * @brief Copy assignment operator.
   * @param other The other FragTrap to assign.
   * @return A reference to the assigned FragTrap.
   */
  FragTrap &operator=(const FragTrap &other);
  /**
   * @brief Destructor.
   */
  ~FragTrap();
  /**
   * @brie Positive high fives request on std out.
   */
  void highFivesGuys();
};

#endif // EX02_FRAGTRAP_HPP