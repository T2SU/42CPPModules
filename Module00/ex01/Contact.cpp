/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 19:40:37 by smun              #+#    #+#             */
/*   Updated: 2021/09/20 21:47:49 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "Contact.hpp"

static void	print_column(const std::string &data)
{
	if (data.length() > 10)
		std::cout << std::setfill(' ') << data.substr(0, 9) << '.';
	else
		std::cout << std::setw(10) << std::setfill(' ') << data;
}

void	Contact::Summary() const
{
	std::cout << std::setw(10) << std::setfill(' ') << index;
	std::cout << '|';
	print_column(first_name);
	std::cout << '|';
	print_column(last_name);
	std::cout << '|';
	print_column(nickname);
	std::cout << std::endl;
}

void	Contact::Print() const
{
	std::cout << " - First Name: " << first_name << std::endl;
	std::cout << " - Last Name: " << last_name << std::endl;
	std::cout << " - NickName: " << nickname << std::endl;
	std::cout << " - Phone Number: " << phone_number << std::endl;
	std::cout << " - Darkest Secret: " << darkest_secret << std::endl;
}
