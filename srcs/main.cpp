/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 10:46:35 by ldevilla          #+#    #+#             */
/*   Updated: 2021/10/11 11:49:35 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/containers/Vector.hpp"
#include "../includes/iterator/RandomAccessIterator.hpp"
#include "../includes/iterator/ReverseIterator.hpp"
#include <iostream>
#include <vector>
#include <iterator>
#include <list>

/*
int main()
{
	ft::vector<int> tab(4, 5);
	ft::vector<int> tab2(2, 3);
	ft::vector<int>::iterator it = tab2.begin();

	it++;

	tab2.insert(it, tab.begin(), tab.end());
	
	std::cout << "CAPACITY : " << tab2.capacity() << std::endl;

	for (it = tab2.begin(); it != tab2.end(); it++)
		std::cout << *it << std::endl;

	return 0;
}*/
/*
int main ()
{
	ft::vector<int> myvector;

  // set some values (from 1 to 10)
  for (int i=1; i<=10; i++)
  {
  	myvector.push_back(i);
  }
	  

  // erase the 6th element
  myvector.erase (myvector.begin()+5);

  std::cout << "CAPACITY : " << myvector.capacity() << std::endl;

  // erase the first 3 elements:
  ft::vector<int>::iterator it = myvector.erase (myvector.begin(),myvector.begin()+3);

  std::cout << "myvector contains:";
  for (unsigned i=0; i<myvector.size(); ++i)
    std::cout << ' ' << myvector[i];
  std::cout << '\n';
  std::cout << *it << std::endl;

  return 0;
}*/

int main ()
{
  ft::vector<int> myvector;
  int * p;
  unsigned int i;

  // allocate an array with space for 5 elements using vector's allocator:
  p = myvector.get_allocator().allocate(5);

  // construct values in-place on the array:
  for (i=0; i<5; i++) myvector.get_allocator().construct(&p[i],i);

  std::cout << "The allocated array contains:";
  for (i=0; i<5; i++) std::cout << ' ' << p[i];
  std::cout << '\n';

  // destroy and deallocate:
  for (i=0; i<5; i++) myvector.get_allocator().destroy(&p[i]);
  myvector.get_allocator().deallocate(p,5);

  return 0;
}