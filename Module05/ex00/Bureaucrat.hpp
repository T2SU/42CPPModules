/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 13:51:18 by smun              #+#    #+#             */
/*   Updated: 2021/12/02 15:14:43 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>

class Bureaucrat
{
private:
	std::string	_name;
	int			_grade;
	void		setGrade(int grade);
	Bureaucrat();

public:
	Bureaucrat(std::string const& name, int grade);
	virtual ~Bureaucrat();
	Bureaucrat(Bureaucrat const& origin);
	Bureaucrat&			operator= (Bureaucrat const& another);

	int					getGrade() const;
	std::string const&	getName() const;

	void				incGrade();
	void				decGrade();

	class GradeTooHighException : public std::exception
	{
	private:
		int	_grade;
		GradeTooHighException();
	public:
		GradeTooHighException(int grade);
		virtual const char*	what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
	private:
		int	_grade;
		GradeTooLowException();
	public:
		GradeTooLowException(int grade);
		virtual const char*	what() const throw();
	};
};

std::ostream	&operator<<(std::ostream &ostream, Bureaucrat const &bureaucrat);

#endif
