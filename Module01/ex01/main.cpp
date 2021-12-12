/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 17:59:42 by smun              #+#    #+#             */
/*   Updated: 2021/09/24 18:12:58 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "Zombie.hpp"

void	testZombieHorde( int N, std::string name )
{
	Zombie	*zombies = Zombie::zombieHorde(N, name);
	for (int i = 0; i < N; i++)
		zombies[i].announce();
	delete[] zombies;
}

int	main( void )
{
	testZombieHorde(2, "Karen");
	testZombieHorde(3, "Chica");
	testZombieHorde(4, "Xiaoyu");
	return 0;
}
