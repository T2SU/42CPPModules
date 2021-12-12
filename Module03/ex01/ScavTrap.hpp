/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 02:11:48 by smun              #+#    #+#             */
/*   Updated: 2021/09/29 02:36:40 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <string>
# include "ClapTrap.hpp"

class	ScavTrap : public ClapTrap
{
public:
	ScavTrap(std::string const & name);
	ScavTrap(ScavTrap const & scavTrap);
	virtual		~ScavTrap();
	ScavTrap&	operator=(ScavTrap const & scavTrap);
	void		attack(std::string const & target);
	void		guardGate();
private:
	ScavTrap();
};

#endif
