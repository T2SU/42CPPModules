/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 17:23:08 by smun              #+#    #+#             */
/*   Updated: 2021/11/23 19:28:55 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "WrongCat.hpp"

WrongCat::WrongCat() 
{
	std::cout << "[WrongCat] (Constructed as default)" << std::endl;
	type = "WrongCat";
}

WrongCat::~WrongCat() 
{
	std::cout << "[WrongCat] (Destructed)" << std::endl;
}

WrongCat::WrongCat(WrongCat const &original)
		: WrongAnimal(original) 
{
	std::cout << "[WrongCat] (Constructed as copy)" << std::endl;
}

WrongCat &WrongCat::operator=(WrongCat const &other) 
{
	std::cout << "[WrongCat] (Occurred the assignation)" << std::endl;
	WrongAnimal::operator=(other);
	return *this;
}

void WrongCat::makeSound() const 
{
	std::cout << "[WrongCat] Meow! Meow!" << std::endl;
}
