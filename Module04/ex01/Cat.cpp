/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 17:13:09 by smun              #+#    #+#             */
/*   Updated: 2021/11/23 19:28:55 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Cat.hpp"

Cat::Cat() 
{
	std::cout << "[Cat] (Constructed as default)" << std::endl;
	type = "Cat";
	brain = new Brain();
}

Cat::~Cat() 
{
	std::cout << "[Cat] (Destructed)" << std::endl;
	delete brain;
}

Cat::Cat(Cat const &original)
		: Animal(original) 
{
	std::cout << "[Cat] (Constructed as copy)" << std::endl;
	brain = new Brain(*original.brain);
}

Cat &Cat::operator=(Cat const &other) 
{
	std::cout << "[Cat] (Occurred the assignation)" << std::endl;
	if (this == &other)
		return *this;
	Animal::operator=(other);
	brain = new Brain(*other.brain);
	return *this;
}

void Cat::makeSound() const 
{
	std::cout << "[Cat] Meow! Meow!" << std::endl;
}

Brain *Cat::getBrain() 
{
	return brain;
}
