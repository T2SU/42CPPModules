/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 13:53:53 by smun              #+#    #+#             */
/*   Updated: 2021/12/05 14:07:04 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::~Data()
{
}

Data::Data(Data const& origin)
	: _name(origin.getName())
	, _grade(origin.getGrade())
	, _address(origin.getAddress())
	, _gender(origin.getGender())
{
}

Data::Data(std::string const& name,
	unsigned int const grade,
	std::string const& address,
	unsigned int const gender)
	: _name(name)
	, _grade(grade)
	, _address(address)
	, _gender(gender)
{
}

std::string const&	Data::getName() const
{
	return _name;
}

int	Data::getGrade() const
{
	return _grade;
}

std::string const&	Data::getAddress() const
{
	return _address;
}

int	Data::getGender() const
{
	return _gender;
}
