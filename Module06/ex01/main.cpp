/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 14:17:11 by smun              #+#    #+#             */
/*   Updated: 2021/12/12 10:25:54 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int main()
{
	Data data("smun", 42, "서울특별시 강남구 개포로 416 Innovation Academy 42Seoul", Data::Male);

	uintptr_t raw = ::serialize(&data);
	Data* data2 = ::deserialize(raw);

	std::cout << "data  ptr=" << std::hex << &data << std::endl;
	std::cout << "raw   ptr=" << std::hex << "0x" << raw << std::endl;
	std::cout << "data2 ptr=" << std::hex << data2 << std::endl;
	std::cout << std::dec << std::endl;

	std::cout << "data  Name: " << data.getName() << std::endl;
	std::cout << "data2 Name: " << data2->getName() << std::endl;
	std::cout << std::endl;

	std::cout << "data  Grade: " << data.getGrade() << std::endl;
	std::cout << "data2 Grade: " << data2->getGrade() << std::endl;
	std::cout << std::endl;

	std::cout << "data  Address: " << data.getAddress() << std::endl;
	std::cout << "data2 Address: " << data2->getAddress() << std::endl;
	std::cout << std::endl;

	std::cout << "data  Gender: ";
	if (data.getGender() == Data::Male)
		std::cout << "Male" << std::endl;
	else
		std::cout << "Female" << std::endl;
	std::cout << "data2 Gender: ";
	if (data2->getGender() == Data::Male)
		std::cout << "Male" << std::endl;
	else
		std::cout << "Female" << std::endl;
	std::cout << std::endl;

	return 0;
}
