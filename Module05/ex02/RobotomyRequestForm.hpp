/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 21:40:42 by smun              #+#    #+#             */
/*   Updated: 2021/12/02 12:23:27 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "Form.hpp"
# include <string>

class RobotomyRequestForm : public Form
{
private:
	RobotomyRequestForm();

protected:
	virtual void	execute(Bureaucrat const& executor) const;

public:
	RobotomyRequestForm(std::string const& target);
	RobotomyRequestForm(RobotomyRequestForm const& origin);
	virtual ~RobotomyRequestForm();
	RobotomyRequestForm& operator= (RobotomyRequestForm const& another);

	class NoRandomSourceException : public std::exception
	{
	public:
		const char* what() const throw();
	};

	class RandomSourceAccessException : public std::exception
	{
	public:
		const char* what() const throw();
	};
};

#endif
