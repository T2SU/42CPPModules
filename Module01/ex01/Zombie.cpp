/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 04:30:35 by smun              #+#    #+#             */
/*   Updated: 2021/09/27 20:06:30 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie( void )
{
}

Zombie::~Zombie()
{
	std::cout << RED"(Zombie " << name << " has been removed.)"RESET << std::endl;
}

void	Zombie::setName( std::string name )
{
	this->name = name;
}

void	Zombie::announce( void ) const
{
	std::cout << GREEN"<" << name << "> BraiiiiiiinnnzzzZ..."RESET << std::endl;
}

