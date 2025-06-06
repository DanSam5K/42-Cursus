/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 20:28:06 by dsamuel           #+#    #+#             */
/*   Updated: 2025/01/09 20:28:21 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

// Own tests | If a block is not equipped and its allocated, it need to be
// freeded at the end
/*int main() {
  AMateria *Ice_1 = new Ice();
  AMateria *Cure_1 = new Cure();
  AMateria *Ice_2 = new Ice();
  AMateria *Ice_3 = new Ice();
  AMateria *Ice_4 = new Ice();
  Cure Cure_2;
  Character Char_3("mario");
  std::cout << "Ice_1 type: " << Ice_1->getType() << std::endl;
  std::cout << "Ice_2 type: " << Ice_2->getType() << std::endl;
  std::cout << "Cure_1 type: " << Cure_1->getType() << std::endl;
  Ice_2->use(Char_3);
  Char_3.equip(Ice_1);
  Char_3.equip(Ice_2);
  Char_3.equip(Ice_3);
  Char_3.equip(Ice_4);
  Char_3.unequip(4);
  Char_3.unequip(3);
  Char_3.equip(Cure_1);
  Char_3.use(0, Char_3);
}*/

// Subject Main test
int main() {
  IMateriaSource *src = new MateriaSource();
  src->learnMateria(new Ice());
  src->learnMateria(new Cure());
  ICharacter *me = new Character("me");
  AMateria *tmp;
  tmp = src->createMateria("ice");
  me->equip(tmp);
  tmp = src->createMateria("cure");
  me->equip(tmp);
  ICharacter *bob = new Character("bob");
  me->use(0, *bob);
  me->use(1, *bob);
  delete bob;
  delete me;
  delete src;
  return 0;
}
