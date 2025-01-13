/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 20:14:48 by dsamuel           #+#    #+#             */
/*   Updated: 2025/01/09 20:15:03 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main() {
  const Animal *j = new Dog();
  const Animal *i = new Cat();
  std::cout << j->getType() << " " << std::endl;
  std::cout << i->getType() << " " << std::endl;
  i->makeSound(); // Outputs the cat sound!
  j->makeSound();

  // Additional tests with WrongCat
  const WrongAnimal *wrongCat = new WrongCat();
  wrongCat->makeSound();

  delete j;
  delete i;
  delete wrongCat;

  const Animal *testA = new Dog();
  const Animal *testB = new Cat();
  testA->makeSound();
  testB->makeSound();
  std::cout << testA->getType() << " " << std::endl;
  delete testA; // should not create a leak
  delete testB;

  // const Animal *testAnimal = new Animal();
  // Animal class is now abstract and cannot be instaciated
  return 0;
}
