/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 01:09:57 by smun              #+#    #+#             */
/*   Updated: 2021/09/28 17:00:49 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

#define RED "\e[31m"
#define GREEN "\e[32m"
#define YELLOW "\e[33m"
#define CYAN "\e[36m"
#define BLUE "\e[34m"
#define RESET "\e[0m"

int		main( void )
{
	{
		Fixed a;
		Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << Fixed::max( a, b ) << std::endl;
	}
	{
		Fixed a;
		Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

		std::cout << std::endl;
		std::cout << CYAN"[[ ** Prefix/Postfix increment ** ]]"RESET << std::endl;
		std::cout << CYAN"a  : "RESET << a << std::endl;
		std::cout << CYAN"++a: "RESET << ++a << std::endl;
		std::cout << CYAN"a  : "RESET << a << std::endl;
		std::cout << CYAN"a++: "RESET << a++ << std::endl;
		std::cout << std::endl;

		std::cout << GREEN"[[ ** Comparison ** ]]"RESET << std::endl;
		std::cout << GREEN"a      : "RESET << a << std::endl;
		std::cout << GREEN"b      : "RESET << b << std::endl;
		std::cout << GREEN"a >  b : "RESET << (a > b) << std::endl;
		std::cout << GREEN"a >= b : "RESET << (a >= b) << std::endl;
		std::cout << GREEN"a <  b : "RESET << (a < b) << std::endl;
		std::cout << GREEN"a <= b : "RESET << (a <= b) << std::endl;
		std::cout << std::endl;

		std::cout << YELLOW"[[ ** Logical comparision ** ]]"RESET << std::endl;
		std::cout << YELLOW"a == b : "RESET << (a == b) << std::endl;
		std::cout << YELLOW"a != b : "RESET << (a != b) << std::endl;
		std::cout << std::endl;

		std::cout << RED"[[ ** Arithmetic ** ]]"RESET << std::endl;
		std::cout << RED"b + a : "RESET << (b + a) << std::endl;
		std::cout << RED"b - a : "RESET << (b - a) << std::endl;
		std::cout << RED"b * a : "RESET << (b * a) << std::endl;
		std::cout << RED"b / a : "RESET << (b / a) << std::endl;
		std::cout << std::endl;

		std::cout << BLUE"[[ ** Min, max ** ]]"RESET << std::endl;
		std::cout << BLUE"Fixed::max( a, b ) : "RESET << Fixed::max( a, b ) << std::endl;
		std::cout << BLUE"Fixed::mix( a, b ) : "RESET << Fixed::min( a, b ) << std::endl;
	}

	return 0;
}
