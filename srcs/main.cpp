/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 10:46:35 by ldevilla          #+#    #+#             */
/*   Updated: 2021/10/19 10:39:33 by ldevilla         ###   ########lyon.fr   */
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
	/*
	ft::map<std::string, int> ft_map;

	ft_map.insert(ft::make_pair("Logan", 19));
	ft_map.insert(ft::make_pair("Boyyyyy", 12));
	ft_map.insert(ft::make_pair("Leickmay", 28));

	ft::map<std::string, int> tab;

	tab.insert(ft::make_pair("heyy", 9));
	tab.insert(ft::make_pair("dabadi", 2));
	tab.insert(ft::make_pair("wuhfuen", 4));
	tab.insert(ft::make_pair("LOLILOL", 29));

	tab.swap(ft_map);

	ft_map.print();
	std::cout << "--------------------" << std::endl;
	tab.print();
	
	ft::map<char,int> foo;
	ft::map<char, int>::iterator it;

	foo['x']=100;
	foo['y']=200;
	
	foo['a']=11;
	foo['b']=22;
	foo['c']=33;

	foo.print();
	foo.clear();
	foo.print();

	it = foo.begin();

	while (it != foo.end())
	{
		std::cout << it->first << " : " << it->second << std::endl;
		it++;
	}*/

    ft::map<int, char> alice;
	alice[1] = 'a';
	alice[2] = 'b';
	alice[3] = 'c';
    ft::map<int, char> bob;
	bob[7] = 'Z';
	bob[8] = 'Y';
	bob[9] = 'X';
	bob[10] = 'W';


	for (int i = 1; i < 4; i++)
		std::cout << alice[i] << std::endl;
	std::cout << "---------" << std::endl;
	for (int i = 7; i < 11; i++)
		std::cout << bob[i] << std::endl;

	ft::swap(alice, bob);
	std::cout << "-------------------" << std::endl;

	for (int i = 1; i < 4; i++)
		std::cout << bob[i] << std::endl;
	std::cout << "---------" << std::endl;
	for (int i = 7; i < 11; i++)
		std::cout << alice[i] << std::endl;
}