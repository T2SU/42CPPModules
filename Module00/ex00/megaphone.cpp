/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 01:08:53 by smun              #+#    #+#             */
/*   Updated: 2021/09/20 01:08:55 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

static void	print_upper(const char *input)
{
	std::string				str(input);
	std::string::iterator	strit = str.begin();

	while (strit != str.end())
	{
		std::cout << static_cast<char>(std::toupper(*strit));
		strit++;
	}
}

int	main(int argc, char *argv[])
{
	if (argc > 1)
	{
		for (int i = 1; i < argc; i++)
			print_upper(argv[i]);
	}
	else
		print_upper("* loud and unbearable feedback noise *");
	std::cout << std::endl;
	return 0;
}
