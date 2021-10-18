/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 10:46:35 by ldevilla          #+#    #+#             */
/*   Updated: 2021/10/18 15:36:47 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/containers/Vector.hpp"
#include "../includes/containers/Stack.hpp"
#include "../includes/containers/Map.hpp"
#include "../includes/iterator/RandomAccessIterator.hpp"
#include "../includes/iterator/ReverseIterator.hpp"
#include <iostream>
#include <vector>
#include <iterator>
#include <list>
#include <string>
#include <stack>
#include <map>

int main()
{
	ft::map<std::string, int> ft_map;

	ft_map.insert(ft::make_pair("Logan", 19));
	ft_map.insert(ft::make_pair("Alex", 12));
	ft_map.insert(ft::make_pair("Loic", 28));

	ft::map<std::string, int> tab(ft_map.begin(), ft_map.end());

	std::cout << tab["A"] << std::endl;
	ft_map.print();
	tab.print();
}