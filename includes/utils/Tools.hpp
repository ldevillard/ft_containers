/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tools.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 12:33:55 by ldevilla          #+#    #+#             */
/*   Updated: 2021/10/12 15:02:19 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_HPP
# define TOOLS_HPP

namespace ft
{

	/*--------EQUAL---------*/
	template <class InputIterator1, class InputIterator2>
	bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
	{
		while (first1 != last1)
		{
			if (*first1 != *first2)
				return false;
			first1++;
			first2++;
		}
		return true;
	}

	template <class InputIterator1, class InputIterator2, class BinaryPredicate>
	bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate pred)
	{
		while (first1 != last1)
		{
			if (!pred(*first1, *first2))
				return false;
			first1++;
			first2++;
		}
		return true;
	}

	/*--------LEXICOGRAPHICAL COMPARE---------*/
	template <class InputIterator1, class InputIterator2>
	bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2)
	{
		while (first1 != last1)
		{
			if (first2 == last2 || *first2 < *first1)
				return false;
			else if (*first1 < *first2)
				return true;
			++first1;
			++first2;
		}
		return first2 != last2;
	}

	template <class InputIterator1, class InputIterator2, class Compare>
	bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, Compare comp)
	{
		while (first1 != last1)
		{
			if (first2 == last2 || comp(*first2, *first1))
				return false;
			else if (comp(*first1, *first2))
				return true;
			++first1;
			++first2;
		}
		return first2 != last2;
	}

	/*--------PAIR---------*/
	template <class T1, class T2>
	struct pair
	{
		public:
			typedef T1 first_type;
			typedef T2 second_type;

			first_type first;
			second_type second;

			pair() : first(), second() {}
			template<class U, class V>
			pair(const pair<U,V>& pr) : first(pr.first), second(pr.second) {}
			pair(const first_type& a, const second_type& b) : first(a), second(b) {}

			pair &operator=(const pair& pr)
			{
				first = pr.first;
				second = pr.second;
				return *this;
			}
	};

	template <class T1, class T2>
	bool operator==(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return lhs.first == rhs.first && lhs.second == rhs.second;
	}
	template <class T1, class T2>
	bool operator!=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return !(lhs == rhs);
	}
	template <class T1, class T2>
	bool operator<(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second);
	}
	template <class T1, class T2>
	bool operator<=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return !(rhs < lhs);
	}
	template <class T1, class T2>
	bool operator>(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return rhs < lhs;
	}
	template <class T1, class T2>
	bool operator>=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return !(lhs < rhs);
	}

	template <class T1,class T2>
	ft::pair<T1,T2> make_pair(T1 x, T2 y)
	{
		return ft::pair<T1,T2>(x,y);
	}

}
#endif