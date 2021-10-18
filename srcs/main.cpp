/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 10:46:35 by ldevilla          #+#    #+#             */
/*   Updated: 2021/10/18 17:21:02 by ldevilla         ###   ########lyon.fr   */
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

  std::map<char,int> mymap;

  mymap ['a']=101;
  mymap ['r']=202;
  mymap ['c']=303;
  mymap ['d']=101;
  mymap ['h']=202;
  mymap ['f']=303;

  std::cout << mymap.lower_bound('b')->first << std::endl;
  std::cout << mymap.upper_bound('b')->first << std::endl;

}