/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   std_speed_test.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 18:01:56 by ldevilla          #+#    #+#             */
/*   Updated: 2021/10/19 18:08:27 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <stack>
#include <map>
#include <iostream>
#include <string>

#define PURPLE "\e[35m"
#define GREEN "\e[32m"
#define REDD "\e[31;1m"
#define RESET "\e[0m"

int main()
{
	std::cout << REDD << "VERY HARD SPEED TEST" << std::endl;

	std::map<int, int> tab;

	for (int i = 0; i < 9999999; i++)
		tab.insert(std::make_pair(i, 1));

	std::stack<int, std::vector<int> > st;
	for (int i = 0; i < 999999; i++)
		st.push(i);

	std::vector<std::string> vec;
	for (int i = 0; i < 999999; i++)
		vec.push_back("too fast");
	
	std::cout << GREEN << "done" << RESET << std::endl;
}