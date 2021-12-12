/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 03:39:46 by smun              #+#    #+#             */
/*   Updated: 2021/09/28 18:32:44 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

/*
** Shoelace formula
**  https://en.wikipedia.org/wiki/Shoelace_formula
*/

static	Fixed	area( Point const a, Point const b, Point const c )
{
	Fixed	s1 = c.getX() * (a.getY() - b.getY());
	Fixed	s2 = a.getX() * (b.getY() - c.getY());
	Fixed	s3 = b.getX() * (c.getY() - a.getY());
	Fixed	s = s1 + s2 + s3;

	if (s.toFloat() < 0)
		s = s * Fixed(-1);
	return s;
}

bool	bsp( Point const a, Point const b, Point const c, Point const point )
{
	Fixed	a0 = area(a, b, c);
	Fixed	a1 = area(point, b, c);
	Fixed	a2 = area(a, point, c);
	Fixed	a3 = area(a, b, point);
	Fixed	zero = Fixed(0);

	if (a1 == zero || a2 == zero || a3 == zero)
		return false;
	return (a0 == a1 + a2 + a3);
}
