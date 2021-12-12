/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 01:37:59 by smun              #+#    #+#             */
/*   Updated: 2021/09/29 22:02:06 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main()
{
	ScavTrap sv2("FSCVD");
	ClapTrap& ct1 = sv2;
	ct1.takeDamage(100000);
	ct1.attack("Something");
	sv2.guardGate();
	return 0;
}
