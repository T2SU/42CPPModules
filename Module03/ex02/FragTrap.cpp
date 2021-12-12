/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 02:22:47 by smun              #+#    #+#             */
/*   Updated: 2021/09/29 21:40:48 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "ClapTrap.hpp"
#include "FragTrap.hpp"

FragTrap::FragTrap(std::string const & name)
	: ClapTrap(name)
{
	this->hp = 100;
	this->ep = 100;
	this->attackDamage = 30;
	std::cout << PURPLE << "<New>      FragTrap <" << name << "> was created.\t\t"
				<< "[HP: " << hp << " | EP: " << ep << " | Dam: " << attackDamage << "]" RESET << std::endl;
}

FragTrap::FragTrap(FragTrap const & fragTrap)
{
	*this = fragTrap;
	std::cout << PURPLE << "<New>      FragTrap <" << name << "> (copied) was created.\t"
				<< "[HP: " << hp << " | EP: " << ep << " | Dam: " << attackDamage << "]" RESET << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << PURPLE  << "<Term>     FragTrap <" << name << "> was destroyed.\t\t"
				<< "[HP: " << hp << " | EP: " << ep << " | Dam: " << attackDamage << "]" RESET << std::endl;
}

FragTrap&	FragTrap::operator=(FragTrap const & fragTrap)
{
	this->name = fragTrap.name;
	this->hp = fragTrap.hp;
	this->ep = fragTrap.ep;
	this->attackDamage = fragTrap.attackDamage;
	return *this;
}

void	FragTrap::highFivesGuys()
{
	std::cout << PURPLE << "<HiveFive> FragTrap <" << name << "> wants hive fives! :D\t"
				<< "[HP: " << hp << " | EP: " << ep << " | Dam: " << attackDamage << "]" RESET << std::endl;
}
