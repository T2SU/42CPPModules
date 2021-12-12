/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 18:03:19 by smun              #+#    #+#             */
/*   Updated: 2021/11/30 21:28:50 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

#define RED "\e[31m"
#define GREEN "\e[32m"
#define YELLOW "\e[33m"
#define RESET "\e[0m"

#define CYAN "\e[36m"
#define BLUE "\e[34m"
#define PURPLE "\e[35m"

static void	formAndSign(int grade, std::string const& name, Bureaucrat &bureaucrat);
static void	formAndSignTwice(int grade, std::string const& name, Bureaucrat &bureaucrat);

int main()
{
	Bureaucrat bureaucrat_grade5 = Bureaucrat("유모씨", 5);
	std::cout << PURPLE" >> ( [유모씨, 5급 공무원] 대기중.. )" << RESET << std::endl;
	std::cout << bureaucrat_grade5 << std::endl;
	Bureaucrat bureaucrat_grade50 = Bureaucrat("송모씨", 50);
	std::cout << PURPLE" >> ( [송모씨, 50급 공무원] 대기중.. )" << RESET << std::endl;
	std::cout << bureaucrat_grade50 << std::endl;
	Bureaucrat bureaucrat_grade100 = Bureaucrat("정모씨", 100);
	std::cout << PURPLE" >> ( [정모씨, 100급 공무원] 대기중.. )" << RESET << std::endl;
	std::cout << bureaucrat_grade100 << std::endl;
	std::cout << std::endl;

	std::cout << YELLOW" >> ( [이세계 문서, 0급 문서] 0급은 너무 높아서 생성할 수 없을 것으로 기대. )" << RESET << std::endl;
	formAndSign(0, "이세계 문서", bureaucrat_grade5);
	std::cout << std::endl;

	std::cout << YELLOW" >> ( [시궁창 문서, 151급 문서] 151급은 너무 낮아서 생성할 수 없으로 것을 기대. )" << RESET << std::endl;
	formAndSign(151, "시궁창 문서", bureaucrat_grade5);
	std::cout << std::endl;

	std::cout << GREEN" >> ( [유모씨, 5급 공무원]이 [기밀 문서, 5급] 문서에 서명에 성공할 것으로 기대. )" << RESET << std::endl;
	formAndSign(5, "기밀 문서", bureaucrat_grade5);
	std::cout << std::endl;

	std::cout << YELLOW" >> ( [정모씨, 100급 공무원]이 [기밀 문서, 5급] 문서에 서명을 실패할 것으로 기대. )" << RESET << std::endl;
	formAndSign(5, "기밀 문서", bureaucrat_grade100);
	std::cout << std::endl;

	std::cout << YELLOW" >> ( [송모씨, 50급 공무원]이 [도플갱어 문서, 50급] 같은 문서를 두 번 서명은 할 수 없을 것으로 기대. )" << RESET << std::endl;
	formAndSignTwice(50, "도플갱어 문서", bureaucrat_grade50);
	std::cout << std::endl;

	std::cout << std::endl;

	return 0;
}

static void	formAndSign(int grade, std::string const& name, Bureaucrat &bureaucrat)
{
	try
	{
		Form form = Form(name, grade, grade);
		std::cout << form << std::endl;
		bureaucrat.signForm(form);
		std::cout << form << std::endl;
	}
	catch (std::exception &ex)
	{
		std::cout << RED << ex.what() << RESET << std::endl;
	}
}

static void	formAndSignTwice(int grade, std::string const& name, Bureaucrat &bureaucrat)
{
	try
	{
		Form form = Form(name, grade, grade);
		bureaucrat.signForm(form);
		std::cout << form << std::endl;
		bureaucrat.signForm(form);
		std::cout << form << std::endl;
	}
	catch (std::exception &ex)
	{
		std::cout << RED << ex.what() << RESET << std::endl;
	}
}
