/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 18:33:38 by smun              #+#    #+#             */
/*   Updated: 2021/09/26 18:39:51 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <string>
# include <Weapon.hpp>

class	HumanA
{
public:
	HumanA( std::string name, Weapon &weapon );
	void		attack( void ) const;
	void		setWeapon( Weapon &weapon );
private:
	std::string	name;
	Weapon		*weapon;
};

#endif
