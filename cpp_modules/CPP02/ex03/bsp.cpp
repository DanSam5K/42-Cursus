/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:08:49 by dsamuel           #+#    #+#             */
/*   Updated: 2025/01/03 15:36:46 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Fixed triangleArea(Point const& a, Point const& b, Point const& c) {
    return ((a.getX() * (b.getY() - c.getY())) +
            (b.getX() * (c.getY() - a.getY())) +
            (c.getX() * (a.getY() - b.getY()))).abs() * Fixed(0.5f);
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
    Fixed totalArea = triangleArea(a, b, c);
    Fixed area1 = triangleArea(point, b, c);
    Fixed area2 = triangleArea(a, point, c);
    Fixed area3 = triangleArea(a, b, point);

    return (area1 + area2 + area3 == totalArea) &&
           (area1 != Fixed(0)) && (area2 != Fixed(0)) && (area3 != Fixed(0));
}
