/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 00:52:35 by smun              #+#    #+#             */
/*   Updated: 2021/09/28 18:42:09 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <ostream>

class	Fixed
{
public:
	Fixed( void );
	Fixed( Fixed const &fixed );
	Fixed( int const value );
	Fixed( float const value );
	virtual ~Fixed( void );
	Fixed	&operator=( Fixed const &fixed );
	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
	float	toFloat( void ) const;
	int		toInt( void ) const;
	bool	operator<( Fixed const &other ) const;
	bool	operator<=( Fixed const &other ) const;
	bool	operator>( Fixed const &other ) const;
	bool	operator>=( Fixed const &other ) const;
	bool	operator==( Fixed const &other ) const;
	bool	operator!=( Fixed const &other ) const;
	Fixed	operator+( Fixed const &other ) const;
	Fixed	operator-( Fixed const &other ) const;
	Fixed	operator*( Fixed const &other ) const;
	Fixed	operator/( Fixed const &other ) const;
	Fixed	&operator++( void ); // prefix ++
	Fixed	operator++( int ); // postfix ++
	Fixed	&operator--( void ); // prefix --
	Fixed	operator--( int ); // postfix --
	static Fixed const	&min( Fixed const &a, Fixed const &b );
	static Fixed const	&max( Fixed const &a, Fixed const &b );
	static Fixed &min( Fixed &a, Fixed &b );
	static Fixed &max( Fixed &a, Fixed &b );
private:
	int		value;
	static const int	FRACTIONAL_BITS = 8;
};

std::ostream	&operator<<( std::ostream &ostream, Fixed const &fixed );

#endif
