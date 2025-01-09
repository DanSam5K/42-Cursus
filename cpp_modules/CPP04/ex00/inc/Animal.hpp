/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 19:06:29 by dsamuel           #+#    #+#             */
/*   Updated: 2025/01/09 19:28:25 by dsamuel          ###   ########.fr       */
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
  explicit Animal();
  Animal(const Animal &other);
  Animal &operator=(const Animal &other);
  
  virtual ~Animal();

  virtual void makeSound() const;
  std::string getType() const;
};

#endif // ANIMAL_HPP