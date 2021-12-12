/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 01:37:59 by smun              #+#    #+#             */
/*   Updated: 2021/09/29 17:03:00 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main()
{
	ClapTrap ct2("Deepthought");
	ct2.takeDamage(1);
	ct2.attack("Moulinette");
	ct2.beRepaired(0x7ffffff0u);
	ct2.beRepaired(0xffffffffu);

	ClapTrap ct3(ct2);
	ct3.takeDamage(1000000);
	return 0;
}
