/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 10:48:12 by smun              #+#    #+#             */
/*   Updated: 2021/12/12 15:56:35 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <set>
# include <vector>
# include <functional>
# include <numeric>
# include <algorithm>
# include <exception>

class Span
{
private:
	std::set<int>	_set;
	unsigned int	_maxCapacity;

	Span();

public:
	enum _SpanType { Shortest, Longest };

	Span(unsigned int N);
	Span(Span const & origin);
	Span& operator=(Span const & another);
	virtual ~Span();

	void			addNumber(int number);

	template<typename _InputIterator>
	void			addNumber(_InputIterator begin, _InputIterator end)
	{
		if (_set.size() + std::distance(begin, end) > _maxCapacity)
			throw std::logic_error("Not enough of capacity in current Span.");
		_set.insert(begin, end);
	}

	template<typename _Container>
	void			addNumber(_Container container)
	{
		addNumber(container.cbegin(), container.cend());
	}

	unsigned int	shortestSpan() const;
	unsigned int	longestSpan() const;
};

template<typename _InputIterator>
typename _InputIterator::value_type
spanAs(
	_InputIterator begin,
	_InputIterator end,
	Span::_SpanType spanType)
{
	typedef typename std::iterator_traits<_InputIterator> _It;

	typename _It::difference_type	size = std::distance(begin, end);
	std::vector<typename _It::value_type>	result(size);
	std::adjacent_difference(begin, end, result.begin());

	typename std::vector<typename _It::value_type>::iterator it = result.begin();
	std::advance(it, 1);

	switch (spanType)
	{
	case Span::Shortest:
		return *std::min_element(it, result.end());
	case Span::Longest:
		return std::accumulate(it, result.end(), 0);
	default:
		throw std::logic_error("unknown span type");
	}
}

#endif
