/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 05:40:57 by smun              #+#    #+#             */
/*   Updated: 2021/09/27 20:06:18 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main( void )
{
	static const char	*names[] =
	{
		"Zombie No.00",
		"Zombie No.01",
		"Zombie No.02",
		"Zombie No.03",
		"Zombie No.04",
		"Zombie No.05",
		"Zombie No.06",
		"Zombie No.07",
		"Zombie No.08",
		"Zombie No.09"
	};
	Zombie	*zombies[5];

	for (int i = 0; i < 5; i++)
	{
		zombies[i] = Zombie::newZombie(names[i]);
		zombies[i]->announce();
	}
	for (int i = 0; i < 5; i++)
		delete zombies[i];
	for (int i = 5; i < 10; i++)
		Zombie::randomChump(names[i]);
	return 0;
}
