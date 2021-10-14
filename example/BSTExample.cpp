/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BSTExample.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 09:42:22 by ldevilla          #+#    #+#             */
/*   Updated: 2021/10/14 14:12:14 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <functional>
#include <string>
#include <memory>

/*
bst class have to be in a .hpp file
but for the example and the comprehension
i made it in one file
*/
template <class Key, class T>
class bst
{
	public:
		typedef T		value_type;
		typedef Key		key_type;
		typedef size_t	size_type;

		struct node
		{
			key_type			key;
			value_type	data;
			node		*left;
			node		*right;
			node		*parent;
		};

		typedef node *node_ptr;

		bst() : _size(0), _root(NULL) {}

		/*
		This type of copy isn't very powerful
		because the nodes dare copied in the order
		so the copy will be a simple linked list
		finally it works perfectly but
		the tree concept is broken.
		This type of copy work with a balanced tree.
		I just made it for coplien's form
		*/
		bst(const bst &cpy) : _root(NULL), _size(cpy._size)
		{
			_deepCopy(*this, cpy._root);
		}

		~bst()
		{
			clear();
		}

		/* Same as copy constructor */
		bst &operator=(const bst &cpy)
		{
			_deepCopy(*this, cpy._root);
			return *this;
		}

		int size() { return _size; }

		void remove(key_type key)
		{
			if (!_exist(_root, key)) /* Check if the key exit in the tree */
			{
				std::cout << "Error: node <"<< key << "> not exist!" << std::endl;
				return;
			}
			_root = _deepRemove(_root, key); /* Then if so -> remove it */
		}

		void insert(key_type key, value_type val)
		{
			node_ptr n = _new_node(key, val);
			node_ptr tmp = _root;
			node_ptr buf = NULL;
			/*
			Find the place where the new node should be.
			If it's still exist just delete the new node and do nothing.
			Maybe overwrite the node can be an option
			*/
			while (tmp != NULL)
			{
				buf = tmp;
				if (n->key < tmp->key)
					tmp = tmp->left;
				else if (n->key > tmp->key)
					tmp = tmp->right;
				else
				{
					std::cout << "Error: node <"<< key << "> already exist!" << std::endl;
					delete n;
					return ;
				}
			}

			/* Then setup the node and inc _size */
			n->parent = buf;
			if (buf == NULL)
				_root = n;
			else if (n->key < buf->key)
				buf->left = n;
			else
				buf->right = n;
			_size++;
		}

		void clear()
		{
			_deepClear(_root);
			_size = 0;
		}

		void print()
		{
			if (_root != NULL)
				_deepPrint(_root, "", true);
			std::cout << "size : " << size() << std::endl;
		}

		node &operator[] (key_type)
		{
			
		}

	private:
		void _deepCopy(bst &dest, node_ptr root_src)
		{
			if (root_src != NULL)
			{
				_deepCopy(dest, root_src->left);
				dest.insert(root_src->key, root_src->data);
				_deepCopy(dest, root_src->right);
			}
		}

		node_ptr _min(node_ptr root)
		{
			node_ptr tmp = root;

			if (tmp == NULL)
				return NULL;

			while (tmp->left != NULL)
				tmp = tmp->left;
			return tmp;
		}

		node_ptr _find(node_ptr root, key_type key)
		{
			node_ptr tmp = root;

			if (!_exist(root, key))
				return NULL;

			while (tmp != NULL)
			{
				if (key == tmp->key)
					return tmp;
				else if (key < tmp->key)
					tmp = tmp->left;
				else
					tmp = tmp->right;
			}
		}

		bool		_exist(node_ptr root, key_type key)
		{
			node_ptr tmp = root;

			while (tmp != NULL)
			{
				if (key == tmp->key)
					return true;
				else if (key < tmp->key)
					tmp = tmp->left;
				else
					tmp = tmp->right;
			}
			return false;
		}

		node_ptr	_deepRemove(node_ptr root, key_type key)
		{
			if (root == NULL) return root;
			/* Find the node to be deleted */
			if (key < root->key)
				root->left = _deepRemove(root->left, key);
			else if (key > root->key)
				root->right = _deepRemove(root->right, key);
			else
			{
				/*
				CASE 1 - if the node is with only one child or no child 
				Exchange the content of root and delete it
				*/
				if (root->left == NULL)
				{
					node_ptr temp = root->right;
					delete root;
					return temp;
				}
				else if (root->right == NULL)
				{
					node_ptr temp = root->left;
					delete root;
					return temp;
				}
				/*
				CASE 2 - if the node has two children
				Exchange the content of root with the min node of right child
				*/
				node_ptr temp = _min(root->right);

				root->key = temp->key;
				root->data = temp->data;
				
				/* Then remove the min of right child */
				root->right = _deepRemove(root->right, temp->key);
			}
			_size--;
			return root;
		}

		void	_deepPrint(node_ptr root, std::string indent, bool last)
		{
			if (root != NULL)
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

				std::cout << root->data << std::endl;
				_deepPrint(root->left, indent, false);
				_deepPrint(root->right, indent, true);
			}
		}

		void	_deepClear(node_ptr src = NULL)
		{
			if (src == NULL)
				_root = src;
			if (src != NULL)
			{
				_deepClear(src->left);
				_deepClear(src->right);
				delete src;
			}
		}

		node_ptr _new_node(key_type key, value_type val)
		{
			node_ptr ret = new node;

			ret->left = NULL;
			ret->right = NULL;
			ret->parent = NULL;
			ret->key = key;
			ret->data = val;

			return ret;
		}

		node_ptr _root;
		size_type _size;
};

int main()
{
	bst<std::string, int> age;
	
	age.insert("logan", 19);
	age.insert("bob", 23);
	age.insert("berty", 43);
	age.insert("tom", 12);
	age.insert("john", 4);

	age.print();
	age.insert("berty", 43); /* Get an error */

	std::cout << "\n-------------\n\n";

	age.clear();
	
	age.insert("tom", 12);
	age.insert("john", 4);
	age.insert("logan", 19);
	age.remove("john");

	age.print();
	age.remove("john"); /* Get an error */
}