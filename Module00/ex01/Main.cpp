/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 19:56:57 by smun              #+#    #+#             */
/*   Updated: 2021/09/20 20:37:40 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "PhoneBook.hpp"

int	main()
{
	PhoneBook	phonebook;
	std::string	command;

	while (true)
	{
		std::cout << "COMMAND? [ADD, SEARCH, EXIT]: ";
		if (!std::getline(std::cin, command) || command == "EXIT")
			break;
		if (command == "ADD")
			phonebook.Add();
		if (command == "SEARCH")
			phonebook.Search();
	}
	return 0;
}
