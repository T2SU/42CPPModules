/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 18:09:29 by smun              #+#    #+#             */
/*   Updated: 2021/11/23 21:56:33 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "AMateria.hpp"
#include <iostream>
#include <iomanip>

Character::Character()
{
	std::cout << "[Character] (Constructed as default)" << std::endl;
	initInventory();
}

Character::Character(std::string const& name)
{
	std::cout << "[Character] (Constructed as parametered name [" << name << "])" << std::endl;
	initInventory();
	this->name = name;
}

Character::Character(Character const& origin)
{
	std::cout << "[Character] (Constructed as copy)" << std::endl;
	initInventory();
	*this = origin;
}

void Character::initInventory()
{
	for (int i = 0; i < getInventorySize(); i++)
		inventory[i] = NULL;
}

Character::~Character()
{
	std::cout << "[Character] (Destructed)" << std::endl;
	for (int i = 0; i < getInventorySize(); i++)
	{
		AMateria *m = getMateria(i);
		if (m != NULL)
			delete m;
	}
}

Character& Character::operator=(Character const& another)
{
	std::cout << "[Character] (Occurred the assignation)" << std::endl;
	if (this == &another)
		return *this;
	ICharacter::operator=(another);
	name = another.name;
	for (int i = 0; i < getInventorySize(); i++)	
	{
		AMateria *m = another.getMateria(i);
		inventory[i] = (m != NULL) ? m->clone() : NULL;
	}
	return *this;
}

std::string const & Character::getName() const
{
	return name;
}

void Character::equip(AMateria* m)
{
	int free_inv = getFreeInventory();
	if (free_inv == -1)
	{
		std::cout << "[Character] (Tried to learn materia, but no free inventory)" << std::endl;
		return;
	}
	std::cout << "[Character] (Learned Materia [" << m->getType() << "] to inventory [" << free_inv << "])" << std::endl;
	inventory[free_inv] = m;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= getInventorySize())
		return;
	AMateria *m = inventory[idx];
	if (m == NULL)
		return;
	inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	AMateria *m = getMateria(idx);
	if (m == NULL)
		return;
	m->use(target);
}


int Character::getFreeInventory() const
{
	for (int i = 0; i < getInventorySize(); i++)	
	{
		if (inventory[i] == NULL)
			return i;
	}
	return -1;
}

int Character::getInventorySize() const
{
	return sizeof(inventory) / sizeof(inventory[0]);
}

AMateria *Character::getMateria(int idx) const
{
	if (idx < 0 || idx >= getInventorySize())
		return NULL;
	return inventory[idx];
}

void Character::printInv() const
{
	std::cout << "* [" << std::setw(10) << getName() << "] : [";
	for (int i = 0; i < getInventorySize(); i++)
	{
		std::cout << std::setw(5);
		AMateria *m = getMateria(i);
		if (m == NULL)
			std::cout << "None";
		else
			std::cout << m->getType();
		if (i + 1 < getInventorySize())
			std::cout << ", ";
	}
	std::cout << "]" << std::endl;
}
