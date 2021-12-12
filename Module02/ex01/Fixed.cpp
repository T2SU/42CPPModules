/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 00:59:30 by smun              #+#    #+#             */
/*   Updated: 2021/09/28 18:37:59 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed( void )
{
	std::cout << "Default constructor called" << std::endl;
	this->value = 0;
}

Fixed::Fixed( const Fixed &fixed )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
	//equivalent to this->operator=(fixed);
}

Fixed::Fixed( const int value )
{
	std::cout << "Int constructor called" << std::endl;
	this->value = value << FRACTIONAL_BITS;
}

/*
** [[IEEE754 single precision floating number:]]
**   seeeeeeemmmmmmmmmmmmmmmmmmmmmmmm
**
** [[Our fixed:]]
**   iiiiiiiiiiiiiiiiiiiiiiiiffffffff
*/

Fixed::Fixed( float const value )
{
	std::cout << "Float constructor called" << std::endl;
	this->value = roundf(value * (1 << FRACTIONAL_BITS));
}

Fixed::~Fixed( void )
{
	std::cout << "Destructor called" << std::endl;
}

Fixed	&Fixed::operator=( Fixed const &fixed )
{
	std::cout << "Assignation operator called" << std::endl;
	this->value = fixed.value;
	return (*this);
}

int		Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->value;
}

void	Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called" << std::endl;
	this->value = raw;
}

float	Fixed::toFloat( void ) const
{
	return (value / (float)(1 << FRACTIONAL_BITS));
}

int		Fixed::toInt( void ) const
{
	return this->value >> FRACTIONAL_BITS;
}

std::ostream	&operator<<( std::ostream &ostream, Fixed const &fixed )
{
	ostream << fixed.toFloat();
	return ostream;
}
