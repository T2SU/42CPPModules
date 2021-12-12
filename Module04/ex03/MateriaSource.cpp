/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 18:58:30 by smun              #+#    #+#             */
/*   Updated: 2021/11/23 21:56:44 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "AMateria.hpp"
#include <iostream>

MateriaSource::MateriaSource()
{
	std::cout << "[MateriaSource] (Constructed as default)" << std::endl;
	initSources();
}

MateriaSource::~MateriaSource()
{
	std::cout << "[MateriaSource] (Destructed)" << std::endl;
	for (int i = 0; i < getSourceSize(); i++)
	{
		AMateria *m = sources[i];
		if (m != NULL)
			delete m;
	}
}

MateriaSource::MateriaSource(MateriaSource const& origin)
{
	std::cout << "[MateriaSource] (Constructed as copy)" << std::endl;
	initSources();
	*this = origin;
}

void MateriaSource::initSources()
{
	for (int i = 0; i < getSourceSize(); i++)
		sources[i] = NULL;
}

MateriaSource& MateriaSource::operator=(MateriaSource const& another)
{
	std::cout << "[MateriaSource] (Occurred the assignation)" << std::endl;
	if (this == &another)
		return *this;
	for (int i = 0; i < getSourceSize(); i++)
	{
		AMateria *m = another.sources[i];
		sources[i] = (m != NULL) ? m->clone() : NULL;
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria* m)
{
	int free_src = getFreeSource();
	if (free_src == -1)
	{
		std::cout << "[MateriaSource] (Tried to learn materia, but no free slot)" << std::endl;
		return;
	}
	sources[free_src] = m->clone();
	std::cout << "[MateriaSource] (Learned Materia [" << m->getType() << "] to slot [" << free_src << "])" << std::endl;
	delete m;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < getSourceSize(); i++)
	{
		AMateria *m = sources[i];
		if (m == NULL)
			continue;
		if (m->getType() == type)
		{
			std::cout << "[MateriaSource] (Found matched type '" << type << "')" << std::endl;
			return m->clone();
		}
	}
	std::cout << "[MateriaSource] (No matched type '" << type << "')" << std::endl;
	return NULL;
}

int MateriaSource::getSourceSize() const
{
	return sizeof(sources) / sizeof(sources[0]);
}

int MateriaSource::getFreeSource() const
{
	for (int i = 0; i < getSourceSize(); i++)
	{
		if (sources[i] == NULL)
			return i;
	}
	return -1;
}
