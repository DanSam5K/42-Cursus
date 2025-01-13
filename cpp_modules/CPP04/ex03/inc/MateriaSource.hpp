/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 20:26:16 by dsamuel           #+#    #+#             */
/*   Updated: 2025/01/09 20:26:20 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

#define SLOTS 4

class IMateriaSource;

class MateriaSource : public IMateriaSource {
private:
  AMateria *learntMaterias_[SLOTS];

public:
  /**
   * @brief Default constructor.
   */
  MateriaSource();
  /**
   * @brief Copy constructor.
   * @param other The other MateriaSource to copy.
   */
  MateriaSource(const MateriaSource &other);
  /**
   * @brief Copy assignment operator.
   * @param other The other MateriaSource to assign.
   * @return A reference to the assigned MateriaSource.
   */
  MateriaSource &operator=(const MateriaSource &other);
  /**
   * @brief Destructor.
   */
  ~MateriaSource();
  /**
   * @brief Copies the Materia passed as a parameter and store it in memory so
   * it can be cloned later.
   * @param materiaToLearn AMateria to learn.
   */
  void learnMateria(AMateria *materiaToLearn);
  /**
   * @brief Creates a copy of a Materia previously learned.
   * @param type The other MateriaSource to assign.
   * @return A new Materia or 0 if type is unknow.
   */
  AMateria *createMateria(std::string const &type);
};

#endif // MATERIASOURCE_HPP
