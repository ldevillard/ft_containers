/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBTree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 13:38:02 by ldevilla          #+#    #+#             */
/*   Updated: 2021/10/14 14:59:28 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBTREE_HPP
# define RBTREE_HPP

#include <memory>
#include <functional>
#include "../iterator/RBTIterators.hpp"
#include "../iterator/ReverseIterator.hpp"
#include "Tools.hpp"
#include <iostream> //DEBUG

#define BLACK false
#define RED true

//Great Tutorial for all Binary trees ! https://www.programiz.com/dsa/b-tree
//See my template bst example in the example folder of this repo

namespace ft
{

	template <class T>
	struct node
	{
		typedef T value_type;
		
		node *left;
		node *right;
		node *parent;
		bool color;
		value_type data;

		node(value_type const &src) : data(src){}
	};

	template <class T, class Compare, class Alloc = std::allocator< node<T> > >
	class rb_tree
	{
		public:
			typedef T	value_type;

			typedef Compare key_compare;
			typedef Alloc allocator_type;

			typedef node<value_type> node;
			typedef node *node_ptr;

			typedef ft::red_black_tree_iterators<node> iterator;
			typedef ft::red_black_tree_iterators<const node> const_iterator;
			typedef ft::reverse_iterator<iterator> reverse_iterator;
			typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

			typedef	size_t size_type;

			/*--------CONSTRUCTOR-------*/
			rb_tree(const allocator_type &alloc = allocator_type()) : _comp(key_compare())
			{
				_size = 0;
				_alloc = alloc;
				_NIL = _alloc.allocate(1);
				_alloc.construct(_NIL, value_type());
				_NIL->parent = _NIL;
				_NIL->right = _NIL;
				_NIL->left = _NIL;
				_NIL->color = BLACK;
				_root = _NIL;
			}

			rb_tree(const rb_tree &copy)
			{
				_alloc = copy._alloc;
				_comp = copy._comp;
				_size = copy._size;
				_NIL = _alloc.allocate(1);
				_NIL->parent = _NIL;
				_NIL->right = _NIL;
				_NIL->left = _NIL;
				_NIL->color = BLACK;

				_root = _NIL;
				_deepCopy(*this, copy._root, copy._NIL);
			}

			~rb_tree()
			{
				clear();
				_alloc.destroy(_NIL);
				_alloc.deallocate(_NIL, 1);
			}

			void print()
			{
				if (_root != _NIL)
					_deepPrint(_root, "", true);
				std::cout << "size : " << size() << std::endl;
			}

			void clear()
			{
				_deepClear(_root);
				_root = _NIL;
				_size = 0;
			}

			size_type size() const
			{
				return _size;
			}

			size_type max_size() const
			{
				return _alloc.max_size();
			}

			ft::pair<iterator,bool> insert(const value_type &val)
			{
				node_ptr newNode = _newNode(val);
				
				ft::pair<node_ptr, bool> ret = _deepInsert(_root, newNode);

				if (ret.second)
				{
					_size++;
					if (newNode->parent == _NIL)
						newNode->color = BLACK;
					else
						_insertFix(newNode);
					//root may be changed after fixing the tree so fix it
					_root = _getRoot(newNode);
					//std::cout << newNode->data.second << std::endl;
					return ft::make_pair(iterator(newNode, _root, _NIL), true);
				}
				else
				{
					_alloc.destroy(newNode);
					_alloc.deallocate(newNode, 1);
					//std::cout << newNode->data.second << std::endl;
					return ft::make_pair(iterator(ret.first, _root, _NIL), false);
				}
			}

		private:
			void _deepPrint(node_ptr root, std::string indent, bool last)
			{
				if (root != _NIL)
				{
					std::cout << indent;
					if (last)
					{
						std::cout << "R----";
						indent += "   ";
					}
					else
					{
						std::cout << "L----";
						indent += "|  ";
					}

					std::cout << root->data.second << std::endl;
					_deepPrint(root->left, indent, false);
					_deepPrint(root->right, indent, true);
				}
			}

			node_ptr _getRoot(node_ptr n)
			{
				node_ptr tmp = n;

				while (tmp->parent != _NIL)
					tmp = tmp->parent;

				return tmp;
			}

			void _deepCopy(rb_tree &tree_dst, node_ptr root_src, node_ptr nil_src)
			{
				if (root_src != nil_src)
				{
					_deepCopy(tree_dst, root_src->left, nil_src);
					tree_dst.insert(root_src->data);
					_deepCopy(tree_dst, root_src->right, nil_src);
				}
			}

			void _deepClear(node_ptr src = NULL)
			{
				if (src == NULL)
					src = _root;
				if (src != _NIL)
				{
					_deepClear(src->left);
					_deepClear(src->right);
					_alloc.destroy(src);
					_alloc.deallocate(src, 1);
				}
			}

			ft::pair<node_ptr, bool> _deepInsert(node_ptr root, node_ptr n)
			{
				if (root != _NIL && _comp(n->data, root->data))
				{
					if (root->left != _NIL)
						return _deepInsert(root->left, n);
					else
						root->left = n;
				}
				else if (root != _NIL && _comp(root->data, n->data))
				{
					if (root->right != _NIL)
						return _deepInsert(root->right, n);
					else
						root->right = n;
				}
				else if (root != _NIL)
					return ft::make_pair(root, false);
				n->parent = root;
				n->color = RED;
				n->left = _NIL;
				n->right = _NIL;
				return ft::make_pair(n, true);
			}

			node_ptr _newNode(const value_type &data)
			{
				node_ptr newNode = _alloc.allocate(1);
				_alloc.construct(newNode, data);
				newNode->color = RED;
				newNode->left = _NIL;
				newNode->right = _NIL;
				newNode->parent = _NIL;
				return newNode;
			}

			void _leftRotate(node_ptr x)
			{
				node_ptr y = x->right;
				x->right = y->left;
				if (y->left != _NIL)
					y->left->parent = x;

				y->parent = x->parent;
				if (x->parent == _NIL)
					this->_root = y;
				else if (x == x->parent->left)
					x->parent->left = y;
				else
					x->parent->right = y;

				y->left = x;
				x->parent = y;
			}

			void _rightRotate(node_ptr x)
			{
				node_ptr y = x->left;
				x->left = y->right;
				if (y->right != _NIL)
					y->right->parent = x;

				y->parent = x->parent;
				if (x->parent == _NIL)
					this->_root = y;
				else if (x == x->parent->right)
					x->parent->right = y;
				else
					x->parent->left = y;

				y->right = x;
				x->parent = y;
			}

			void _insertFix(node_ptr k)
			{
				node_ptr u;

				while (k->parent->color == RED)
				{
					if (k->parent == k->parent->parent->right)
					{
						u = k->parent->parent->left;
						if (u->color == RED)
						{
							u->color = BLACK;
							k->parent->color = BLACK;
							k->parent->parent->color = RED;
							k = k->parent->parent;
						}
						else
						{
							if (k == k->parent->left)
							{
								k = k->parent;
								_rightRotate(k);
							}
							k->parent->color = BLACK;
							k->parent->parent->color = RED;
							_leftRotate(k->parent->parent);
						}
					}
					else
					{
						u = k->parent->parent->right;

						if (u->color == RED)
						{
							u->color = BLACK;
							k->parent->color = BLACK;
							k->parent->parent->color = RED;
							k = k->parent->parent;
						}
						else
						{
							if (k == k->parent->right)
							{
								k = k->parent;
								_leftRotate(k);
							}
							k->parent->color = BLACK;
							k->parent->parent->color = RED;
							_rightRotate(k->parent->parent);
						}
					}
					if (k == _root)
						break;
				}
				_root->color = BLACK;
			}

			node_ptr _root;
			node_ptr _NIL;
			size_type _size;
			allocator_type _alloc;
			key_compare _comp;
	};
}

#endif