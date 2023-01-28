#ifndef STL_TREE_HPP
# define STL_TREE_HPP

#include <cstddef>
#include <string>
#include <iostream>
#include <alloca.h>
#include "stl_utility.hpp"

#define BLACK 'b'
#define RED 'r'

namespace ft {

	template <typename Key, typename value_type>
    struct Rb_node {
		public:
			Key				_key;
			value_type		_data;
			Rb_node*		_parent;
			Rb_node*		_left;
			Rb_node*		_right;
			char			_color;

			Rb_node( void ):
				_parent(this), _left(this), _right(this), _color(BLACK) {};
			Rb_node( value_type& data, Rb_node* parent, Rb_node* left, Rb_node* right, char color = RED ): _data(data), _parent(parent), _left(left), _right(right), _color(color) {};

	};

	// template<typename Key, typename value_type, typename _KeyOfValue, typename _Compare, typename _Alloc = allocator<_Val> >
	template <typename Key, typename value_type, typename Compare = std::less<Key>, typename Alloc = std::allocator<value_type> >
	class Rb_tree {
		public:
			typedef	Rb_node<Key, value_type> Rb_type;

			Rb_type* root;
			Rb_type* Nil;
			typedef Alloc					allocator_type;

			Rb_tree( void ): root(NULL) {
				Nil = new Rb_type;
				root = Nil;
			}

			void insert(value_type data) {
				if (root == Nil) {
					root = new Rb_type(data, Nil, Nil, Nil);
				} else {
                    Rb_type *tmp = root;
                    while (tmp != Nil) {
                        if (data.first == tmp->_data.first) {
                            tmp->_data.second = data.second;
                            return ;
                        }
                        if (data.first < tmp->_data.first) {
                            if (tmp->_left == Nil) {
                                tmp->_left = new Rb_type(data, tmp, Nil, Nil);
                                return ;
                            }
                            else
                                tmp = tmp->_left;
                        } else {
                            if (tmp->_right == Nil) {
                                tmp->_right = new Rb_type(data, tmp, Nil, Nil);
                                return ;
                            }
                            else
                                tmp = tmp->_right;
                        }
                    }
				}
			}

            void inOrderTraversal(Rb_type *root) {
                if (root == Nil) return;
                inOrderTraversal(root->_left);
                std::cout << "(" << root->_data.first << ", " << root->_data.second << ")" << " ";
                inOrderTraversal(root->_right);
            }

            void printRedBlackTree(void) {
                inOrderTraversal(root);
                std::cout << std::endl;
            }

            void printTree(Rb_type *root, int level, std::string side) {
                if (root == Nil)
                    return;
                printTree(root->_right, level + 1, "R");
                for (int i = 0; i < level; i++) {
                    std::cout << "        ";
                }
                std::cout << side << " " << root->_data.first << ":" << root->_data.second;
                if (root->_color == RED) {
                    std::cout << " (RED)" << std::endl;
                } else {
                    std::cout << " (BLACK)" << std::endl;
                }
                printTree(root->_left, level + 1, "L");
            }

            void printBT(void)
            {
                printTree(root, 0, "ROOT");
            }

	};

}

#endif
