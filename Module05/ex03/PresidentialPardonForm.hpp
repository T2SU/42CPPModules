/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 21:40:42 by smun              #+#    #+#             */
/*   Updated: 2021/11/30 21:44:42 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "Form.hpp"
# include <string>

class PresidentialPardonForm : public Form
{
private:
	PresidentialPardonForm();

protected:
	virtual void	execute(Bureaucrat const& executor) const;

public:
	PresidentialPardonForm(std::string const& target);
	PresidentialPardonForm(PresidentialPardonForm const& origin);
	virtual ~PresidentialPardonForm();
	PresidentialPardonForm& operator= (PresidentialPardonForm const& another);
};

#endif
