/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 10:46:35 by ldevilla          #+#    #+#             */
/*   Updated: 2021/10/19 17:28:06 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/containers/Vector.hpp"
#include "../includes/containers/Stack.hpp"
#include "../includes/containers/Map.hpp"
#include "../includes/containers/Set.hpp"
#include "../includes/iterator/RandomAccessIterator.hpp"
#include "../includes/iterator/ReverseIterator.hpp"
#include <iostream>
#include <vector>
#include <iterator>
#include <list>
#include <string>
#include <stack>
#include <map>
#include <set>

void vector_test();
void stack_test();
void map_test();
void set_test();

int main(int ac, char **av)
{
	if (ac == 2)
	{
		if (!strcmp(av[1], "vector") || !strcmp(av[1], "all"))
			vector_test();
		if (!strcmp(av[1], "stack") || !strcmp(av[1], "all"))
			stack_test();
		if (!strcmp(av[1], "map") || !strcmp(av[1], "all"))
			map_test();
		if (!strcmp(av[1], "set") || !strcmp(av[1], "all"))
			set_test();
	}
	else if (ac == 1)
		std::cout << "\e[31;1m" << av[0] <<  " <container> : vector, stack, map, set -> all\e[0m" << std::endl;

	std::cout << "\e[0m";
}