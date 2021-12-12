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
}

Cat::~Cat() 
{
	std::cout << "[Cat] (Destructed)" << std::endl;
}

Cat::Cat(Cat const &original)
		: Animal(original) 
{
	std::cout << "[Cat] (Constructed as copy)" << std::endl;
}

Cat &Cat::operator=(Cat const &other) 
{
	std::cout << "[Cat] (Occurred the assignation)" << std::endl;
	Animal::operator=(other);
	return *this;
}

void Cat::makeSound() const 
{
	std::cout << "[Cat] Meow! Meow!" << std::endl;
}
