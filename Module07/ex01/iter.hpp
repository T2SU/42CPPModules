/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 15:45:52 by smun              #+#    #+#             */
/*   Updated: 2021/12/11 15:57:45 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

template<typename T>
void	iter(T* array, unsigned int length, void(*func)(T const&))
{
	for (unsigned int i = 0; i < length; i++)
		func(array[i]);
}

#endif
