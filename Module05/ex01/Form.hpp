/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 17:32:12 by smun              #+#    #+#             */
/*   Updated: 2021/12/02 15:15:19 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>

class Bureaucrat;

class Form
{
private:
	std::string	_name;
	bool		_signed;
	int			_gradeToSign;
	int			_gradeToExecute;

	Form();

protected:
	void		setGradeToSign(int gradeToSign);
	void		setGradeToExecute(int gradeToExecute);

public:
	Form(std::string const& name, int gradeToSign, int gradeToExecute);
	virtual ~Form();
	Form(Form const& origin);
	Form& operator= (Form const& another);

	std::string	const&	getName() const;
	bool				isSigned() const;
	int					getGradeToSign() const;
	int					getGradeToExecute() const;
	void				beSigned(Bureaucrat const& bureaucrat);

	class GradeTooHighException : public std::exception
	{
	private:
		int	_grade;
		GradeTooHighException();
	public:
		GradeTooHighException(int grade);
		const char* what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
	private:
		int	_grade;
		GradeTooLowException();
	public:
		GradeTooLowException(int grade);
		const char* what() const throw();
	};

	class AlreadySignedException : public std::exception
	{
	public:
		const char* what() const throw();
	};
};

std::ostream& operator<< (std::ostream& ostream, Form const& form);

#endif
