/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 17:27:08 by smun              #+#    #+#             */
/*   Updated: 2021/11/23 21:41:45 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include <iostream>

Ice::~Ice()
{
	std::cout << "[Ice] (Destructed)" << std::endl;
}

Ice::Ice()
	: AMateria("ice")
{
	std::cout << "[Ice] (Constructed as default)" << std::endl;
}

Ice::Ice(Ice const& origin)
	: AMateria(origin)
{
	std::cout << "[Ice] (Constructed as copy)" << std::endl;
}

Ice& Ice::operator= (Ice const& another)
{
	std::cout << "[Ice] (Occurred the assignation)" << std::endl;
	if (this == &another)
		return *this;
	type = another.type;
	return *this;
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

AMateria* Ice::clone() const
{
	return new Ice(*this);
}
