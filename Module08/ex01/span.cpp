/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 10:54:50 by smun              #+#    #+#             */
/*   Updated: 2021/12/12 15:30:25 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"
#include <exception>
#include <algorithm>
#include <string>

Span::Span(unsigned int N)
	: _maxCapacity(N) {}

Span::Span(Span const & origin)
	: _set(origin._set)
	, _maxCapacity(origin._maxCapacity) {}

Span::~Span() {}

Span& Span::operator=(Span const & another)
{
	if (this == &another)
		return *this;
	_set = another._set;
	_maxCapacity = another._maxCapacity;
	return *this;
}

void	Span::addNumber(int number)
{
	if (_set.size() >= _maxCapacity)
		throw std::logic_error("Already full of capacity in current Span.");
	std::pair<std::set<int>::iterator, bool> result = _set.insert(number);
	if (!result.second)
		throw std::logic_error("Duplicated number '" + std::to_string(number) + "' in current Span.");
}

unsigned int	Span::shortestSpan() const
{
	if (_set.size() <= 1)
		throw std::logic_error("Lacked numbers for calculating a span.");

	return static_cast<unsigned int>(::spanAs(_set.begin(), _set.end(), Span::Shortest));
}

unsigned int	Span::longestSpan() const
{
	if (_set.size() <= 1)
		throw std::logic_error("Lacked numbers for calculating a span.");

	return static_cast<unsigned int>(::spanAs(_set.begin(), _set.end(), Span::Longest));
}
