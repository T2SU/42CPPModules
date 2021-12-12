/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 00:59:30 by smun              #+#    #+#             */
/*   Updated: 2021/09/28 18:42:03 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed( void )
{
	this->value = 0;
}

Fixed::Fixed( Fixed const &fixed )
{
	*this = fixed;
}

Fixed::Fixed( int const value )
{
	this->value = value << FRACTIONAL_BITS;
}

Fixed::Fixed( float const value )
{
	this->value = roundf(value * (1 << FRACTIONAL_BITS));
}

Fixed::~Fixed( void )
{
}

Fixed	&Fixed::operator=( Fixed const &fixed )
{
	this->value = fixed.getRawBits();
	return (*this);
}

int		Fixed::getRawBits( void ) const
{
	return this->value;
}

void	Fixed::setRawBits( int const raw )
{
	this->value = raw;
}

float	Fixed::toFloat( void ) const
{
	return value / (float)(1 << FRACTIONAL_BITS);
}

int		Fixed::toInt( void ) const
{
	return this->value >> FRACTIONAL_BITS;
}

bool	Fixed::operator<(Fixed const &other) const
{
	return getRawBits() < other.getRawBits();
}

bool	Fixed::operator<=(Fixed const &other) const
{
	return getRawBits() <= other.getRawBits();
}

bool	Fixed::operator>( Fixed const &other ) const
{
	return getRawBits() > other.getRawBits();
}

bool	Fixed::operator>=( Fixed const &other ) const
{
	return getRawBits() >= other.getRawBits();
}

bool	Fixed::operator==( Fixed const &other ) const
{
	return getRawBits() == other.getRawBits();
}

bool	Fixed::operator!=( Fixed const &other ) const
{
	return getRawBits() != other.getRawBits();
}

Fixed	Fixed::operator+( Fixed const &other ) const
{
	Fixed	ret;

	ret.setRawBits(getRawBits() + other.getRawBits());
	return ret;
}

Fixed	Fixed::operator-( Fixed const &other ) const
{
	Fixed	ret;

	ret.setRawBits(getRawBits() - other.getRawBits());
	return ret;
}

Fixed	Fixed::operator*( Fixed const &other ) const
{
	Fixed	ret;
	long	f1 = getRawBits(), f2 = other.getRawBits();
	long	mul = f1 * f2;
	long	div = mul / (1 << FRACTIONAL_BITS);

	ret.setRawBits(div);
	return ret;
}

Fixed	Fixed::operator/( Fixed const &other ) const
{
	Fixed	ret;
	long	f1 = getRawBits(), f2 = other.getRawBits();
	long	mul = f1 * (1 << FRACTIONAL_BITS);
	long	div = mul / f2;

	ret.setRawBits(div);
	return ret;
}

Fixed	&Fixed::operator++( void )
{
	setRawBits(getRawBits() + 1);
	return *this;
}

Fixed	Fixed::operator++( int )
{
	Fixed	ret(*this);
	operator++();
	return ret;
}

Fixed	&Fixed::operator--( void )
{
	setRawBits(getRawBits() - 1);
	return *this;
}

Fixed	Fixed::operator--( int )
{
	Fixed	ret(*this);
	operator--();
	return ret;
}

Fixed const	&Fixed::min( Fixed const &a, Fixed const &b )
{
	if (a > b)
		return b;
	return a;
}

Fixed &Fixed::min( Fixed &a, Fixed &b )
{
	if (a > b)
		return b;
	return a;
}

Fixed const	&Fixed::max( Fixed const &a, Fixed const &b )
{
	if (a < b)
		return b;
	return a;
}

Fixed &Fixed::max( Fixed &a, Fixed &b )
{
	if (a < b)
		return b;
	return a;
}

std::ostream	&operator<<( std::ostream &ostream, Fixed const &fixed )
{
	ostream << fixed.toFloat();
	return ostream;
}
