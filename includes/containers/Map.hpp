/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 15:35:20 by ldevilla          #+#    #+#             */
/*   Updated: 2021/10/18 17:18:56 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include <functional>
#include <memory>
#include "../utils/Tools.hpp"
#include "../utils/RBTree.hpp"
#include "../iterator/IteratorTraits.hpp"

namespace ft
{
	template < class Key, class T,
	class Compare = std::less<Key>,
	class Alloc = std::allocator<ft::pair<const Key,T> > >
	class map
	{
		public:
			/*--------MEMBER TYPES-------*/
			typedef Key key_type;
			typedef T mapped_type;
			typedef ft::pair<key_type, mapped_type> value_type;
			typedef Compare key_compare;

			class value_compare
			{
				protected:
					Compare _comp;
				public:
					typedef bool result_type;
					typedef value_type first_argument_type;
					typedef value_type second_argument_type;
					bool operator()(const value_type& x, const value_type& y) const
					{
						return _comp(x.first, y.first);
					}
			};

			typedef Alloc allocator_type;
			typedef typename allocator_type::reference reference;
			typedef typename allocator_type::const_reference const_reference;
			typedef typename allocator_type::pointer pointer;
			typedef typename allocator_type::const_pointer const_pointer;

			typedef typename ft::rb_tree<value_type, value_compare>::iterator iterator;
			typedef typename ft::rb_tree<value_type, value_compare>::const_iterator const_iterator;
			typedef typename ft::rb_tree<value_type, value_compare>::reverse_iterator reverse_iterator;
			typedef typename ft::rb_tree<value_type, value_compare>::const_reverse_iterator const_reverse_iterator;

			typedef typename ft::iterator_traits<iterator>::difference_type difference_type; //equivalent to ptrdiff_t
			typedef size_t size_type;

			/*--------CONSTRUCTORS-------*/
			explicit map(const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type())
			{
				_alloc = alloc;
				_keyComp = comp;
				_valComp = value_compare();
			}

			template <class InputIterator>
			map(InputIterator first, InputIterator last,
				const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type())
			{
				_alloc = alloc;
				_keyComp = comp;
				_valComp = value_compare();
				insert(first, last);
			}

			map(const map &x) : _tree(x._tree)
			{
				_alloc = x._alloc;
				_keyComp = x._keyComp;
				_valComp = x._valComp;
			}

			/*
			Not necessary to clear the tree here because
			tree's destructor already do it
			*/
			~map() {}

			map &operator=(const map& x)
			{
				_alloc = x._alloc;
				_keyComp = x._keyComp;
				_valComp = x._valComp;
				_tree = x._tree;
				return *this;
			}

			/*--------ITERATORS-------*/
			iterator begin() { return (_tree.begin()); }
			const_iterator begin() const { return (_tree.begin()); }
			iterator end() { return (_tree.end()); }
			const_iterator end() const { return (_tree.end()); }

			reverse_iterator rbegin() { return _tree.rbegin(); }
			const_reverse_iterator rbegin() const { return _tree.rbegin(); }
			reverse_iterator rend() { return _tree.rend(); }
			const_reverse_iterator rend() const { return _tree.rend(); }

			/*--------CAPACITY-------*/
			bool empty() const { return _tree.size() == 0; }
			size_type size() const { return _tree.size(); }
			size_type max_size() const { return _tree.max_size(); }

			/*--------ELEMENT ACCESS-------*/
			mapped_type& operator[] (const key_type& k)
			{
				return (*((this->insert(ft::make_pair(k,mapped_type()))).first)).second;
			}

			/*--------MODIFIERS-------*/
			pair<iterator,bool> insert(const value_type &val)
			{
				return _tree.insert(val);
			}
			iterator insert(iterator position, const value_type& val)
			{
				return _tree.insert(position, val);
			}
			template <class InputIterator>
			void insert(InputIterator first, InputIterator last)
			{
				while (first != last)
					insert(first, *first++);
			}
			
			void erase (iterator position)
			{
				_tree.erase(position);
			}
			size_type erase (const key_type &k)
			{
				return _tree.erase(ft::make_pair(k, mapped_type()));
			}
			void erase (iterator first, iterator last)
			{
				while (first != last)
					_tree.erase(first++);
			}

			void swap (map& x)
			{
				allocator_type allocTmp = _alloc;
				key_compare keyTmp = _keyComp;
				value_compare valTmp = _valComp;

				_alloc = x._alloc;
				_keyComp = x._keyComp;
				_valComp = x._valComp;

				x._alloc = allocTmp;
				x._keyComp = keyTmp;
				x._valComp = valTmp;

				_tree.swap(x._tree);
			}

			void clear()
			{
				_tree.clear();
			}

			/*--------OBSERVERS-------*/
			key_compare key_comp() const { return _keyComp; }
			value_compare value_comp() const { return _valComp; }

			/*--------OPERATIONS-------*/
			iterator find(const key_type &k)
			{
				return _tree.find(ft::make_pair(k, mapped_type()));
			}
			const_iterator find(const key_type &k) const
			{
				return _tree.find(ft::make_pair(k, mapped_type()));
			}

			size_type count(const key_type &k) const
			{
				return _tree.isIn(ft::make_pair(k, mapped_type()));
			}

			//iterator lower_bound(const key_type &k)
			//{
				
			//}
			//const_iterator lower_bound(const key_type &k) const;

			void print()
			{
				_tree.print();
			}
		private:
			ft::rb_tree<value_type, value_compare> _tree;
			allocator_type _alloc;
			key_compare _keyComp;
			value_compare _valComp;
	};
}

#endif