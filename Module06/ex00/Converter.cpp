/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 13:00:23 by smun              #+#    #+#             */
/*   Updated: 2021/12/12 10:21:16 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"
#include <iostream>
#include <cmath>

Converter::~Converter() {}

Converter::Converter(const char* literal)
	: _literal(literal)
	, _typeFlag(0)
{
	parse();
}

Converter::Converter(Converter const& origin)
	: _literal(origin._literal)
	, _typeFlag(origin._typeFlag)
	, _intval(origin._intval)
	, _floatval(origin._floatval)
{
}

Converter& Converter::operator= (Converter const& another)
{
	if (this == &another)
		return *this;
	_literal = another._literal;
	_typeFlag = another._typeFlag;
	_intval = another._intval;
	_floatval = another._floatval;
	return *this;
}

int		Converter::toInt() const
{
	if (!hasTypeFlag(Converter::Type_Integer))
		throw Converter::NotConvertibleException(Converter::Error_Impossible);
	return static_cast<int>(_intval);
}

float	Converter::toFloat() const
{
	if (!hasTypeFlag(Converter::Type_Float))
		throw Converter::NotConvertibleException(Converter::Error_Impossible);
	return static_cast<float>(_floatval);
}

double	Converter::toDouble() const
{
	if (!hasTypeFlag(Converter::Type_Double))
		throw Converter::NotConvertibleException(Converter::Error_Impossible);
	return static_cast<double>(_doubleval);
}

char	Converter::toChar() const
{
	if (!hasTypeFlag(Converter::Type_Integer))
		throw Converter::NotConvertibleException(Converter::Error_Impossible);
	if (!hasTypeFlag(Converter::Type_Displayable))
		throw Converter::NotConvertibleException(Converter::Error_NonDisplayable);
	return static_cast<char>(_intval);
}

void	Converter::purgeQuotes(std::string& literal)
{
	if (literal.length() != 3)
		return;
	if (literal.front() != '\'')
		return;
	if (literal.back() != '\'')
		return;
	literal[0] = literal[1];
	literal.erase(1);
	_typeFlag |= Type_Character;
}

void	Converter::parse()
{
	unsigned int type = Type_None;

	purgeQuotes(_literal);
	if (hasTypeFlag(Type_Character))
		_literal = std::to_string(static_cast<int>(_literal.front()));
	try
	{
		_intval = std::stoi(_literal);
		if (std::isprint(_intval))
			type |= Type_Displayable;
		type |= Type_Integer;
	}
	catch (std::exception& ex)
	{
	}
	try
	{
		_floatval = std::stof(_literal);
		type |= Type_Float;
	}
	catch (std::exception& ex)
	{
	}
	try
	{
		_doubleval = std::stod(_literal);
		type |= Type_Double;
	}
	catch (std::exception& ex)
	{
	}
	_typeFlag |= type;
}

bool	Converter::hasTypeFlag(unsigned int flag) const
{
	return ((_typeFlag & flag) != 0);
}

bool	Converter::hasFractional() const
{
	return (_doubleval - static_cast<int>(_doubleval)) != 0;
}

Converter::NotConvertibleException::~NotConvertibleException() throw() {}
Converter::NotConvertibleException::NotConvertibleException(NotConvertibleException const& origin)
	: _errorType(origin._errorType) {}
Converter::NotConvertibleException::NotConvertibleException(int errorType)
	: _errorType(errorType) {}

const char*	Converter::NotConvertibleException::what() const throw()
{
	if (_errorType == Converter::Error_NonDisplayable)
		return "Non displayable";
	return "impossible";
}
