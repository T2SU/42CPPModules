/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 18:12:38 by smun              #+#    #+#             */
/*   Updated: 2021/11/23 19:28:55 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Brain.hpp"

Brain::Brain() 
{
	std::cout << "[Brain] (Constructed as default)" << std::endl;
}

Brain::~Brain() 
{
	std::cout << "[Brain] (Destructed)" << std::endl;
}

Brain::Brain(Brain const &original) 
{
	std::cout << "[Brain] (Constructed as copy)" << std::endl;
	*this = original;
}

Brain &Brain::operator=(Brain const &other) 
{
	std::cout << "[Brain] (Occurred the assignation)" << std::endl;
	if (this == &other)
		return *this;
	unsigned long length = sizeof(ideas) / sizeof(ideas[0]);
	for (unsigned long i = 0; i < length; i++)
		ideas[i] = other.ideas[i];
	return *this;
}

void Brain::putIdea(int idx, char const *idea) 
{
	ideas[idx] = idea;
}

std::string const &Brain::getIdea(int idx) const 
{
	return ideas[idx];
}
