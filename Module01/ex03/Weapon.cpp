/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 18:35:48 by smun              #+#    #+#             */
/*   Updated: 2021/09/26 18:40:09 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon( std::string weaponType )
{
	setType(weaponType);
}

std::string	&Weapon::getType( void )
{
	return weaponType;
}

void	Weapon::setType( std::string weaponType )
{
	this->weaponType = weaponType;
}
