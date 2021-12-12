/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 22:05:30 by smun              #+#    #+#             */
/*   Updated: 2021/12/02 12:21:48 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(std::string const& target)
	: Form("PresidentialPardonForm", 25, 5, target)
{
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const& origin)
	: Form(origin)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm& PresidentialPardonForm::operator= (PresidentialPardonForm const& another)
{
	if (this == &another)
		return *this;
	Form::operator=(another);
	return *this;
}

void	PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
	(void)executor;
	std::cout << getTarget() << " has been pardoned by Zafod Beeblebrox." << std::endl;
}
