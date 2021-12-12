/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 01:01:31 by smun              #+#    #+#             */
/*   Updated: 2021/09/29 21:42:16 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string const & name)
	: name(name),
		hp(10),
		ep(10),
		attackDamage(0)
{
	std::cout << CYAN << "<New>      ClapTrap <" << name << "> was created.\t\t"
				<< "[HP: " << hp << " | EP: " << ep << " | Dam: " << attackDamage << "]" RESET << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const & clapTrap)
{
	*this = clapTrap;
	std::cout << CYAN << "<New>      ClapTrap <" << name << "> (copied) was created.\t\t"
				<< "[HP: " << hp << " | EP: " << ep << " | Dam: " << attackDamage << "]" RESET << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << CYAN  << "<Term>     Claptrap <" << name << "> was destroyed.\t\t"
				<< "[HP: " << hp << " | EP: " << ep << " | Dam: " << attackDamage << "]" RESET << std::endl;
}

ClapTrap&	ClapTrap::operator=(ClapTrap const & clapTrap)
{
	name = clapTrap.name;
	hp = clapTrap.hp;
	ep = clapTrap.ep;
	attackDamage = clapTrap.attackDamage;
	return *this;
}

void	ClapTrap::attack(std::string const & target)
{
	std::cout << CYAN << "<Attack>   ClapTrap <" << name << "> -> '" << target << "' "
		<< "[" << attackDamage << " DAMAGE]" << RESET << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (hp < amount)
		amount = hp;
	hp -= amount;
	std::cout << CYAN << "<Hit>      ClapTrap <" << name << "> [-" << amount << " DAMAGE]\t\t"
				<< "[HP: " << hp << " | EP: " << ep << " | Dam: " << attackDamage << "]" RESET << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (hp + amount < hp)
		amount = ~hp;
	hp += amount;
	std::cout << CYAN << "<Repair>   ClapTrap <" << name << "> [+" << amount << " HP]\t\t"
				<< "[HP: " << hp << " | EP: " << ep << " | Dam: " << attackDamage << "]" RESET << std::endl;
}
