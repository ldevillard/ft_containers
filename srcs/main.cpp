/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 10:46:35 by ldevilla          #+#    #+#             */
/*   Updated: 2021/10/12 16:51:58 by ldevilla         ###   ########lyon.fr   */
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
  std::stack<int, std::list<int> > myints;
  std::stack<int, std::list<int> > myints2;

  myints2.push(4);
  myints2.push(3);
  for (int i = 0; i < 1000000; i++)
    myints2.push(1);

  myints = myints2;
/*
  while (myints.size() > 0)
  {
	  std::cout << myints.top() << '\n';
	  myints.pop();
  }
*/
  return 0;
}