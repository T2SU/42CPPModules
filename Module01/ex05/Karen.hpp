/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 18:10:19 by smun              #+#    #+#             */
/*   Updated: 2021/09/26 19:17:24 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KAREN_HPP
# define KAREN_HPP

# include <string>
# define RED "\e[31m"
# define GREEN "\e[32m"
# define YELLOW "\e[33m"
# define CYAN "\e[36m"
# define RESET "\e[0m"

enum	Level
{
	UNDEFINED = -1,
	DEBUG,
	INFO,
	WARNING,
	ERROR,
	NUM
};

class	Karen
{
private:
	std::string	actionMap[NUM];
	void		(Karen::*actions[NUM])( void );
	void		debug( void );
	void		info( void );
	void		warning( void );
	void		error( void );
	Level		getLevel( std::string level );
public:
	Karen();
	void		complain( std::string level );
};

#endif
