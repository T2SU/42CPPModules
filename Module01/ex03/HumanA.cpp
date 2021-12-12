/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 18:39:17 by smun              #+#    #+#             */
/*   Updated: 2021/09/26 18:39:43 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "HumanA.hpp"
#include "Weapon.hpp"

HumanA::HumanA( std::string name, Weapon &weapon )
{
	this->name = name;
	setWeapon(weapon);
}

void	HumanA::attack( void ) const
{
	std::cout << name << " attacks with his " << weapon->getType() << std::endl;
}

void	HumanA::setWeapon( Weapon &weapon )
{
	this->weapon = &weapon;
}
