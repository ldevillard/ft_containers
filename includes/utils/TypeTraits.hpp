/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TypeTraits.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 11:33:48 by ldevilla          #+#    #+#             */
/*   Updated: 2021/10/07 12:39:40 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPETRAITS_HPP
# define TYPETRAITS_HPP

namespace ft
{
	//-----------ENABLE_IF---------------
	template<bool B, class T = void>
	struct enable_if {};

	template<class T>
	struct enable_if<true, T> { typedef T type; };

	//-----------IS_INTEGRAL---------------
	template <class T> struct is_integral { static const bool value = false; };
	template <> struct is_integral<bool> { static const bool value = true; };
	template <> struct is_integral<char> { static const bool value = true; };
	template <> struct is_integral<signed char> { static const bool value = true; };
	template <> struct is_integral<unsigned char> { static const bool value = true; };
	template <> struct is_integral<wchar_t> { static const bool value = true; };
	template <> struct is_integral<short> { static const bool value = true; };
	template <> struct is_integral<int> { static const bool value = true; };
	template <> struct is_integral<long> { static const bool value = true; };
	template <> struct is_integral<long long> { static const bool value = true; };
	template <> struct is_integral<unsigned short> { static const bool value = true; };
	template <> struct is_integral<unsigned int> { static const bool value = true; };
	template <> struct is_integral<unsigned long> { static const bool value = true; };
	template <> struct is_integral<unsigned long long> { static const bool value = true; };
}

#endif