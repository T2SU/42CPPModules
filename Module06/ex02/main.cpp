/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 16:35:51 by smun              #+#    #+#             */
/*   Updated: 2021/12/05 17:16:43 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>

Base * generate(void)
{
	int r;

	do;
	while (!(r = rand() & 3));
	switch (r)
	{
		case 1:
			std::cout << "creates A" << std::endl;
			return new A;
		case 2:
			std::cout << "creates B" << std::endl;
			return new B;
		case 3:
			std::cout << "creates C" << std::endl;
			return new C;
	}
	return nullptr;
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	}
	catch (std::bad_cast &)
	{
	}
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
	}
	catch (std::bad_cast &)
	{
	}
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
	}
	catch (std::bad_cast &)
	{
	}
}

int main()
{
	srand(time(NULL));
	for (int i = 0; i < 10; i++)
	{
		Base* p = generate();
		identify(p);
		identify(*p);
		std::cout << std::endl;
	}
	return 0;
}
