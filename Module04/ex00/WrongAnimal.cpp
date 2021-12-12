/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 17:22:56 by smun              #+#    #+#             */
/*   Updated: 2021/11/23 19:28:55 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() 
{
	std::cout << "[WrongAnimal] (Constructed as default)" << std::endl;
	type = "UNKNOWN";
}

WrongAnimal::~WrongAnimal() 
{
	std::cout << "[WrongAnimal] (Destructed)" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &original) 
{
	std::cout << "[WrongAnimal] (Constructed as copy)" << std::endl;
	*this = original;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &other) 
{
	std::cout << "[WrongAnimal] (Occurred the assignation)" << std::endl;
	if (this == &other)
		return *this;
	type = other.type;
	return *this;
}

void WrongAnimal::makeSound() const 
{
	std::cout << "[WrongAnimal] (NO SOUND)" << std::endl;
}

std::string const &WrongAnimal::getType() const 
{
	return type;
}
