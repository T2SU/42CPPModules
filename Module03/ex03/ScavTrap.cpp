/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 02:22:47 by smun              #+#    #+#             */
/*   Updated: 2021/09/30 00:14:55 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string const & name)
	: ClapTrap(name)
{
	this->hp = 100;
	this->ep = 50;
	this->attackDamage = 20;
	std::cout << GREEN << "<New>      ScavTrap <" << name << "> was created.\t\t"
				<< "[HP: " << hp << " | EP: " << ep << " | Dam: " << attackDamage << "]" RESET << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const & scavTrap)
{
	*this = scavTrap;
	std::cout << GREEN << "<New>      ScavTrap <" << name << "> (copied) was created.\t"
				<< "[HP: " << hp << " | EP: " << ep << " | Dam: " << attackDamage << "]" RESET << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << GREEN  << "<Term>     ScavTrap <" << name << "> was destroyed.\t\t"
				<< "[HP: " << hp << " | EP: " << ep << " | Dam: " << attackDamage << "]" RESET << std::endl;
}

ScavTrap&	ScavTrap::operator=(ScavTrap const & scavTrap)
{
	this->name = scavTrap.name;
	this->hp = scavTrap.hp;
	this->ep = scavTrap.ep;
	this->attackDamage = scavTrap.attackDamage;
	return *this;
}

void	ScavTrap::attack(std::string const & target)
{
	std::cout << GREEN << "<Attack>   ScavTrap <" << name << "> -> '" << target << "' "
		<< "[" << attackDamage << " DAMAGE]" << RESET << std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout << GREEN << "<Guard>    ScavTrap <" << name << "> is on gate keeper mode.\t"
				<< "[HP: " << hp << " | EP: " << ep << " | Dam: " << attackDamage << "]" RESET << std::endl;
}
