/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 00:52:35 by smun              #+#    #+#             */
/*   Updated: 2021/09/28 18:39:46 by smun             ###   ########.fr       */
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
private:
	int		value;
	static const int	FRACTIONAL_BITS = 8;
};

std::ostream	&operator<<( std::ostream &ostream, Fixed const &fixed );

#endif
