/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 18:03:19 by smun              #+#    #+#             */
/*   Updated: 2021/12/03 11:45:44 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

#define RED "\e[31m"
#define GREEN "\e[32m"
#define YELLOW "\e[33m"
#define RESET "\e[0m"

#define CYAN "\e[36m"
#define BLUE "\e[34m"
#define PURPLE "\e[35m"

int main()
{
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

	ShrubberyCreationForm scform1 = ShrubberyCreationForm("anywhere");
	std::cout << YELLOW" >> ( [ShrubberyCreationForm, anywhere] [정모씨, 140급 공무원] 문서가 서명되지 않아 실패할 것으로 기대. )" << RESET << std::endl;
	bureaucrat_grade140.executeForm(scform1);
	std::cout << std::endl;

	ShrubberyCreationForm scform2 = ShrubberyCreationForm("anywhere");
	std::cout << YELLOW" >> ( [ShrubberyCreationForm, anywhere] [정모씨, 140급 공무원] 서명은 할 수 있으나, 등급이 부족해 실행할 수 없어 실패할 것으로 기대. )" << RESET << std::endl;
	bureaucrat_grade140.signForm(scform2);
	bureaucrat_grade140.executeForm(scform2);
	std::cout << std::endl;

	ShrubberyCreationForm scform3 = ShrubberyCreationForm("/dev/");
	std::cout << YELLOW" >> ( [ShrubberyCreationForm, /dev/], [송모씨, 45급 공무원] 해당 타겟에는 파일을 생성할 수 없어 실패할 것으로 기대. )" << RESET << std::endl;
	bureaucrat_grade45.signForm(scform3);
	bureaucrat_grade45.executeForm(scform3);
	std::cout << std::endl;

	ShrubberyCreationForm scform4 = ShrubberyCreationForm("home");
	std::cout << GREEN" >> ( [ShrubberyCreationForm, home], [송모씨, 45급 공무원] home_shrubbery 경로에 나무가 그려진 파일이 작성될 것으로 기대. )" << RESET << std::endl;
	bureaucrat_grade45.signForm(scform4);
	bureaucrat_grade45.executeForm(scform4);
	std::cout << std::endl;

	RobotomyRequestForm rbform1 = RobotomyRequestForm("Cyberman");
	std::cout << GREEN" >> ( [RobotomyRequestForm, Cyberman] [송모씨, 45급 공무원] 타겟 Cyberman을 50% 확률로 Robotomized. )" << RESET << std::endl;
	bureaucrat_grade45.signForm(rbform1);
	bureaucrat_grade45.executeForm(rbform1);
	std::cout << std::endl;

	RobotomyRequestForm rbform2 = RobotomyRequestForm("Bugman");
	std::cout << GREEN" >> ( [RobotomyRequestForm, Bugman] [유모씨, 5급 공무원] 타겟 Bugman을 50% 확률로 Robotomized. )" << RESET << std::endl;
	bureaucrat_grade5.signForm(rbform2);
	bureaucrat_grade5.executeForm(rbform2);
	std::cout << std::endl;

	PresidentialPardonForm ppform1 = PresidentialPardonForm("Dovahkiin");
	std::cout << GREEN" >> ( [PresidentialPardonForm, Dovahkiin] [유모씨, 5급 공무원] 타겟 Dovahkiin을 사면. )" << RESET << std::endl;
	bureaucrat_grade5.signForm(ppform1);
	bureaucrat_grade5.executeForm(ppform1);
	std::cout << std::endl;

	return 0;
}
