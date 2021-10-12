/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 15:35:20 by ldevilla          #+#    #+#             */
/*   Updated: 2021/10/12 16:51:45 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include <functional>
#include <memory>
#include "../utils/Tools.hpp"
#include "../utils/AVLTree.hpp"

namespace ft
{
	template < class Key, class T,
	class Compare = std::less<Key>,
	class Alloc = std::allocator<ft::pair<const Key,T> > >
	class map
	{
		
	};
}

#endif