/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 04:30:43 by smun              #+#    #+#             */
/*   Updated: 2021/09/27 18:30:51 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# define RED "\e[31m"
# define GREEN "\e[32m"
# define YELLOW "\e[33m"
# define CYAN "\e[36m"
# define RESET "\e[0m"

# include <string>

class	Zombie
{
public:
	Zombie( std::string name );
	~Zombie();
	void		announce( void ) const;
	static Zombie	*newZombie( std::string name );
	static void		randomChump( std::string name );
private:
	std::string	name;
};

#endif
