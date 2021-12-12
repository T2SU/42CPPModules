/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 17:27:23 by smun              #+#    #+#             */
/*   Updated: 2021/11/23 19:30:45 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure : public AMateria
{
public:
	Cure();
	Cure(Cure const& origin);
	virtual ~Cure();
	Cure& operator= (Cure const& origin);

	virtual AMateria* clone() const;
	virtual void use(ICharacter& target);
};

#endif
