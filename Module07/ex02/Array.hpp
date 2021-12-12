/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 16:01:34 by smun              #+#    #+#             */
/*   Updated: 2021/12/12 17:36:08 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <exception>
# include <string>

template<typename T>
class Array
{
private:
	T*				_data;
	unsigned int	_size;

	void			init(unsigned int size);
	void			copy(Array<T> const& origin);

public:
	Array();
	Array(unsigned int n);
	Array(Array<T> const& origin);
	Array&	operator=(Array<T> const& another);
	virtual ~Array();

	T const& 		operator[](int index) const;
	T&				operator[](int index);
	unsigned int	size() const;
};

template<typename T>
void	Array<T>::init(unsigned int size)
{
	_data = new T[size];
	_size = size;
}

template<typename T>
void	Array<T>::copy(Array<T> const& origin)
{
	init(origin._size);
	for (unsigned int i = 0; i < origin._size; i++)
		_data[i] = origin._data[i];
}

template<typename T>
Array<T>::Array()
{
	init(0);
}

template<typename T>
Array<T>::Array(unsigned int n)
{
	init(n);
}

template<typename T>
Array<T>::Array(Array<T> const& origin)
{
	copy(origin);
}

template<typename T>
Array<T>&	Array<T>::operator=(Array<T> const& another)
{
	if (this == &another)
		return *this;
	delete[] _data;
	copy(another);
	return *this;
}

template<typename T>
Array<T>::~Array()
{
	delete[] _data;
}

template<typename T>
T const& Array<T>::operator[](int index) const
{
	if (index < 0 || static_cast<unsigned int>(index) >= _size)
		throw std::out_of_range("invalid index " + std::to_string(index) + " (array size: " + std::to_string(size()) + ")");
	return _data[index];
}

template<typename T>
T&	Array<T>::operator[](int index)
{
	if (index < 0 || static_cast<unsigned int>(index) >= _size)
		throw std::out_of_range("invalid index " + std::to_string(index) + " (array size: " + std::to_string(size()) + ")");
	return _data[index];
}

template<typename T>
unsigned int	Array<T>::size() const
{
	return _size;
}

#endif
