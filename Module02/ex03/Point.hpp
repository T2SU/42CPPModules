/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 03:25:41 by smun              #+#    #+#             */
/*   Updated: 2021/09/28 18:44:01 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include <ostream>
# include "Fixed.hpp"

class	Point
{
public:
	Point( void );
	Point( Point const &point );
	Point( float const x, float const y );
	virtual ~Point( void );
	Point	&operator=( Point const &point );
	Fixed	getX( void ) const;
	Fixed	getY( void ) const;
	bool	operator==( Point const &other ) const;
	bool	operator!=( Point const &other ) const;
private:
	Fixed const	x;
	Fixed const	y;
};

std::ostream	&operator<<( std::ostream &ostream, Point const &point );

bool	bsp( Point const a, Point const b, Point const c, Point const point );

#endif
