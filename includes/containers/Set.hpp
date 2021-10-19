/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 10:44:56 by ldevilla          #+#    #+#             */
/*   Updated: 2021/10/19 12:11:06 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_HPP
# define SET_HPP

#include <functional>
#include <memory>
#include "../utils/Tools.hpp"
#include "../utils/RBTree.hpp"
#include "../iterator/IteratorTraits.hpp"

namespace ft
{
	template < class T, class Compare = std::less<T>, class Alloc = std::allocator<T> >
	class set
	{
		public:
			/*--------MEMBER TYPES-------*/
			typedef T key_type;
			typedef T value_type;
			typedef Compare key_compare;
			typedef Compare value_compare;
			
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
			explicit set(const key_compare &comp = key_compare(),
				const allocator_type &alloc = allocator_type())
			{
				_comp = comp;
				_alloc = alloc;
			}

			template <class InputIterator>
			set(InputIterator first, InputIterator last, const key_compare &comp = key_compare(),
				const allocator_type &alloc = allocator_type())
			{
				_comp = comp;
				_alloc = alloc;
				insert(first, last);
			}

			set(const set &x) : _tree(x._tree)
			{
				_comp = x._comp;
				_alloc = x._alloc;
			}
			
			/*
			Not necessary to clear the tree here because
			tree's destructor already do it
			*/
			~set() {}

			set &operator=(const set& x)
			{
				_alloc = x._alloc;
				_comp = x._comp;
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
					_tree.insert(*first++);
			}
			
			void erase(iterator position)
			{
				_tree.erase(position);
			}
			size_type erase(const value_type &k)
			{
				return _tree.erase(k);
			}
			void erase (iterator first, iterator last)
			{
				while (first != last)
					_tree.erase(first++);
			}

			void swap (set& x)
			{
				allocator_type allocTmp = _alloc;
				key_compare keyTmp = _comp;

				_alloc = x._alloc;
				_comp = x._comp;

				x._alloc = allocTmp;
				x._comp = keyTmp;

				_tree.swap(x._tree);
			}

			void clear()
			{
				_tree.clear();
			}

			/*--------OBSERVERS-------*/
			key_compare key_comp() const { return _comp; }
			value_compare value_comp() const { return _comp; }

			/*--------OPERATIONS-------*/
			iterator find(const key_type &k)
			{
				return _tree.find(k);
			}
			const_iterator find(const key_type &k) const
			{
				return _tree.find(k);
			}

			size_type count(const key_type &k) const
			{
				return _tree.isIn(k);
			}

			iterator lower_bound(const key_type &k)
			{
				return _tree.lower_bound(k);
			}

			const_iterator lower_bound(const key_type &k) const
			{
				return _tree.lower_bound(k);
			}

			iterator upper_bound(const key_type &k)
			{
				return _tree.upper_bound(k);
			}

			const_iterator upper_bound(const key_type &k) const
			{
				return _tree.upper_bound(k);
			}

			ft::pair<iterator,iterator> equal_range(const key_type &k)
			{
				iterator low = lower_bound(k);
				iterator up = upper_bound(k);
				return ft::make_pair(low, up);
			}
			ft::pair<const_iterator,const_iterator> equal_range(const key_type &k) const
			{
				const_iterator low = lower_bound(k);
				const_iterator up = upper_bound(k);
				return ft::make_pair(low, up);
			}

			/*--------ALLOCATOR-------*/
			allocator_type get_allocator() const { return _alloc; }

		private:
			ft::rb_tree<value_type, value_compare> _tree;
			allocator_type _alloc;
			key_compare _comp;
	};

	template <class Key, class Compare, class Alloc>
	bool operator==(const ft::set<Key, Compare, Alloc> &lhs, const ft::set<Key, Compare, Alloc> &rhs)
	{
		if (lhs.size() == rhs.size())
			return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
		return false;
	}

	template <class Key, class Compare, class Alloc>
	bool operator!=(const ft::set<Key, Compare, Alloc> &lhs, const ft::set<Key, Compare, Alloc> &rhs)
	{
		return !(lhs == rhs);
	}

	template <class Key, class Compare, class Alloc>
	bool operator<(const ft::set<Key, Compare, Alloc> &lhs, const ft::set<Key, Compare, Alloc> &rhs)
	{
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	template <class Key, class Compare, class Alloc>
	bool operator<=(const ft::set<Key, Compare, Alloc> &lhs, const ft::set<Key, Compare, Alloc> &rhs)
	{
		return !(rhs < lhs);
	}

	template <class Key, class Compare, class Alloc>
	bool operator>(const ft::set<Key, Compare, Alloc> &lhs, const ft::set<Key, Compare, Alloc> &rhs)
	{
		return rhs < lhs;
	}

	template <class Key, class Compare, class Alloc>
	bool operator>=(const ft::set<Key, Compare, Alloc> &lhs, const ft::set<Key, Compare, Alloc> &rhs)
	{
		return !(lhs < rhs);
	}

	template <class Key, class Compare, class Alloc>
	void swap(ft::set<Key, Compare, Alloc> &lhs, ft::set<Key, Compare, Alloc> &rhs)
	{
		lhs.swap(rhs);
	}
}

#endif
