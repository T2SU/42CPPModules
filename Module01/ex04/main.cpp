/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 18:56:46 by smun              #+#    #+#             */
/*   Updated: 2021/09/26 18:20:22 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int	main( int argc, char *argv[] )
{
	if (argc < 4)
	{
		std::cerr << "Usage: " << argv[0] << " <FILENAME> <To be replaced string> <To replace string>" << std::endl;
		return 1;
	}
	std::ifstream	ifs(argv[1], std::ios::in);
	std::ofstream	ofs(std::string(argv[1]) + ".REPLACE", std::ios::out | std::ios::trunc);
	if (!ifs)
	{
		std::cerr << "Failed to read file " << argv[1] << std::endl;
		return 1;
	}
	if (!ofs)
	{
		std::cerr << "Failed to write file to " << argv[1] << ".REPLACE" << std::endl;
		return 1;
	}
	const std::string	before = argv[2];
	const std::string	after = argv[3];
	std::string	line;
	while (std::getline(ifs, line))
	{
		while (true)
		{
			if (before.length() <= 0)
				break;
			size_t pos = line.find(before);
			if (pos == std::string::npos)
				break;
			line = line.substr(0, pos) + after + line.substr(pos + before.length());
		}
		ofs << line;
		if (!ifs.eof())
			ofs << std::endl;
	}
}
