/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 16:30:35 by smun              #+#    #+#             */
/*   Updated: 2021/12/12 17:25:00 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mutantstack.hpp"
#include <iostream>
#include <list>
#include <deque>
#include <vector>
#include <string>
#include <cxxabi.h>

#define RESET "\e[0m"
#define RED "\e[31m"
#define GREEN "\e[32m"
#define YELLOW "\e[33m"
#define BLUE "\e[34m"

std::string demangle(const char* what)
{
	int status;

	char* name = abi::__cxa_demangle(what, 0, 0, &status);
	std::string str(name);
	delete name;
	return str;
}

template<typename _InputIterator>
static void PrintByIterate(_InputIterator it, _InputIterator ite)
{
	std::cout << YELLOW << demangle(typeid(_InputIterator).name()) << ": " << RESET;
	while (it != ite)
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << RESET << std::endl;
}

template<typename _Tp, typename _Container, _Tp first, _Tp end, _Tp gap>
static void Test()
{
	MutantStack<_Tp, _Container> mstack;
	std::cout << BLUE << "Test of " << demangle(typeid(mstack).name());
	std::cout << RESET << std::endl;

	for (_Tp i = first; i != end; i += gap)
	{
		mstack.push(i);
		std::cout << "Top : " << mstack.top() << std::endl;
	}

	MutantStack<_Tp, _Container> mstack_clone1 = mstack;
	MutantStack<_Tp, _Container> mstack_clone2;
	mstack_clone2 = mstack;
	MutantStack<_Tp, _Container> mstack_clone3 = mstack_clone2;

	typename MutantStack<_Tp, _Container>::iterator it = mstack.begin();
	typename MutantStack<_Tp, _Container>::iterator ite = mstack.end();
	typename MutantStack<_Tp, _Container>::const_iterator cit = mstack_clone1.cbegin();
	typename MutantStack<_Tp, _Container>::const_iterator cite = mstack_clone1.cend();
	typename MutantStack<_Tp, _Container>::reverse_iterator rit = mstack_clone2.rbegin();
	typename MutantStack<_Tp, _Container>::reverse_iterator rite = mstack_clone2.rend();
	typename MutantStack<_Tp, _Container>::const_reverse_iterator crit = mstack_clone3.crbegin();
	typename MutantStack<_Tp, _Container>::const_reverse_iterator crite = mstack_clone3.crend();

	PrintByIterate(it, ite);
	PrintByIterate(cit, cite);
	PrintByIterate(rit, rite);
	PrintByIterate(crit, crite);

	std::cout << "Size: " << mstack_clone3.size() << std::endl;
	for (_Tp i = first; i != end; i += gap)
	{
		std::cout << "BeforePopTop : " << mstack_clone3.top() << ", ";
		mstack_clone3.pop();
		std::cout << "AfterPopSize: " << mstack_clone3.size() << " (Original size: " << mstack.size() << ")" << std::endl;
	}
	std::cout << std::endl;
}

int main()
{
	Test<int, std::list<int>, 0, 3, 1>();
	Test<long, std::deque<long>, LONG_MAX, LONG_MAX - 9L, -3L>();
	Test<char, std::vector<char>, 'a', 'f', static_cast<char>(1)>();
	return 0;
}
