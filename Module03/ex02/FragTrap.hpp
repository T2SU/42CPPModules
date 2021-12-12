/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 02:11:48 by smun              #+#    #+#             */
/*   Updated: 2021/09/29 18:35:30 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <string>
# include "ClapTrap.hpp"

class	FragTrap : public ClapTrap
{
public:
	FragTrap(std::string const & name);
	FragTrap(FragTrap const & fragTrap);
	virtual		~FragTrap();
	FragTrap&	operator=(FragTrap const & fragTrap);
	void		highFivesGuys();
private:
	FragTrap();
};

#endif
