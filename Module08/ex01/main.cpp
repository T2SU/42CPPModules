/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 12:59:05 by smun              #+#    #+#             */
/*   Updated: 2021/12/12 15:57:43 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"
#include <iostream>
#include <exception>
#include <iomanip>
#include <vector>

#define RESET "\e[0m"
#define RED "\e[31m"
#define GREEN "\e[32m"
#define YELLOW "\e[33m"
#define BLUE "\e[34m"

static void T(const char* expected, const char* desc)
{
	std::cout << BLUE << "[Expected Action:";
	std::cout << BLUE << std::setw(7) << expected;
	std::cout << BLUE << "] ";
	std::cout << YELLOW << desc;
	std::cout << RESET << std::endl;
}

int main(void)
{
	//////////////// [[ TEST1 - EXCEPTION (MAX CAPACITY)]] ////////////////

	T("Error", "[Test 1] Exceeded size of max capacity");
	try
	{
		Span span(0);
		span.addNumber(0);
	}
	catch (std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	std::cout << std::endl;

	/////////////////////////////////////////////////////////////////////

	//////////////// [[ TEST2 - EXCEPTION (MAX CAPACITY)]] ////////////////

	T("Error", "[Test 2] Not enough size of max capacity");
	try
	{
		Span span(10);
		std::vector<int> vec;

		for (int i = 0; i < 10; i++)
			vec.push_back(i);

		span.addNumber(-1);
		span.addNumber(vec);
	}
	catch (std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	std::cout << std::endl;

	/////////////////////////////////////////////////////////////////////


	//////////////// [[ TEST3 - EXCEPTION (DUPLICATED)]] ////////////////

	T("Error", "[Test 3] A duplicated element");
	try
	{
		Span span(2);
		span.addNumber(2);
		span.addNumber(2);
	}
	catch (std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	std::cout << std::endl;

	/////////////////////////////////////////////////////////////////////


	/////////// [[ TEST4 - EXCEPTION (LACKED ELEMENT COUNT)]] ///////////

	T("Error", "[Test 4] Lacked elements count - shortestSpan");
	try
	{
		Span span(1);
		std::cout << GREEN << span.shortestSpan() << RESET << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	std::cout << std::endl;

	/////////////////////////////////////////////////////////////////////


	/////////// [[ TEST5 - EXCEPTION (LACKED ELEMENT COUNT)]] ///////////

	T("Error", "[Test 5] Lacked elements count - longestSpan");
	try
	{
		Span span(3);
		std::cout << GREEN << span.longestSpan() << RESET << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	std::cout << std::endl;

	/////////////////////////////////////////////////////////////////////


	/////////////// [[ TEST6 - SUCCESS (shortestSpan)]] ///////////////

	T("OK", "[Test 6] shortestSpan");
	try
	{
		Span span(20001);
		for (int i = -20000; i <= 20000; i += 2)
			span.addNumber(i);
		std::cout << GREEN << span.shortestSpan() << RESET << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	std::cout << std::endl;

	/////////////////////////////////////////////////////////////////////


	//////////////// [[ TEST7 - SUCCESS (longestSpan)]] ////////////////

	T("OK", "[Test 7] longestSpan");
	try
	{
		Span span(20001);
		for (int i = -20000; i <= 20000; i += 2)
			span.addNumber(i);
		std::cout << GREEN << span.longestSpan() << RESET << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	std::cout << std::endl;

	/////////////////////////////////////////////////////////////////////


	////////////// [[ TEST8 - SUCCESS (COPY CONSTRUCTOR)]] //////////////

	T("OK", "[Test 8] Copy constructor (shortestSpan, longestSpan)");
	try
	{
		Span span(20001);
		for (int i = -20000; i <= 20000; i += 2)
			span.addNumber(i);
		Span copy = span;
		std::cout << GREEN << copy.shortestSpan() << RESET << std::endl;
		std::cout << GREEN << copy.longestSpan() << RESET << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	std::cout << std::endl;

	/////////////////////////////////////////////////////////////////////


	///////////// [[ TEST9 - SUCCESS (ASSIGNMENT OPERATOR)]] /////////////

	T("OK", "[Test 9] Assignment operator (shortestSpan, longestSpan)");
	try
	{
		Span span(20001);

		for (int i = -20000; i < 0; i += 2)
			span.addNumber(i);

		Span copy(0);
		copy = span;

		std::vector<int> vec;
		for (int i = 0; i <= 20000; i += 2)
			vec.push_back(i);

		copy.addNumber(vec);

		std::cout << GREEN << copy.shortestSpan() << RESET << std::endl;
		std::cout << GREEN << copy.longestSpan() << RESET << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	std::cout << std::endl;

	/////////////////////////////////////////////////////////////////////


	////////////// [[ TEST10 - SUCCESS (INT_MIN TO INT_MAX)]] //////////////

	T("OK", "[Test 10] INT_MIN ~ INT_MAX - (longestSpan)");
	try
	{
		Span span(5);
		span.addNumber(INT_MIN);
		span.addNumber(INT_MAX);
		span.addNumber(7);
		span.addNumber(-1);
		span.addNumber(5);
		std::cout << GREEN << span.longestSpan() << RESET << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	std::cout << std::endl;

	/////////////////////////////////////////////////////////////////////

	return 0;
}
