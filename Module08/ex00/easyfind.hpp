/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 22:18:52 by smun              #+#    #+#             */
/*   Updated: 2021/12/11 23:28:33 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <functional>
# include <map>
# include <unordered_map>

template<typename T>
typename T::iterator easyfind(T & container, int toFind)
{
	return std::find(container.begin(), container.end(), toFind);
}

template<typename K, typename V>
class MapFinder : public std::binary_function<std::pair<K, V>, int, bool>
{
private:
	MapFinder& operator= (MapFinder const&);
public:
	MapFinder() {}
	MapFinder(MapFinder const&) {}
	virtual ~MapFinder() {}

	bool operator()(std::pair<K, V> const& pair, int const& toFind) const
	{
		return pair.second == toFind;
	}
};

template<typename K, typename V>
typename std::map<K, V>::iterator easyfind(std::map<K, V> & container, int toFind)
{
	return std::find_if(container.begin(), container.end(), std::bind2nd(MapFinder<K, V>(), toFind));
}

template<typename K, typename V>
typename std::multimap<K, V>::iterator easyfind(std::multimap<K, V> & container, int toFind)
{
	return std::find_if(container.begin(), container.end(), std::bind2nd(MapFinder<K, V>(), toFind));
}

template<typename K, typename V>
typename std::unordered_map<K, V>::iterator easyfind(std::unordered_map<K, V> & container, int toFind)
{
	return std::find_if(container.begin(), container.end(), std::bind2nd(MapFinder<K, V>(), toFind));
}

template<typename K, typename V>
typename std::unordered_multimap<K, V>::iterator easyfind(std::unordered_multimap<K, V> & container, int toFind)
{
	return std::find_if(container.begin(), container.end(), std::bind2nd(MapFinder<K, V>(), toFind));
}

#endif
