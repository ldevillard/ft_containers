/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 10:46:35 by ldevilla          #+#    #+#             */
/*   Updated: 2021/10/07 16:41:35 by ldevilla         ###   ########lyon.fr   */
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
	std::vector<int> tab(4, 5);
	std::vector<int>::iterator it = tab.begin();

	//tab.push_back(2);
	//tab.pop_back();
	tab.insert(it, 12, 4);

	std::cout << "CAPACITY : " << tab.capacity() << std::endl;

	for (it = tab.begin(); it != tab.end(); it++)
		std::cout << *it << std::endl;

	return 0;
}