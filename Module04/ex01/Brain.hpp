/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 18:12:33 by smun              #+#    #+#             */
/*   Updated: 2021/11/23 19:28:55 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <string>

class Brain 
{
private:
	std::string ideas[100];
public:
	Brain();
	virtual ~Brain();
	Brain(Brain const &original);
	Brain &operator=(Brain const &other);
	void putIdea(int idx, char const *idea);
	std::string const &getIdea(int idx) const;
};

#endif //BRAIN_HPP
