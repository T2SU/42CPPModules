/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 22:05:32 by smun              #+#    #+#             */
/*   Updated: 2021/12/02 15:48:17 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <fstream>

RobotomyRequestForm::RobotomyRequestForm(std::string const& target)
	: Form("RobotomyRequestForm", 72, 45, target)
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const& origin)
	: Form(origin)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm& RobotomyRequestForm::operator= (RobotomyRequestForm const& another)
{
	if (this == &another)
		return *this;
	Form::operator=(another);
	return *this;
}

void	RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
	(void)executor;
	std::ifstream	rnd("/dev/random", std::ios::in | std::ios::binary);
	char			num;

	if (!rnd)
		throw RobotomyRequestForm::NoRandomSourceException();
	if (!(rnd >> num))
		throw RobotomyRequestForm::RandomSourceAccessException();
	if (num < 0)
		std::cout << "(Whirring sound) " << getTarget() << " has been robotomized!" << std::endl;
	else
		std::cout << "(Whirring sound) Failure! no effect on " << getTarget() << "." << std::endl;
}

const char* RobotomyRequestForm::NoRandomSourceException::what() const throw()
{
	return "Failed to open the random source.";
}

const char* RobotomyRequestForm::RandomSourceAccessException::what() const throw()
{
	return "Failed to read from the random source.";
}
