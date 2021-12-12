/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 20:19:23 by smun              #+#    #+#             */
/*   Updated: 2021/10/01 19:14:53 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string const & name)
	: ClapTrap(name + "_clap_name"), ScavTrap(name + "_clap_name"), FragTrap(name + "_clap_name")
{
	this->ep = ScavTrap::ep;
	this->hp = FragTrap::hp;
	this->attackDamage = FragTrap::attackDamage;
	this->name = name;
	std::cout << RED << "<New>      DiamondTrap <" << name << "> was created.\t\t"
				<< "[HP: " << hp << " | EP: " << ep << " | Dam: " << attackDamage << "]" RESET << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const & diamondTrap)
{
	*this = diamondTrap;
	std::cout << RED << "<New>      DiamondTrap <" << name << "> (copied) was created.\t"
				<< "[HP: " << hp << " | EP: " << ep << " | Dam: " << attackDamage << "]" RESET << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << RED  << "<Term>     DiamondTrap <" << name << "> was destroyed.\t\t"
				<< "[HP: " << hp << " | EP: " << ep << " | Dam: " << attackDamage << "]" RESET << std::endl;
}

DiamondTrap&	DiamondTrap::operator=(DiamondTrap const & diamondTrap)
{
	ClapTrap::name = diamondTrap.ClapTrap::name;
	this->name = diamondTrap.name;
	this->hp = diamondTrap.hp;
	this->ep = diamondTrap.ep;
	this->attackDamage = diamondTrap.attackDamage;
	return *this;
}

void	DiamondTrap::attack(std::string const & target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI()
{
	std::cout << RED << "<WhoAmI>   DiamondTrap <" << name << "> "
				"= ClapTrap <" << ClapTrap::name << ">" RESET << std::endl;
}
