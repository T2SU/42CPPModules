/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 15:58:29 by smun              #+#    #+#             */
/*   Updated: 2021/11/23 19:28:55 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Dog.hpp"

Dog::Dog() 
{
	std::cout << "[Dog] (Constructed as default)" << std::endl;
	type = "Dog";
}

Dog::~Dog() 
{
	std::cout << "[Dog] (Destructed)" << std::endl;
}

Dog::Dog(Dog const &original)
		: Animal(original) 
{
	std::cout << "[Dog] (Constructed as copy)" << std::endl;
}

Dog &Dog::operator=(Dog const &other) 
{
	std::cout << "[Dog] (Occurred the assignation)" << std::endl;
	Animal::operator=(other);
	return *this;
}

void Dog::makeSound() const 
{
	std::cout << "[Dog] Bark! Bark!" << std::endl;
}
