/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 21:40:42 by smun              #+#    #+#             */
/*   Updated: 2021/12/02 12:23:30 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "Form.hpp"
# include <exception>
# include <string>

class ShrubberyCreationForm : public Form
{
private:
	ShrubberyCreationForm();

protected:
	virtual void	execute(Bureaucrat const& executor) const;

public:
	ShrubberyCreationForm(std::string const& target);
	ShrubberyCreationForm(ShrubberyCreationForm const& origin);
	virtual ~ShrubberyCreationForm();
	ShrubberyCreationForm& operator= (ShrubberyCreationForm const& another);

	class FileException : public std::exception
	{
	private:
		std::string	_file;

	public:
		virtual ~FileException() throw();
		FileException(std::string const& file);
		const char* what() const throw();
	};
};

#endif
