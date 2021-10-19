/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_test.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 17:27:38 by ldevilla          #+#    #+#             */
/*   Updated: 2021/10/19 17:45:58 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/containers/Set.hpp"

void set_test()
{
	std::cout << "\e[36;1mSet is identic as map, check map test for details" << std::endl;
	std::cout << "The main difference is that map is an associative table like key -> value" << std::endl;
	std::cout << "and set is an ordered unique element storage system" << std::endl;
	std::cout << "#red_black_tree\e[0m" << std::endl << std::endl;
	

	ft::set<std::string> tab;

	tab.insert("Hey");
	tab.insert("there");
	tab.insert("how");
	tab.insert("are");
	tab.insert("u");
	tab.insert("?");

	ft::set<std::string>::iterator it = tab.begin();
	
	std::cout << "\e[33;1minsert as \'Hey\' \'there\' \'how\' \'are\' \'u\' \'?\'" << std::endl;
	std::cout << "\e[35m";

	while (it != tab.end())
		std::cout << "\"" << *it++ << "\"" << ' ';

	std::cout << "\n\e[33;1mThen items are sorted in the container" << std::endl;
	std::cout << std::endl;
	
	std::cout << "\e[31;1m" << "see ./ft_containers" <<  " \"map\"\e[0m" << std::endl;
}