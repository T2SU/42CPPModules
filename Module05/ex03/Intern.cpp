/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 14:23:02 by smun              #+#    #+#             */
/*   Updated: 2021/12/03 13:44:18 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

Intern::Intern() { }
Intern::Intern(Intern const& origin) { (void)origin; }
Intern::~Intern() { }

Intern& Intern::operator= (Intern const& another)
{
	if (this == &another)
		return *this;
	return *this;
}

static Form*	createPresidentialPardonForm(std::string const& name)
{
	return new PresidentialPardonForm(name);
}

static Form*	createRobotomyRequestForm(std::string const& name)
{
	return new RobotomyRequestForm(name);
}

static Form*	createShrubberyCreationForm(std::string const& name)
{
	return new ShrubberyCreationForm(name);
}

Form*	Intern::makeForm(std::string const& name, std::string const& target)
{
	const FormTemplatePair templates[] = {
		FormTemplatePair("presidential pardon", &createPresidentialPardonForm),
		FormTemplatePair("robotomy request", &createRobotomyRequestForm),
		FormTemplatePair("shrubbery creation", &createShrubberyCreationForm)
	};

	for (std::size_t i = 0; i < sizeof(templates) / sizeof(templates[0]); i++)
	{
		if (templates[i].getName() == name)
		{
			Form* ret = templates[i].create(target);
			std::cout << "Intern creates " << ret->getName() << std::endl;
			return ret;
		}
	}
	std::cerr << "Cannot found proper form by name '" << name << "'." << std::endl;
	throw Intern::InvalidFormNameException(name);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////

Intern::FormTemplatePair::~FormTemplatePair()
{
}

Intern::FormTemplatePair::FormTemplatePair(FormTemplatePair const& origin)
	: _name(origin._name)
	, _create(origin._create)
{
}

Intern::FormTemplatePair::FormTemplatePair(std::string const& name, Form*(*create)(std::string const&))
	: _name(name)
	, _create(create)
{
}

std::string const&	Intern::FormTemplatePair::getName() const
{
	return _name;
}

Form*	Intern::FormTemplatePair::create(std::string const& target) const
{
	return _create(target);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////

Intern::InvalidFormNameException::InvalidFormNameException(std::string const& name)
	: _name(name)
{
}

Intern::InvalidFormNameException::~InvalidFormNameException() throw()
{
}

const char* Intern::InvalidFormNameException::what() const throw()
{
	static char buffer[300];

	std::string str;
	str += "Invalid form name '";
	str += _name;
	str += "'";
	std::size_t size = str.copy(buffer, sizeof(buffer) - 1);
	buffer[size] = '\0';
	return buffer;
}
