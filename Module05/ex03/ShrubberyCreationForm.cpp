/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 21:45:39 by smun              #+#    #+#             */
/*   Updated: 2021/12/02 15:48:49 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>
#include <string>

ShrubberyCreationForm::ShrubberyCreationForm(std::string const& target)
	: Form("ShrubberyCreationForm", 145, 137, target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const& origin)
	: Form(origin)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator= (ShrubberyCreationForm const& another)
{
	if (this == &another)
		return *this;
	Form::operator=(another);
	return *this;
}

void	ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
	(void)executor;
	std::string		file = getTarget() + "_shrubbery";
	std::ofstream	ofs(file, std::ios::out | std::ios::trunc);

	if (!ofs)
		throw ShrubberyCreationForm::FileException(file);
	ofs << "         A" << std::endl;
	ofs << "        d$b" << std::endl;
	ofs << "      .d\\$$b." << std::endl;
	ofs << "    .d$i$$\\$$b." << std::endl;
	ofs << "       d$$@b" << std::endl;
	ofs << "      d\\$$$ib" << std::endl;
	ofs << "    .d$$$\\$$$b" << std::endl;
	ofs << "  .d$$@$$$$\\$$ib." << std::endl;
	ofs << "      d$$i$$b" << std::endl;
	ofs << "     d\\$$$$@$b" << std::endl;
	ofs << "  .d$@$$\\$$$$$@b." << std::endl;
	ofs << ".d$$$$i$$$\\$$$$$$b." << std::endl;
	ofs << "        ###" << std::endl;
	ofs << "        ###" << std::endl;
	ofs << "        ###" << std::endl;
}

ShrubberyCreationForm::FileException::FileException(std::string const& file)
	: _file(file)
{
}

ShrubberyCreationForm::FileException::~FileException() throw()
{
}

const char* ShrubberyCreationForm::FileException::what() const throw()
{
	static char	buffer[300];

	std::string str = "Cannot write shrubbery to file ";
	str += _file;
	std::size_t size = str.copy(buffer, sizeof(buffer) - 1);
	buffer[size] = '\0';
	return buffer;
}
