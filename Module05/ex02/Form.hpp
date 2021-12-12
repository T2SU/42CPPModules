/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 17:32:12 by smun              #+#    #+#             */
/*   Updated: 2021/12/02 15:15:42 by smun             ###   ########.fr       */
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
	std::string	_target;

	Form();

protected:
	void			setGradeToSign(int gradeToSign);
	void			setGradeToExecute(int gradeToExecute);
	virtual void	execute(Bureaucrat const& executor) const = 0;

public:
	Form(std::string const& name, int gradeToSign, int gradeToExecute, std::string const & target);
	virtual ~Form();
	Form(Form const& origin);
	Form& operator= (Form const& another);

	std::string const&	getName() const;
	bool				isSigned() const;
	std::string const&	getTarget() const;
	int					getGradeToSign() const;
	int					getGradeToExecute() const;
	void				beSigned(Bureaucrat const& bureaucrat);
	void				beExecuted(Bureaucrat const& bureaucrat) const;

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

	class NotSignedException : public std::exception
	{
	public:
		const char* what() const throw();
	};
};

std::ostream& operator<< (std::ostream& ostream, Form const& form);

#endif
