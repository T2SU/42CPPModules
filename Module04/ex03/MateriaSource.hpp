/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 18:56:06 by smun              #+#    #+#             */
/*   Updated: 2021/11/23 21:55:47 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <string>
# include "IMateriaSource.hpp"

class AMateria;

class MateriaSource : public IMateriaSource
{
private:
	void initSources();
protected:
	AMateria* sources[4];
public:
	MateriaSource();
	virtual ~MateriaSource();
	MateriaSource(MateriaSource const& origin);
	MateriaSource& operator=(MateriaSource const& another);
	virtual void learnMateria(AMateria*);
	virtual AMateria* createMateria(std::string const & type);
	virtual int getSourceSize() const;
	virtual int getFreeSource() const;
};

#endif
