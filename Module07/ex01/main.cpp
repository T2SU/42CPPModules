/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 15:48:47 by smun              #+#    #+#             */
/*   Updated: 2021/12/11 22:07:34 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>
#include <string>

template<typename T>
void	print(T const& val)
{
	std::cout << val << "  ";
}

template<>
void	print<int>(int const& intval)
{
	std::cout << "[int] " << intval << std::endl;
}

template<>
void	print<double>(double const& doubleval)
{
	std::cout << "[double] " << doubleval << std::endl;
}

int	main(void)
{
	int			array0[] = { 42, 4242, 424242, 42424242 };
	double		array1[] = { 4.2, 42.0, 42.42, 42.4242, 4242.4242 };
	std::string	array2[] = { "42", "Fourty-two", "4242", "ft" };

	iter(array0, 4, &print);
	std::cout << std::endl;

	iter(array1, 5, &print);
	std::cout << std::endl;

	iter(array2, 4, &print);
	std::cout << std::endl;

	return 0;
}
