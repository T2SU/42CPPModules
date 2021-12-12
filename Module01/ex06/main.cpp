/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 01:01:21 by smun              #+#    #+#             */
/*   Updated: 2021/09/27 20:43:52 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Karen.hpp"

int	main( int argc, char *argv[] )
{
	Karen	karen;

	if (argc < 2)
	{
		std::cerr << argv[0] << " <DEBUG|INFO|ERROR|WARNING>" << std::endl;
		return 1;
	}
	if (!karen.setFilterLevel(argv[1]))
	{
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		return 1;
	}
	karen.complain("DEBUG");
	karen.complain("INFO");
	karen.complain("WARNING");
	karen.complain("ERROR");
}
