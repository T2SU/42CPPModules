/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 17:27:23 by smun              #+#    #+#             */
/*   Updated: 2021/11/23 19:31:07 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice : public AMateria
{
public:
	Ice();
	Ice(Ice const& origin);
	virtual ~Ice();
	Ice& operator= (Ice const& origin);

	virtual AMateria* clone() const;
	virtual void use(ICharacter& target);
};

#endif
