/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 04:30:35 by smun              #+#    #+#             */
/*   Updated: 2021/09/27 20:06:25 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie( std::string name )
{
	this->name = name;
}

Zombie::~Zombie()
{
	std::cout << RED"(Zombie " << name << " has been removed.)"RESET << std::endl;
}

void	Zombie::announce( void ) const
{
	std::cout << GREEN"<" << name << "> BraiiiiiiinnnzzzZ..."RESET << std::endl;
}

