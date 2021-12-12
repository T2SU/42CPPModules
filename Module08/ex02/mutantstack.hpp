/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 16:06:23 by smun              #+#    #+#             */
/*   Updated: 2021/12/12 16:39:49 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <deque>

template<typename T, typename _C = std::deque<T> >
class MutantStack : public std::stack<T, _C>
{
public:
	MutantStack(): std::stack<T, _C>() {}
	MutantStack(MutantStack<T, _C> const& origin): std::stack<T, _C>(origin) {}
	virtual ~MutantStack() {}

	MutantStack<T, _C>& operator=(MutantStack<T, _C> const& another)
	{
		if (this == &another)
			return *this;
		std::stack<T, _C>::operator=(another);
		return *this;
	}

	// ** Bidirectional Iterator **
	// iterator
	// const_iterator
	// reverse_iterator
	// const_reverse_iterator

	typedef typename std::stack<T, _C>::container_type::iterator iterator;
	typedef typename std::stack<T, _C>::container_type::const_iterator const_iterator;
	typedef typename std::stack<T, _C>::container_type::reverse_iterator reverse_iterator;
	typedef typename std::stack<T, _C>::container_type::const_reverse_iterator const_reverse_iterator;

	iterator begin() throw() { return this->c.begin(); }
	const_iterator begin() const throw() { return this->c.begin(); }
	iterator end() throw() { return this->c.end(); }
	const_iterator end() const throw() { return this->c.end(); }
	reverse_iterator rbegin() throw() { return this->c.rbegin(); }
	const_reverse_iterator rbegin() const throw() { return this->c.rbegin(); }
	reverse_iterator rend() throw() { return this->c.rend(); }
	const_reverse_iterator rend() const throw() { return this->c.rend(); }
	const_iterator cbegin() const throw() { return this->c.cbegin(); }
	const_iterator cend() const throw() { return this->c.cend(); }
	const_reverse_iterator crbegin() const throw() { return this->c.crbegin(); }
	const_reverse_iterator crend() const throw() { return this->c.crend(); }
};

#endif
