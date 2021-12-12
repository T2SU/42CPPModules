/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 18:33:38 by smun              #+#    #+#             */
/*   Updated: 2021/09/27 20:09:21 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <string>
# include <Weapon.hpp>

class	HumanB
{
public:
	HumanB( std::string name );
	void		attack( void ) const;
	void		setWeapon( Weapon &weapon );
private:
	std::string	name;
	Weapon		*weapon;
};

#endif
