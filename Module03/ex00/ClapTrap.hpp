/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 00:55:42 by smun              #+#    #+#             */
/*   Updated: 2021/09/29 16:54:06 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>
# define RED "\e[31m"
# define GREEN "\e[32m"
# define YELLOW "\e[33m"
# define CYAN "\e[36m"
# define BLUE "\e[34m"
# define PURPLE "\e[35m"
# define RESET "\e[0m"

class	ClapTrap
{
public:
	ClapTrap(std::string const & name);
	ClapTrap(ClapTrap const & clapTrap);
	virtual		~ClapTrap();
	ClapTrap&	operator=(ClapTrap const & clapTrap);
	void		attack(std::string const & target);
	void		takeDamage(unsigned int amount);
	void		beRepaired(unsigned int amount);
private:
	ClapTrap();

	std::string		name;
	unsigned int	hp;
	unsigned int	ep;
	unsigned int	attackDamage;
};

#endif
