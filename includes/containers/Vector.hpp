/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 12:32:04 by ldevilla          #+#    #+#             */
/*   Updated: 2021/10/07 14:31:16 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <memory>
#include "../iterator/RandomAccessIterator.hpp"
#include "../iterator/ReverseIterator.hpp"
#include "../utils/TypeTraits.hpp"

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
			explicit vector (const allocator_type& alloc = allocator_type()) : _size(0), _volume(0), _allocator(alloc), _tab(NULL) {}
			
			explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : _size(n), _volume(n), _allocator(alloc), _tab(NULL)
			{
				_tab = _allocator.allocate(_size);
				for (size_type i = 0; i < _size; i++)
					_allocator.construct(&_tab[i], val);
			}

			template <class InputIterator>
			vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
				typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL) : _allocator(alloc), _size(0), _volume(0), _tab(NULL)
			{
				_size = last - first;
				_volume = _size;
				_tab = _allocator.allocate(_size);
				for (size_type i = 0; i < _size; i++)
					_allocator.construct(&_tab[i], *(first + i));
			}
			
			vector (const vector& x) : _size(0)
			{
				_size = x._size;
				_volume = x._volume;
				_allocator = x._allocator;
				_tab = _allocator.allocate(_size);
				for (size_type i = 0; i < _size; i++)
					_allocator.construct(&_tab[i], x._tab[i]);
			}
			
			~vector() { _allocator.deallocate(_tab, _size); }

			//----------ITERATORS--------
			iterator begin() { return iterator(_tab); }
			const_iterator begin() const { return const_iterator(_tab); }
			iterator end() { return iterator(&_tab[_size]); }
			const_iterator end() const { return const_iterator(&_tab[_size]); }

			reverse_iterator rbegin() { return reverse_iterator(end()); }
			const_reverse_iterator rbegin() const { return const_reverse_iterator(end()); }
			reverse_iterator rend() { return reverse_iterator(begin()); }
			const_reverse_iterator rend() const { return const_reverse_iterator(begin()); }
			
			//----------CAPACITY--------
			size_type size() const { return _size; }
			size_type max_size() const { return _allocator.max_size(); }
			size_type capacity() const { return _volume; }
			bool empty() const { return _size == 0; }
			void reserve (size_type n)
			{
				if (n > max_size())
					throw std::length_error("Error: max_size reached!");
				else if (n > _volume)
				{
					value_type *buf = _allocator.allocate(n);
					for (size_type i = 0; i < _size; i++)
					{
						_allocator.construct(&buf[i], _tab[i]);
						_allocator.destroy(&_tab[i]);
					}
					if (_tab)
						_allocator.deallocate(_tab, _volume);
					_tab = buf;
					_volume = n;
				}
			}
			void resize (size_type n, value_type val = value_type())
			{
				if (n < _size)
				{
					for (size_type i = n; i < _size; i++)
						_allocator.destroy(&_tab[i]);
					_size = n;
				}
				else if (n > _volume)
					reserve(n);
				if (n > _size)
				{
					for (size_type i = _size; i < n; i++)
						_allocator.construct(&_tab[i], val);
					_size = n;
				}
			}
			//----------ELEMENT ACCESS--------
			reference operator[] (size_type n)
			{
				reference idx = *(_tab + n);
				return idx;
			}

		private:
			size_type		_size;
			size_type		_volume;
			allocator_type	_allocator;
			pointer			_tab;
	};
}

#endif