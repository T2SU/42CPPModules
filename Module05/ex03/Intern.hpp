/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 14:19:52 by smun              #+#    #+#             */
/*   Updated: 2021/12/03 13:44:12 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include <exception>

class Form;

class Intern
{
public:
	class FormTemplatePair
	{
	private:
		std::string	_name;
		Form*		(*_create)(std::string const&);

		FormTemplatePair();
		FormTemplatePair& operator= (FormTemplatePair const& another);
	public:
		FormTemplatePair(FormTemplatePair const& origin);
		virtual ~FormTemplatePair();
		FormTemplatePair(std::string const& name, Form*(*create)(std::string const&));

		std::string const&	getName() const;
		Form*				create(std::string const& target) const;
	};

private:
	Intern(Intern const& origin);
	Intern& operator= (Intern const& another);

public:
	Intern();
	virtual ~Intern();
	Form*	makeForm(std::string const& name, std::string const& target);

	class InvalidFormNameException : public std::exception
	{
	private:
		std::string	_name;
	public:
		virtual ~InvalidFormNameException() throw();
		InvalidFormNameException(std::string const& name);
		const char* what() const throw();
	};
};

#endif
