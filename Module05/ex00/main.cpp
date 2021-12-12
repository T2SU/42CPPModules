/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 14:58:27 by smun              #+#    #+#             */
/*   Updated: 2021/11/30 18:04:03 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

#define RED "\e[31m"
#define GREEN "\e[32m"
#define YELLOW "\e[33m"
#define RESET "\e[0m"

#define CYAN "\e[36m"
#define BLUE "\e[34m"
#define PURPLE "\e[35m"

static void createAndPrint(std::string const& name, int grade);
static void createAndIncGrade(std::string const& name, int grade);
static void createAndDecGrade(std::string const& name, int grade);

int	main()
{
	std::cout << GREEN" >> ( [박모씨, 10급 공무원] 생성 및 9급으로 승진(incGrade)을 성공할 것으로 기대. )" << RESET << std::endl;
	createAndIncGrade("박모씨", 10);
	std::cout << std::endl;

	std::cout << GREEN" >> ( [조모씨, 140급 공무원] 생성 및 141급으로 강등(decGrade)을 성공할 것으로 기대. )" << RESET << std::endl;
	createAndDecGrade("조모씨", 140);
	std::cout << std::endl;

	std::cout << YELLOW" >> ( [유령, 0급 공무원] -> 0급은 너무 높아서 생성할 수 없을 것으로 기대. )" << RESET << std::endl;
	createAndPrint("유령", 0);
	std::cout << std::endl;

	std::cout << YELLOW" >> ( [전과자, 300급 공무원] -> 300급은 너무 낮아서 생성할 수 없으로 것을 기대. )" << RESET << std::endl;
	createAndPrint("전과자", 300);
	std::cout << std::endl;

	std::cout << GREEN" >> ( [이모씨, 1급 공무원] 생성을 성공할 것으로 기대. )" << RESET << std::endl;
	createAndPrint("이모씨", 1);
	std::cout << std::endl;

	std::cout << GREEN" >> ( [김모씨, 150급 공무원] 생성을 성공할 것으로 기대. )" << RESET << std::endl;
	createAndPrint("김모씨", 150);
	std::cout << std::endl;

	std::cout << YELLOW" >> ( [이모씨, 1급 공무원] 생성은 되나, 0급으로 승진(incGrade) 될 수 없을 것으로 기대. ) )" << RESET << std::endl;
	createAndIncGrade("이모씨", 1);
	std::cout << std::endl;

	std::cout << YELLOW" >> ( [김모씨, 150급 공무원] 생성은 되나, 151급으로 강등(decGrade) 될 수 없을 것으로 기대. )" << RESET << std::endl;
	createAndDecGrade("김모씨", 150);
	std::cout << std::endl;

	return 0;
}

static void createAndPrint(std::string const& name, int grade)
{
	try
	{
		Bureaucrat b = Bureaucrat(name, grade);
		std::cout << RESET << b << RESET << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}
}

static void createAndIncGrade(std::string const& name, int grade)
{
	try
	{
		Bureaucrat b = Bureaucrat(name, grade);
		std::cout << RESET << b << std::endl;
		b.incGrade();
		std::cout << RESET << b << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}
}

static void createAndDecGrade(std::string const& name, int grade)
{
	try
	{
		Bureaucrat b = Bureaucrat(name, grade);
		std::cout << RESET << b << std::endl;
		b.decGrade();
		std::cout << RESET << b << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}
}
