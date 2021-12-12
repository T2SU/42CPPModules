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
	brain = new Brain();
}

Dog::~Dog() 
{
	std::cout << "[Dog] (Destructed)" << std::endl;
	delete brain;
}

Dog::Dog(Dog const &original)
		: Animal(original) 
{
	std::cout << "[Dog] (Constructed as copy)" << std::endl;
	brain = new Brain(*original.brain);
}

Dog &Dog::operator=(Dog const &other) 
{
	std::cout << "[Dog] (Occurred the assignation)" << std::endl;
	if (this == &other)
		return *this;
	Animal::operator=(other);
	brain = new Brain(*other.brain);
	return *this;
}

void Dog::makeSound() const 
{
	std::cout << "[Dog] Bark! Bark!" << std::endl;
}

Brain *Dog::getBrain() 
{
	return brain;
}
