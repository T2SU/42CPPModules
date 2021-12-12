/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 22:25:34 by smun              #+#    #+#             */
/*   Updated: 2021/12/12 10:16:33 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>

int main(void)
{
	// VECTOR:
	{
		std::vector<int> vector;
		vector.push_back(1);
		vector.push_back(2);
		vector.push_back(4);
		vector.push_back(5);
		vector.push_back(6);

		if (::easyfind(vector, 3) != std::end(vector))
			std::cout << "found 3 from vector" << std::endl;
		else
			std::cout << "not found 3 from vector" << std::endl;
	}

	// LIST:
	{
		std::list<int> list;
		list.push_back(5);
		list.push_back(6);
		list.push_back(5);
		list.push_back(3);
		list.push_back(3);

		if (::easyfind(list, 3) != std::end(list))
			std::cout << "found 3 from list" << std::endl;
		else
			std::cout << "not found 3 from list" << std::endl;
	}

	// DEQUE:
	{
		std::deque<int> deque;
		deque.push_back(2);
		deque.push_back(2);
		deque.push_back(2);
		deque.push_back(2);
		deque.push_back(2);

		if (::easyfind(deque, 3) != std::end(deque))
			std::cout << "found 3 from deque" << std::endl;
		else
			std::cout << "not found 3 from deque" << std::endl;
	}

	// SET:
	{
		std::set<int> set;
		set.insert(1);
		set.insert(2);
		set.insert(3);
		set.insert(4);
		set.insert(6);

		if (::easyfind(set, 3) != std::end(set))
			std::cout << "found 3 from set" << std::endl;
		else
			std::cout << "not found 3 from set" << std::endl;
	}

	// MULTISET:
	{
		std::multiset<int> multiset;
		multiset.insert(5);
		multiset.insert(6);
		multiset.insert(5);
		multiset.insert(3);
		multiset.insert(3);

		if (::easyfind(multiset, 3) != std::end(multiset))
			std::cout << "found 3 from multiset" << std::endl;
		else
			std::cout << "not found 3 from multiset" << std::endl;
	}

	// UNORDERED_SET:
	{
		std::unordered_set<int> unordered_set;
		unordered_set.insert(5);
		unordered_set.insert(6);
		unordered_set.insert(5);
		unordered_set.insert(3);
		unordered_set.insert(3);

		if (::easyfind(unordered_set, 3) != std::end(unordered_set))
			std::cout << "found 3 from unordered_set" << std::endl;
		else
			std::cout << "not found 3 from unordered_set" << std::endl;
	}

	// UNORDERED_MULTISET:
	{
		std::unordered_multiset<int> unordered_multiset;
		unordered_multiset.insert(5);
		unordered_multiset.insert(6);
		unordered_multiset.insert(5);
		unordered_multiset.insert(3);
		unordered_multiset.insert(3);

		if (::easyfind(unordered_multiset, 3) != std::end(unordered_multiset))
			std::cout << "found 3 from unordered_multiset" << std::endl;
		else
			std::cout << "not found 3 from unordered_multiset" << std::endl;
	}

	// MAP:
	{
		std::map<int, int> map;
		map.insert(std::pair<int, int>(0, 1));
		map.insert(std::pair<int, int>(0, 3));
		map.insert(std::pair<int, int>(0, 4));
		map.insert(std::pair<int, int>(0, 5));
		map.insert(std::pair<int, int>(0, 6));

		if (::easyfind(map, 3) != std::end(map))
			std::cout << "found 3 from map" << std::endl;
		else
			std::cout << "not found 3 from map" << std::endl;
	}

	// UNORDERED_MAP:
	{
		std::unordered_map<int, int> unordered_map;
		unordered_map.insert(std::pair<int, int>(0, 1));
		unordered_map.insert(std::pair<int, int>(0, 3));
		unordered_map.insert(std::pair<int, int>(0, 4));
		unordered_map.insert(std::pair<int, int>(0, 5));
		unordered_map.insert(std::pair<int, int>(0, 6));

		if (::easyfind(unordered_map, 3) != std::end(unordered_map))
			std::cout << "found 3 from unordered_map" << std::endl;
		else
			std::cout << "not found 3 from unordered_map" << std::endl;
	}

	// MULTIMAP:
	{
		std::multimap<int, int> multimap;
		multimap.insert(std::pair<int, int>(0, 1));
		multimap.insert(std::pair<int, int>(0, 3));
		multimap.insert(std::pair<int, int>(0, 4));
		multimap.insert(std::pair<int, int>(0, 5));
		multimap.insert(std::pair<int, int>(0, 6));

		if (::easyfind(multimap, 3) != std::end(multimap))
			std::cout << "found 3 from multimap" << std::endl;
		else
			std::cout << "not found 3 from multimap" << std::endl;
	}

	// UNORDERED_MULTIMAP:
	{
		std::unordered_multimap<int, int> unordered_multimap;
		unordered_multimap.insert(std::pair<int, int>(0, 1));
		unordered_multimap.insert(std::pair<int, int>(0, 3));
		unordered_multimap.insert(std::pair<int, int>(0, 4));
		unordered_multimap.insert(std::pair<int, int>(0, 5));
		unordered_multimap.insert(std::pair<int, int>(0, 6));

		if (::easyfind(unordered_multimap, 3) != std::end(unordered_multimap))
			std::cout << "found 3 from unordered_multimap" << std::endl;
		else
			std::cout << "not found 3 from unordered_multimap" << std::endl;
	}
	return 0;
}
