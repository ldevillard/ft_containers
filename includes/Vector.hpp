/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 12:32:04 by ldevilla          #+#    #+#             */
/*   Updated: 2021/10/05 14:32:37 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <iostream>
#include <memory>
#include <iterator>

namespace ft
{
	template <class T, class Alloc = std::allocator<T> >
	class Vector
	{
		//typedef
		typedef T value_type; //first arg
		typedef Alloc allocator_type; //second arg
		
		typedef typename allocator_type::reference reference; //reference to an element of our vector
		typedef typename allocator_type::const_reference const_reference; //const ref **
		typedef typename allocator_type::pointer pointer; //pointeur **
		typedef typename allocator_type::const_pointer const_pointer; //const ptr **
		
		//typedef implementation-defined iterator; //have to implement my own iterator system
	};
}

#endif