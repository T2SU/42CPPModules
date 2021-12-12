/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 01:37:59 by smun              #+#    #+#             */
/*   Updated: 2021/09/29 20:37:03 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main()
{
	DiamondTrap dt("DDTVS");

	dt.attack("Robeert");
	dt.takeDamage(10);
	dt.guardGate();
	dt.beRepaired(50);
	dt.highFivesGuys();
	dt.whoAmI();
	return 0;
}
