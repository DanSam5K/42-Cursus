/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 14:36:21 by dsamuel           #+#    #+#             */
/*   Updated: 2025/04/24 14:39:57 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include <iostream>

int main()
{
    int a = 651;
    int b = 6;
    std::cout << "BEFORE SWAP: a = " << a << ", b = " << b << std::endl;
    ::swap(a, b);
    std::cout << "AFTER SWAP: a = " << a << ", b = " << b << std::endl;

    std::cout << "Min of a and b: " << ::min(a, b) << std::endl;
    std::cout << "Max of a and b: " << ::max(a, b) << std::endl;

    float c = 60.6123123f;
    float d = 6.01f;
    std::cout << "BEFORE SWAP: c = " << c << ", d = " << d << std::endl;
    ::swap(c, d);
    std::cout << "AFTER SWAP: c = " << c << ", d = " << d << std::endl;

    std::cout << "Min of c and d: " << ::min(c, d) << std::endl;
    std::cout << "Max of c and d: " << ::max(c, d) << std::endl;

    return 0;
}

//Provided code snippet for testing from the subject:
// int main( void ) {
//   int a = 2;
//   int b = 3;
//   ::swap( a, b );
//   std::cout << "a = " << a << ", b = " << b << std::endl;
//   std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
//   std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
//   std::string c = "chaine1";
//   std::string d = "chaine2";
//   ::swap(c, d);
//   std::cout << "c = " << c << ", d = " << d << std::endl;
//   std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
//   std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
//   return 0;
// }
