/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 12:49:01 by smun              #+#    #+#             */
/*   Updated: 2021/12/11 22:10:05 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_HPP
# define CONVERTER_HPP

# include <string>
# include <exception>

class Converter
{
public:
	enum
	{
		Type_None = 0,
		Type_Integer = 1 << 0,
		Type_Float = 1 << 1,
		Type_Double = 1 << 2,
		Type_Character = 1 << 3,
		Type_Displayable = 1 << 4
	};
	enum { Error_Impossible, Error_NonDisplayable };

private:
	std::string		_literal;
	unsigned int	_typeFlag;
	int				_intval;
	float			_floatval;
	double			_doubleval;

	Converter();

	void			purgeQuotes(std::string& literal);
	void			parse();
public:
	Converter(const char* literal);
	Converter(Converter const& origin);
	virtual ~Converter();
	Converter& operator= (Converter const& another);

	int				toInt() const;
	float			toFloat() const;
	double			toDouble() const;
	char			toChar() const;
	bool			hasFractional() const;
	bool			hasTypeFlag(unsigned int flag) const;

	class	NotConvertibleException : public std::exception
	{
	private:
		int	_errorType;
		NotConvertibleException();
		NotConvertibleException& operator= (NotConvertibleException const& origin);

	public:
		NotConvertibleException(int errorType);
		virtual ~NotConvertibleException() throw();
		NotConvertibleException(NotConvertibleException const& origin);

		const char* what() const throw();
	};
};

#endif
