/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 00:52:35 by smun              #+#    #+#             */
/*   Updated: 2021/09/28 18:37:34 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class	Fixed
{
public:
	Fixed( void );
	Fixed( Fixed const &fixed );
	virtual ~Fixed( void );
	Fixed	&operator=( Fixed const &fixed );
	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
private:
	int		value;
	static const int	FRACTIONAL_BITS = 8;
};

#endif
