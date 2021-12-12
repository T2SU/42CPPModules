/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 15:28:19 by smun              #+#    #+#             */
/*   Updated: 2021/11/23 19:28:55 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"

Animal::Animal() 
{
	std::cout << "[Animal] (Constructed as default)" << std::endl;
	type = "UNKNOWN";
}

Animal::~Animal() 
{
	std::cout << "[Animal] (Destructed)" << std::endl;
}

Animal::Animal(Animal const &original) 
{
	std::cout << "[Animal] (Constructed as copy)" << std::endl;
	*this = original;
}

Animal &Animal::operator=(Animal const &other) 
{
	std::cout << "[Animal] (Occurred the assignation)" << std::endl;
	if (this == &other)
		return *this;
	type = other.type;
	return *this;
}

std::string const &Animal::getType() const 
{
	return type;
}

Brain *Animal::getBrain() 
{
	return NULL;
}
