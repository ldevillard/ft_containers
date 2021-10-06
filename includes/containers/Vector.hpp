/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 12:32:04 by ldevilla          #+#    #+#             */
/*   Updated: 2021/10/06 15:19:36 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <memory>
#include "../iterator/RandomAccessIterator.hpp"
#include "../iterator/ReverseIterator.hpp"

#include <iostream> //DEBUG

namespace ft
{
	template <class T, class Alloc = std::allocator<T> >
	class vector
	{
		public:
			//----------TYPEDEF--------
			typedef T value_type;
			typedef Alloc allocator_type;
			
			typedef typename allocator_type::reference reference;
			typedef typename allocator_type::const_reference const_reference;
			typedef typename allocator_type::pointer pointer;
			typedef typename allocator_type::const_pointer const_pointer;
			
			typedef ft::random_access_iterator<value_type> iterator;
			typedef ft::random_access_iterator<const value_type> const_iterator;
			typedef ft::reverse_iterator<iterator> reverse_iterator;
			typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
	
			typedef typename ft::iterator_traits<iterator>::difference_type difference_type; //equivalent to ptrdiff_t
			typedef size_t size_type;
	
			//----------CONSTRUCTORS--------
			explicit vector (const allocator_type& alloc = allocator_type()) : _size(0), _volume(0), _allocator(alloc), _tab(0) {}
			explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());
			template <class InputIterator>
			vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());
			vector (const vector& x);
	
		private:
			size_type		_size;
			size_type		_volume;
			allocator_type	_allocator;
			pointer			_tab;
	};
}

#endif