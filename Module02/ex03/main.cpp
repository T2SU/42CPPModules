/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 04:53:42 by smun              #+#    #+#             */
/*   Updated: 2021/09/28 18:42:54 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

static void	draw(Point const &a, Point const &b, Point const &c, Point const &point)
{
	Fixed	maxX, maxY;

	maxX = Fixed::max(Fixed::max(Fixed::max(a.getX(), b.getX()), c.getX()), point.getX());
	maxY = Fixed::max(Fixed::max(Fixed::max(a.getY(), b.getY()), c.getY()), point.getY());
	for (int y = maxY.toInt() + 1; y >= 0 ; y--)
	{
		for (int x = 0; x <= maxX.toInt() + 1; x++)
		{
			Point pt = Point(x, y);
			if (point == pt)
				std::cout << '*';
			else if (a == pt || b == pt || c == pt)
				std::cout << '.';
			else
				std::cout << ' ';
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

static void	test(Point const &a, Point const &b, Point const &c, Point const &point)
{
	bool	res = bsp(a, b, c, point);

	draw(a, b, c, point);
	std::cout << "a      : " << a << std::endl;
	std::cout << "b      : " << b << std::endl;
	std::cout << "c      : " << c << std::endl;
	std::cout << "point  : " << point << std::endl;
	std::cout << "in.tri : " << res << std::endl;
	std::cout << std::endl;
}

int	main( void )
{
	test(Point(5.0f, 2.0f), Point(2.0f, 5.0f), Point(11.0f, 6.0f), Point(7.0f, 4.0f));
	test(Point(2, 6), Point(14, 2), Point(10, 10), Point(7, 6));
	test(Point(2, 6), Point(14, 2), Point(10, 10), Point(6, 3));
	test(Point(2, 6), Point(14, 2), Point(10, 10), Point(2, 6));
	return 0;
}
