/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 14:03:37 by smun              #+#    #+#             */
/*   Updated: 2021/12/02 15:47:31 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat::Bureaucrat(std::string const& name, int grade)
	: _name(name)
{
	setGrade(grade);
}

Bureaucrat::Bureaucrat(Bureaucrat const& origin)
{
	_name = origin.getName();
	setGrade(origin.getGrade());
}

Bureaucrat&	Bureaucrat::operator= (Bureaucrat const& another)
{
	if (this == &another)
		return *this;
	_name = another.getName();
	setGrade(another.getGrade());
	return *this;
}

void	Bureaucrat::setGrade(int grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException(grade);
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException(grade);
	_grade = grade;
}

int	Bureaucrat::getGrade() const
{
	return _grade;
}

std::string const&	Bureaucrat::getName() const
{
	return _name;
}

void	Bureaucrat::incGrade()
{
	setGrade(_grade - 1);
}

void	Bureaucrat::decGrade()
{
	setGrade(_grade + 1);
}

Bureaucrat::GradeTooHighException::GradeTooHighException(int grade)
	: _grade(grade)
{
}


Bureaucrat::GradeTooLowException::GradeTooLowException(int grade)
	: _grade(grade)
{
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	static char buffer[64];

	std::string str;
	str += "Bureaucrat's grade ";
	str += std::to_string(_grade);
	str += " is too high.";
	std::size_t size = str.copy(buffer, sizeof(buffer) - 1);
	buffer[size] = '\0';
	return buffer;
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	static char buffer[64];

	std::string str;
	str += "Bureaucrat's grade ";
	str += std::to_string(_grade);
	str += " is too low.";
	std::size_t size = str.copy(buffer, sizeof(buffer) - 1);
	buffer[size] = '\0';
	return buffer;
}

std::ostream	&operator<<(std::ostream &ostream, Bureaucrat const &bureaucrat)
{
	ostream << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return ostream;
}
