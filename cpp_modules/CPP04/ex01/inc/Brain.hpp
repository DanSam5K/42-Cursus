/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 19:56:48 by dsamuel           #+#    #+#             */
/*   Updated: 2025/01/09 19:56:50 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>
#include <cstdlib>

#define IDEAS 100

class Brain {
private:
  std::string ideas[IDEAS];

public:
  /**
   * @brief Default constructor.
   */
  Brain();
  /**
   * @brief Copy constructor.
   * @param other The other Brain to copy.
   */
  Brain(const Brain &other);
  /**
   * @brief Copy assignment operator.
   * @param other The other Brain to assign.
   * @return A reference to the assigned Brain.
   */
  Brain &operator=(const Brain &other);
  /**
   * @brief Destructor.
   */
  ~Brain();
  /**
   * @brief Fill the brain with 25 random ideas.
   */
  void RandomIdeas();
};

#endif // BRAIN_HPP