/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 18:14:52 by smun              #+#    #+#             */
/*   Updated: 2021/09/27 20:44:16 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Karen.hpp"

Karen::Karen()
{
	actionMap[DEBUG] = "DEBUG";
	actionMap[INFO] = "INFO";
	actionMap[WARNING] = "WARNING";
	actionMap[ERROR] = "ERROR";
}

void	Karen::complain( std::string level )
{
	const Level paramLevel = getLevel(level);

	if (switchLevel > paramLevel)
		return;
	switch (paramLevel)
	{
		case DEBUG:
			debug();
			break;
		case INFO:
			info();
			break;
		case WARNING:
			warning();
			break;
		case ERROR:
			error();
			break;
		default:
			break;
	}
}

Level	Karen::getLevel( std::string level )
{
	for (int i = DEBUG; i < NUM; i++)
		if (actionMap[i] == level)
			return static_cast<Level>(i);
	return UNDEFINED;
}

bool	Karen::setFilterLevel( std::string level )
{
	const Level paramLevel = this->getLevel(level);

	if (paramLevel == UNDEFINED)
		return false;
	this->switchLevel = paramLevel;
	return true;
}

void	Karen::debug( void )
{
	std::cout << CYAN"[DEBUG] 내 7XL-더블-치즈-트리플-피클-스페셜-케첩-버거에 베이컨을 더 얹어 먹곤 하죠. 그냥 그렇다고요. ㅎㅎ"RESET << std::endl;
}

void	Karen::info( void )
{
	std::cout << GREEN"[INFO] 베이컨 좀 얹는 거에 돈을 더 내라고요? 애초에 별로 넣지도 않아놓고서! 제대로 넣어줬으면 말도 안 꺼냈죠!"RESET << std::endl;
}

void	Karen::warning( void )
{
	std::cout << YELLOW"[WARNING] 당신 여기 일한 지 고작 한 달이죠? 내가 여기 가게 몇 년 단골인 줄 알아요? 그냥 베이컨 좀 얹어줘도 되잖아요?"RESET << std::endl;
}

void	Karen::error( void )
{
	std::cout << RED"[ERROR] 당신이랑 말이 안통하네요. 지금 당장 매니저 불러오세요."RESET << std::endl;
}
