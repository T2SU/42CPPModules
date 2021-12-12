/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 13:38:17 by smun              #+#    #+#             */
/*   Updated: 2021/12/05 14:11:48 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

# include <string>

class Data
{
public:
	enum { Male, Female };

private:
	std::string const	_name;
	unsigned int const	_grade;
	std::string const	_address;
	unsigned int const	_gender;

	Data();
	Data& operator= (Data const& another);

public:
	virtual ~Data();
	Data(Data const& origin);
	Data(std::string const& name,
		unsigned int const grade,
		std::string const& address,
		unsigned int const gender);

	std::string const&	getName() const;
	int					getGrade() const;
	std::string const&	getAddress() const;
	int					getGender() const;
};

#endif
