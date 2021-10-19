/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_speed_test.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 18:02:03 by ldevilla          #+#    #+#             */
/*   Updated: 2021/10/19 18:09:24 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/containers/Map.hpp"
#include "../../includes/containers/Stack.hpp"
#include "../../includes/containers/Vector.hpp"
#include <iostream>
#include <string>

#define PURPLE "\e[35m"
#define GREEN "\e[32m"
#define REDD "\e[31;1m"
#define RESET "\e[0m"

int main()
{
	std::cout << REDD << "VERY HARD SPEED TEST" << std::endl;

	ft::map<int, int> tab;

	for (int i = 0; i < 9999999; i++)
		tab.insert(ft::make_pair(i, 1));

	ft::stack<int, ft::vector<int> > st;
	for (int i = 0; i < 999999; i++)
		st.push(i);

	ft::vector<std::string> vec;
	for (int i = 0; i < 999999; i++)
		vec.push_back("too fast");
	
	std::cout << PURPLE << "done" << RESET << std::endl;
}