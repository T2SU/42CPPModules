/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 19:42:54 by smun              #+#    #+#             */
/*   Updated: 2021/09/20 21:48:53 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# ifndef MAX_CONTACTS
#  define MAX_CONTACTS 8
# endif

# include <Contact.hpp>

class	PhoneBook
{
public:
	PhoneBook(): index(0) {}
	void	Add();
	void	Search() const;
private:
	int		index;
	Contact	contacts[MAX_CONTACTS];
	bool	PrintAll() const;
};

#endif
