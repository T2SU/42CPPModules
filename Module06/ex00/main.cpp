/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 14:20:44 by smun              #+#    #+#             */
/*   Updated: 2021/12/05 12:57:14 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"
#include <iostream>
#include <iomanip>

int	main(int argc, char* argv[])
{
	if (argc < 2)
	{
		std::cerr << "Not provided argument." << std::endl;
		return 1;
	}
	Converter	conv(argv[1]);

	// Char:
	std::cout << "char: ";
	try
	{
		char c = conv.toChar();
		std::cout << '\'' << c << '\'' << std::endl;
	}
	catch (std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}

	// Int:
	std::cout << "int: ";
	try
	{
		std::cout << conv.toInt() << std::endl;
	}
	catch (std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}

	// Float:
	std::cout << "float: ";
	try
	{
		if (!conv.hasFractional())
			std::cout << std::fixed << std::setprecision(1);
		std::cout << conv.toFloat() << 'f' << std::endl;
	}
	catch (std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}

	// Double:
	std::cout << "double: ";
	try
	{
		if (!conv.hasFractional())
			std::cout << std::fixed << std::setprecision(1);
		std::cout << conv.toDouble() << std::endl;
	}
	catch (std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}
	return 0;
}
