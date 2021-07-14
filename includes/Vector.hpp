/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 12:32:04 by ldevilla          #+#    #+#             */
/*   Updated: 2021/07/14 13:35:12 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <iostream>
#include <memory>

namespace ft
{
	template <class T, class Alloc = std::allocator<T> >
	class Vector
	{
		public:
			Vector()
			{
				std::cout << "hello i'm vector" << std::endl;
			}
	};
}

#endif