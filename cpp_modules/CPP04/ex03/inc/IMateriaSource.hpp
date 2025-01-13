/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 20:25:51 by dsamuel           #+#    #+#             */
/*   Updated: 2025/01/09 20:26:05 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
#define IMATERIASOURCE_HPP

#include "AMateria.hpp"

class AMateria;

class IMateriaSource
{
 public:
 virtual ~IMateriaSource() {}
 virtual void learnMateria(AMateria*) = 0;
 virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif //IMATERIASOURCE_HPP