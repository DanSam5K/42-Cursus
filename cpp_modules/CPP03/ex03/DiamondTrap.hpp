/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 19:06:26 by dsamuel           #+#    #+#             */
/*   Updated: 2025/01/07 19:06:29 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {
private:
  std::string Name_;

public:
  /**
   * @brief Default constructor.
   */
  explicit DiamondTrap(const std::string &Name);
  /**
   * @brief Copy constructor.
   * @param other The other DiamondTrap to copy.
   */
  DiamondTrap(const DiamondTrap &other);
  /**
   * @brief Copy assignment operator.
   * @param other The other DiamondTrap to assign.
   * @return A reference to the assigned DiamondTrap.
   */
  DiamondTrap &operator=(const DiamondTrap &other);
  /**
   * @brief Destructor.
   */
  ~DiamondTrap();
  /**
   * @brief Use the ScavTrap attack function on DiamondTrap class objects.
   */
  using ScavTrap::attack;
  /**
   * @brief Use the ScavTrap attack function on DiamondTrap class objects.
   */
  void whoAmI();
};

#endif // DIAMONDTRAP_HPP