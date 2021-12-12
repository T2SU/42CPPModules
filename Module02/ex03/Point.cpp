/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 03:27:30 by smun              #+#    #+#             */
/*   Updated: 2021/09/28 18:43:29 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point( void )
{
}

Point::Point( Point const &point )
	: x(Fixed(point.x.toFloat())), y(Fixed(point.y.toFloat()))
{
}

Point::Point( float const x, float const y )
	: x(Fixed(x)), y(Fixed(y))
{
}

Point::~Point( void )
{
}

Point	&Point::operator=( Point const &point )
{
	(void)point;
	return (*this);
}

Fixed	Point::getX( void ) const
{
	return x;
}

Fixed	Point::getY( void ) const
{
	return y;
}

bool	Point::operator==( Point const &other ) const
{
	return getX() == other.getX() && getY() == other.getY();
}

bool	Point::operator!=( Point const &other ) const
{
	return getX() != other.getX() || getY() != other.getY();
}

std::ostream	&operator<<( std::ostream &ostream, Point const &point )
{
	ostream << "(" << point.getX() << ", " << point.getY() << ")";
	return ostream;
}
