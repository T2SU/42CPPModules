/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 18:06:50 by smun              #+#    #+#             */
/*   Updated: 2021/11/23 21:56:07 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"

class AMateria;

class Character : public ICharacter
{
private:
	void initInventory();
protected:
	std::string name;
	AMateria* inventory[4];
public:
	Character();
	Character(std::string const& name);
	Character(Character const& origin);
	virtual ~Character();
	Character& operator=(Character const& another);
	virtual std::string const & getName() const;
	virtual void equip(AMateria* m);
	virtual void unequip(int idx);
	virtual void use(int idx, ICharacter& target);
	virtual int getInventorySize() const;
	virtual int getFreeInventory() const;
	virtual AMateria *getMateria(int idx) const;
	virtual void printInv() const;
};

#endif
