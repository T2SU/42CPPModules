/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 17:15:34 by smun              #+#    #+#             */
/*   Updated: 2021/12/02 15:47:44 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::~Form()
{
}

Form::Form(std::string const& name, int gradeToSign, int gradeToExecute)
	: _name(name)
	, _signed(false)
{
	setGradeToSign(gradeToSign);
	setGradeToExecute(gradeToExecute);
}

Form::Form(Form const& origin)
	: _name(origin.getName())
	, _signed(origin.isSigned())
{
	setGradeToSign(origin.getGradeToSign());
	setGradeToExecute(origin.getGradeToExecute());
}

Form& Form::operator= (Form const& another)
{
	if (this == &another)
		return *this;
	_name = another.getName();
	_signed = another.isSigned();
	setGradeToSign(another.getGradeToSign());
	setGradeToExecute(another.getGradeToExecute());
	return *this;
}

void	Form::setGradeToSign(int gradeToSign)
{
	if (gradeToSign < 1)
		throw Form::GradeTooHighException(gradeToSign);
	if (gradeToSign > 150)
		throw Form::GradeTooLowException(gradeToSign);
	_gradeToSign = gradeToSign;
}

void	Form::setGradeToExecute(int gradeToExecute)
{
	if (gradeToExecute < 1)
		throw Form::GradeTooHighException(gradeToExecute);
	if (gradeToExecute > 150)
		throw Form::GradeTooLowException(gradeToExecute);
	_gradeToExecute = gradeToExecute;
}

std::string const&	Form::getName() const
{
	return _name;
}

bool	Form::isSigned() const
{
	return _signed;
}

int	Form::getGradeToSign() const
{
	return _gradeToSign;
}

int	Form::getGradeToExecute() const
{
	return _gradeToExecute;
}

void	Form::beSigned(Bureaucrat const& bureaucrat)
{
	if (isSigned())
		throw Form::AlreadySignedException();
	if (bureaucrat.getGrade() > getGradeToSign())
		throw Form::GradeTooHighException(getGradeToSign());
	_signed = true;
}

Form::GradeTooHighException::GradeTooHighException(int grade)
	: _grade(grade)
{
}

Form::GradeTooLowException::GradeTooLowException(int grade)
	: _grade(grade)
{
}

const char*	Form::GradeTooHighException::what() const throw()
{
	static char buffer[64];

	std::string str;
	str += "Form's grade ";
	str += std::to_string(_grade);
	str += " is too high.";
	std::size_t size = str.copy(buffer, sizeof(buffer) - 1);
	buffer[size] = '\0';
	return buffer;
}

const char*	Form::GradeTooLowException::what() const throw()
{
	static char buffer[64];

	std::string str;
	str += "Form's grade ";
	str += std::to_string(_grade);
	str += " is too low.";
	std::size_t size = str.copy(buffer, sizeof(buffer) - 1);
	buffer[size] = '\0';
	return buffer;
}

const char*	Form::AlreadySignedException::what() const throw()
{
	return "Form is already signed.";
}

std::ostream& operator<< (std::ostream& ostream, Form const& form)
{
	ostream << form.getName() << ", form is ";
	if (!form.isSigned())
		ostream << "not ";
	ostream << "signed";
	ostream << " (signable grade: " << form.getGradeToSign() << ")";
	ostream << " (executable grade: " << form.getGradeToExecute() << ")";
	return ostream;
}
