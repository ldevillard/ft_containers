/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 10:46:35 by ldevilla          #+#    #+#             */
/*   Updated: 2021/10/07 14:31:37 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/containers/Vector.hpp"
#include "../includes/iterator/RandomAccessIterator.hpp"
#include "../includes/iterator/ReverseIterator.hpp"
#include <iostream>
#include <vector>
#include <iterator>
#include <list>

int main()
{

	ft::vector<int> tab(5,100);
	ft::vector<int>::iterator it = tab.begin();

	while (it != tab.end())
	{
		std::cout << *it << std::endl;
		it++;
	}

	std::cout << "----------------" << std::endl;

	ft::vector<int> tab2(tab);
	tab2.resize(10, 3);
	ft::vector<int>::iterator it2 = tab2.begin();
	tab2.reserve(8);


	while (it2 != tab2.end())
	{
		std::cout << *it2 << std::endl;
		it2++;
	}
	
	ft::vector<int> lol;
	
	std::cout << lol.empty() << std::endl;
/*
	ft::vector<double> tab(3, 3.14);
	tab[2] = 2.14;

	ft::vector<double>::reverse_iterator rit = tab.rend();
	rit--;
	std::cout << *rit << std::endl;
*/
	return 0;
}