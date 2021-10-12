/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AVLTree.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 13:38:02 by ldevilla          #+#    #+#             */
/*   Updated: 2021/10/12 17:03:36 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef AVLTREE_HPP
# define AVLTREE_HPP

#include <memory>

namespace ft
{
	template <class T, class Compare, class Alloc = std::allocator<T> >
	class Tree
	{
		public:
			typedef T	value_type;
			typedef typename value_type::first_type	key_type;
			typedef typename value_type::second		data_type;
			
			typedef Compare compare;
			typedef Alloc allocator_type;

			typedef value_type&			reference;
			typedef const value_type& 	const_reference;
			typedef	value_type*			pointer;
			typedef	const value_type*	const_pointer;
			
			typedef	size_t size_type;

			struct Node
			{
				public:
					value_type	content;
					Node		*left;
					Node		*right;
					Node		*parent;

					Node *root()
					{
						Node *tmp = this;
						while (tmp->parent)
							tmp = tmp->parent;
						return tmp;
					}

					Node *min()
					{
						Node *tmp = this;
						while (tmp->left)
							tmp = tmp->left;
						return tmp;
					}

					Node *max()
					{
						Node *tmp = this;
						while (tmp->right)
							tmp = tmp->right;
						return tmp;
					}

				private:
					Node *_root;

			};

			
			int size(Node *n)
			{
				size_type i = 0;
				if (n)
				{
					i += size(n->left);
					i += size(n->right);
					i++;
				}
				return i;
			}

	};
}

#endif