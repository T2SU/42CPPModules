/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 20:15:05 by smun              #+#    #+#             */
/*   Updated: 2021/09/29 21:21:14 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include <string>
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class	DiamondTrap : public ScavTrap, public FragTrap
{
public:
	DiamondTrap(std::string const & name);
	DiamondTrap(DiamondTrap const & diamondTrap);
	virtual	~DiamondTrap();
	DiamondTrap&	operator=(DiamondTrap const & diamondTrap);
	void	attack(std::string const & target);
	void	whoAmI();
private:
	std::string	name;
};

#endif
