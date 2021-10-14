/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 10:46:35 by ldevilla          #+#    #+#             */
/*   Updated: 2021/10/14 15:01:09 by ldevilla         ###   ########lyon.fr   */
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
	ft::map<std::string, int> tab;

	tab.insert(ft::pair<std::string, int>("logan", 19));
	tab.insert(ft::pair<std::string, int>("test", 32));
	tab.insert(ft::pair<std::string, int>("alo", 9));
	tab.insert(ft::pair<std::string, int>("ki", 2));
	tab.print();


}