/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 18:39:17 by smun              #+#    #+#             */
/*   Updated: 2021/09/27 20:09:18 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB( std::string name )
{
	this->name = name;
	this->weapon = NULL;
}

void	HumanB::attack( void ) const
{
	if (weapon != NULL)
		std::cout << name << " attacks with his " << weapon->getType() << std::endl;
	else
		std::cout << name << " tried to attack. but no weapon!" << std::endl;
}

void	HumanB::setWeapon( Weapon &weapon )
{
	this->weapon = &weapon;
}
