/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 17:30:43 by smun              #+#    #+#             */
/*   Updated: 2021/11/23 21:39:24 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria()
{
	std::cout << "[AMateria] (Constructed as default)" << std::endl;
}

AMateria::~AMateria()
{
	std::cout << "[AMateria] (Destructed)" << std::endl;
}

AMateria::AMateria(std::string const& type)
{
	std::cout << "[AMateria] (Constructed as parametered type [" << type << "])" << std::endl;
	this->type = type;
}

AMateria::AMateria(AMateria const& origin)
{
	std::cout << "[AMateria] (Constructed as copy)" << std::endl;
	*this = origin;
}

AMateria& AMateria::operator= (AMateria const& another)
{
	std::cout << "[AMateria] (Occurred the assignation)" << std::endl;
	if (this == &another)
		return *this;
	type = another.type;
	return *this;
}

std::string const & AMateria::getType() const
{
	return type;
}

void AMateria::use(ICharacter& target)
{
	(void)target;
}
