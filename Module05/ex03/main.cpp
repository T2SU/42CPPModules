/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 16:13:08 by smun              #+#    #+#             */
/*   Updated: 2021/12/03 12:19:15 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

#define RED "\e[31m"
#define GREEN "\e[32m"
#define YELLOW "\e[33m"
#define RESET "\e[0m"

#define CYAN "\e[36m"
#define BLUE "\e[34m"
#define PURPLE "\e[35m"

static void	makeFormAndSignAndExecute(
	Intern & intern,
	std::string const& name,
	std::string const& target,
	Bureaucrat & bureaucrat)
{
	Form* form = NULL;
	try
	{
		form = intern.makeForm(name, target);
		bureaucrat.signForm(*form);
		bureaucrat.executeForm(*form);
	}
	catch (std::exception& ex)
	{
		std::cout << RED << ex.what() << RESET << std::endl;
	}
	delete form;
}

int	main()
{
	Intern intern;

	Bureaucrat bureaucrat_grade5 = Bureaucrat("유모씨", 5);
	std::cout << PURPLE" >> ( [유모씨, 5급 공무원] 대기중.. )" << RESET << std::endl;
	std::cout << bureaucrat_grade5 << std::endl;
	Bureaucrat bureaucrat_grade45 = Bureaucrat("송모씨", 45);
	std::cout << PURPLE" >> ( [송모씨, 45급 공무원] 대기중.. )" << RESET << std::endl;
	std::cout << bureaucrat_grade45 << std::endl;
	Bureaucrat bureaucrat_grade140 = Bureaucrat("정모씨", 140);
	std::cout << PURPLE" >> ( [정모씨, 140급 공무원] 대기중.. )" << RESET << std::endl;
	std::cout << bureaucrat_grade140 << std::endl;
	std::cout << std::endl;

	std::cout << YELLOW" >> ( [weird process, phantasma] 맞는 템플릿이 없어, 실패할 것으로 기대. )" << RESET << std::endl;
	makeFormAndSignAndExecute(intern, "weird process", "phantasma", bureaucrat_grade140);
	std::cout << std::endl;

	std::cout << YELLOW" >> ( [shrubbery creation, house] [정모씨, 140급 공무원] 등급이 부족해 서명은 성공하나, 실행은 실패할 것으로 기대. )" << RESET << std::endl;
	makeFormAndSignAndExecute(intern, "shrubbery creation", "house", bureaucrat_grade140);
	std::cout << std::endl;

	std::cout << GREEN" >> ( [shrubbery creation, house] [송모씨, 45급 공무원] house_shrubbery 파일에 나무 작성에 성공할 것으로 기대. )" << RESET << std::endl;
	makeFormAndSignAndExecute(intern, "shrubbery creation", "house", bureaucrat_grade45);
	std::cout << std::endl;

	std::cout << GREEN" >> ( [robotomy request, computer] [송모씨, 45급 공무원] computer을 Robotomized 시도하는 것에 성공할 것으로 기대. )" << RESET << std::endl;
	makeFormAndSignAndExecute(intern, "robotomy request", "computer", bureaucrat_grade45);
	std::cout << std::endl;

	std::cout << GREEN" >> ( [presidential pardon, someone] [유모씨, 5급 공무원] someone을 사면하는 것에 성공할 것으로 기대. )" << RESET << std::endl;
	makeFormAndSignAndExecute(intern, "presidential pardon", "someone", bureaucrat_grade5);
	std::cout << std::endl;

	return 0;
}
