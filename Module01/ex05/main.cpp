/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 01:01:21 by smun              #+#    #+#             */
/*   Updated: 2021/09/26 18:51:16 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

int	main()
{
	Karen	karen;

	for (int i = 0; i < 2; i++)
		karen.complain("DEBUG");
	for (int i = 0; i < 3; i++)
		karen.complain("INFO");
	for (int i = 0; i < 4; i++)
		karen.complain("WARNING");
	for (int i = 0; i < 5; i++)
		karen.complain("ERROR");
}
