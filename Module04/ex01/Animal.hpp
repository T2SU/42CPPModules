/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 15:27:47 by smun              #+#    #+#             */
/*   Updated: 2021/11/23 19:28:55 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <string>
# include "Brain.hpp"

class Animal 
{
protected:
	std::string type;

public:
	Animal();
	virtual ~Animal();
	Animal(Animal const &original);
	Animal &operator= (Animal const &other);
	virtual void makeSound() const;
	std::string const &getType() const;
	virtual Brain *getBrain();
};

#endif //ANIMAL_HPP
