/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 12:32:04 by ldevilla          #+#    #+#             */
/*   Updated: 2021/10/19 14:13:04 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <memory>
#include "../iterator/RandomAccessIterator.hpp"
#include "../iterator/ReverseIterator.hpp"
#include "../utils/TypeTraits.hpp"
#include "../utils/Tools.hpp"

//#include <iostream>

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
			explicit vector(const allocator_type& alloc = allocator_type()) : _size(0), _volume(0), _allocator(alloc), _tab(NULL) {}
			
			explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : _size(n), _volume(n), _allocator(alloc), _tab(NULL)
			{
				_tab = _allocator.allocate(_size);
				for (size_type i = 0; i < _size; i++)
					_allocator.construct(&_tab[i], val);
			}

			template <class InputIterator>
			vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
				typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL) : _size(0), _volume(0), _allocator(alloc), _tab(NULL)
			{
				_size = last - first;
				_volume = _size;
				_tab = _allocator.allocate(_size);
				for (size_type i = 0; i < _size; i++)
					_allocator.construct(&_tab[i], *(first + i));
			}
			
			vector(const vector& x) : _size(0)
			{
				_size = x._size;
				_volume = x._volume;
				_allocator = x._allocator;
				_tab = _allocator.allocate(_size);
				for (size_type i = 0; i < _size; i++)
					_allocator.construct(&_tab[i], x._tab[i]);
			}
			
			~vector() { _allocator.deallocate(_tab, _size); }

			vector &operator=(const vector &x)
			{
				vector tmp(x);
				swap(tmp);
				return *this;
			}

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
			void reserve(size_type n)
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
			void resize(size_type n, value_type val = value_type())
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
			reference at (size_type n)
			{
				if (n >= _size)
					throw std::out_of_range("Error: you're trying to acceed to an out of ranage element!");
				return _tab[n];
			}
			const_reference at (size_type n) const
			{
				if (n >= _size)
					throw std::out_of_range("Error: you're trying to acceed to an out of ranage element!");
				return _tab[n];
			}
			reference front() { return _tab[0]; }
			const_reference front() const { return _tab[0]; }
			reference back() { return _tab[_size - 1]; }
			const_reference back() const { return _tab[_size - 1]; }

			//----------MODIFIERS--------
			template <class InputIterator>
			void assign(InputIterator first, InputIterator last,
				typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL)
			{
				size_type newSize = last - first;
				if (newSize > _size)
					reserve(newSize);
				for (size_type i = 0; i < _size; i++)
					_allocator.destroy(&_tab[i]);
				_size = newSize;
				for (size_type i = 0; i < _size; i++)
					_allocator.construct(&_tab[i], *(first + i));
			}
			void assign(size_type n, const value_type& val)
			{
				if (n > _size)
					reserve(n);
				for (size_type i = 0; i < _size; i++)
					_allocator.destroy(&_tab[i]);
				_size = n;
				for (size_type i = 0; i < _size; i++)
					_allocator.construct(&_tab[i], val);
			}

			void push_back (const value_type& val)
			{
				if (_size + 1 > _volume)
					_reAlloc();
				_allocator.construct(&_tab[_size++], val);
			}
			void pop_back()
			{
				_allocator.destroy(&_tab[_size - 1]);
				_size--;
			}
			
			iterator insert(iterator position, const value_type& val)
			{
				size_type dist = position - begin();
				if (_size + 1 > _volume)
					_reAlloc();
				_size++;
				for (size_type i = _size - 1; i > dist; i--)
					_allocator.construct(&_tab[i], _tab[i - 1]);
				_allocator.construct(&_tab[dist], val);
				return iterator(begin() + dist);
			}
			void insert(iterator position, size_type n, const value_type& val)
			{
				size_type dist = position - begin();
				if (_size + n > _volume)
				{
					if (n > _size)
						reserve(_size + n);
					else
						_reAlloc();
				}
				_size += n;
				for (size_type i = _size - 1; i > dist; i--)
					_allocator.construct(&_tab[i], _tab[i - n]);
				for (size_type i = 0; i < n; i++)
					_allocator.construct(&_tab[dist + i], val);
			}
			template <class InputIterator>
			void insert(iterator position, InputIterator first, InputIterator last,
				typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL)
			{
				size_type dist = position - begin();
				size_type n = last - first;
				if (_size + n > _volume)
				{
					if (n > _size)
						reserve(_size + n);
					else
						_reAlloc();
				}
				_size += n;
				for (size_type i = _size - 1; i > dist; i--)
					_allocator.construct(&_tab[i], _tab[i - n]);
				for (size_type i = 0; i < n; i++)
					_allocator.construct(&_tab[dist + i], *(first + i));
			}
			
			iterator erase(iterator position)
			{
				size_type dist = position - begin();
				_allocator.destroy(&_tab[dist]);
				for (size_type i = dist; i < _size; i++)
				{
					_allocator.construct(&_tab[i], _tab[i + 1]);
					_allocator.destroy(&_tab[i + 1]);
				}
				_size--;
				return begin() + dist;
			}
			iterator erase(iterator first, iterator last)
			{
				size_type dist = first - begin();
				size_type n = last - first;
				for (size_type i = 0; i < n; i++)
					_allocator.destroy(&_tab[dist + i]);
				for (size_type i = dist; i < _size; i++)
				{
					_allocator.construct(&_tab[i], _tab[i + n]);
					_allocator.destroy(&_tab[i + n]);
				}
				_size -= n;
				return begin() + dist;
			}

			void swap(vector &x)
			{
				size_type		sizeTemp = x._size;
				size_type		volTemp = x._volume;
				allocator_type	allocTemp = x._allocator;
				pointer			tabTemp = x._tab;

				x._size = _size;
				x._volume = _volume;
				x._allocator = _allocator;
				x._tab = _tab;
				
				_size = sizeTemp;
				_volume = volTemp;
				_allocator = allocTemp;
				_tab = tabTemp;
			}

			void clear()
			{
				for (size_type i = 0; i < _size; i++)
					_allocator.destroy(&_tab[i]);
				_size = 0;
			}

			//----------ALLOCATOR--------
			allocator_type get_allocator() const
			{
				allocator_type ret(_allocator);
				return ret;
			}

		private:

			void	_reAlloc()
			{
				if (_volume == 0)
					reserve(1);
				else
					reserve(_volume * 2);
			}
			
			size_type		_size;
			size_type		_volume;
			allocator_type	_allocator;
			pointer			_tab;
	};

	template <class T, class Alloc>
	bool operator==(const vector<T,Alloc> &lhs, const vector<T,Alloc> &rhs)
	{
		if (lhs.size() == rhs.size())
			return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
		return false;
	}

	template <class T, class Alloc>
	bool operator!=(const vector<T,Alloc> &lhs, const vector<T,Alloc> &rhs)
	{
		return !(lhs == rhs);
	}

	template <class T, class Alloc>
	bool operator<(const vector<T,Alloc> &lhs, const vector<T,Alloc> &rhs)
	{
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	template <class T, class Alloc>
	bool operator<=(const vector<T,Alloc> &lhs, const vector<T,Alloc> &rhs)
	{
		return !(rhs < lhs);
	}

	template <class T, class Alloc>
	bool operator>(const vector<T,Alloc> &lhs, const vector<T,Alloc> &rhs)
	{
		return rhs < lhs;
	}

	template <class T, class Alloc>
	bool operator>=(const vector<T,Alloc> &lhs, const vector<T,Alloc> &rhs)
	{
		return !(lhs < rhs);
	}

	template <class T, class Alloc>
	void swap(vector<T,Alloc> &x, vector<T,Alloc> &y)
	{
		x.swap(y);
	}

}

#endif