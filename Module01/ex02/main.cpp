/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 18:27:07 by smun              #+#    #+#             */
/*   Updated: 2021/09/27 19:05:08 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main( void )
{
	std::string	hello = "HI THIS IS BRAIN";
	std::string	*stringPTR = &hello;
	std::string	&stringREF = hello;
	std::cout << "hello    : " << std::hex << &hello << std::endl;
	std::cout << "stringPTR: " << std::hex << stringPTR << std::endl;
	std::cout << "stringREF: " << std::hex << &stringREF << std::endl;
	std::cout << "hello    : " << hello << std::endl;
	std::cout << "stringPTR: " << *stringPTR << std::endl;
	std::cout << "stringREF: " << stringREF << std::endl;
	return 0;
}
