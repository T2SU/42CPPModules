/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 19:45:13 by smun              #+#    #+#             */
/*   Updated: 2021/09/20 23:13:58 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "PhoneBook.hpp"

void	PhoneBook::Add()
{
	Contact	contact(index);

	std::cout << "first name? ";
	if (!std::getline(std::cin, contact.first_name))
		return;
	std::cout << "last name? ";
	if (!std::getline(std::cin, contact.last_name))
		return;
	std::cout << "nickname? ";
	if (!std::getline(std::cin, contact.nickname))
		return;
	std::cout << "phone number? ";
	if (!std::getline(std::cin, contact.phone_number))
		return;
	std::cout << "darkest secret? ";
	if (!std::getline(std::cin, contact.darkest_secret))
		return;
	contacts[(index++) % MAX_CONTACTS] = contact;
	std::cout << "Added entry." << std::endl;
}

static void	print_header()
{
	std::cout << std::setw(10) << std::setfill(' ') << "Index" << '|';
	std::cout << std::setw(10) << std::setfill(' ') << "First Name" << '|';
	std::cout << std::setw(10) << std::setfill(' ') << "Last Name" << '|';
	std::cout << std::setw(10) << std::setfill(' ') << "NickName" << std::endl;

	std::cout << std::setw(11) << std::setfill('-') << '+';
	std::cout << std::setw(11) << std::setfill('-') << '+';
	std::cout << std::setw(11) << std::setfill('-') << '+';
	std::cout << std::setw(11) << std::setfill('-');
	std::cout << ' ' << std::endl;
}

bool	PhoneBook::PrintAll() const
{
	if (contacts[0].IsEmpty())
	{
		std::cerr << "Empty contact." << std::endl;
		return false;
	}
	print_header();
	for (int i = 0; i < MAX_CONTACTS; i++)
	{
		const Contact	&contact = contacts[i];
		if (contact.IsEmpty())
			continue;
		contact.Summary();
	}
	return true;
}

static void	clear_cin()
{
	std::cin.clear();
	std::cin.ignore(1000, '\n');
}

static void	failed(const char *err)
{
	std::cerr << err << std::endl;
	clear_cin();
}

void	PhoneBook::Search() const
{
	if (!PrintAll())
		return;
	std::cout << "DESIRED ENTRY's INDEX? ";
	int	index;
	if (!(std::cin >> index))
	{
		failed("Invalid index.");
		return;
	}
	if (index < 0 || index >= this->index)
	{
		failed("Index out of bound.");
		return;
	}
	const Contact	&contact = contacts[index % MAX_CONTACTS];
	if (contact.IsEmpty() || contact.index != index)
	{
		failed("Not exists contact.");
		return;
	}
	contact.Print();
	clear_cin();
}
