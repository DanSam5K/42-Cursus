/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:10:25 by dsamuel           #+#    #+#             */
/*   Updated: 2025/01/03 15:51:34 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main() {
    Point a(0, 0);
    Point b(10, 0);
    Point c(5, 10);
    Point point(5, 5);
    
    Point point1(5, 5); // Inside the triangle
    Point point2(0, 0); // On the vertex
    Point point3(15, 5); // Outside the triangle

    if (bsp(point1, point2, point3, point))
        std::cout << "The point is inside the triangle." << std::endl;
    else
        std::cout << "The point is outside the triangle." << std::endl;

    return 0;
}
