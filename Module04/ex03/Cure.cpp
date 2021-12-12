/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 17:27:08 by smun              #+#    #+#             */
/*   Updated: 2021/11/23 21:41:08 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include <iostream>

Cure::~Cure()
{
	std::cout << "[Cure] (Destructed)" << std::endl;
}

Cure::Cure()
	: AMateria("cure")
{
	std::cout << "[Cure] (Constructed as default)" << std::endl;
}

Cure::Cure(Cure const& origin)
	: AMateria(origin)
{
	std::cout << "[Cure] (Constructed as copy)" << std::endl;
}

Cure& Cure::operator= (Cure const& another)
{
	std::cout << "[Cure] (Occurred the assignation)" << std::endl;
	if (this == &another)
		return *this;
	type = another.type;
	return *this;
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}

AMateria* Cure::clone() const
{
	return new Cure(*this);
}
