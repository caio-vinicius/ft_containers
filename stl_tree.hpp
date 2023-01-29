#ifndef STL_TREE_HPP
#define STL_TREE_HPP

#include <cstddef>
#include <string>
#include <iostream>
#include <alloca.h>
#include "stl_utility.hpp"
#define BLACK 'b'
#define RED 'r'

#define COR "\033[31m";
#define RES "\033[0m";


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

            typedef Rb_node<Key, value_type> Rb_node_type;

			Rb_node( void ): _parent(this), _left(this), _right(this), _color(BLACK) {};
			Rb_node( const value_type& data, Rb_node* parent, Rb_node* left, Rb_node* right, char color = RED ): _data(data), _parent(parent), _left(left), _right(right), _color(color) {};

            Rb_node_type *minimum(Rb_node_type *node, Rb_node_type *Nil) {
                while (node->_left != Nil)
                    node = node->_left;
                return node;
            }

            Rb_node_type *maximum(Rb_node_type *node, Rb_node_type *Nil) {
                while (node->_right != Nil)
                    node = node->_right;
                return node;
            }

            static Rb_node_type *next(Rb_node_type *node, Rb_node_type *Nil) {
                if (node->_right != Nil) {
                    node = node->_right;
                    while (node->_left != Nil)
                        node = node->_left;
                }
                else {
                    Rb_node_type *parent = node->_parent;
                    while (node == parent->_right) {
                        node = parent;
                        parent = parent->_parent;
                    }
                    if (node->_right != parent)
                        node = parent;
                }
                return node;
            }

            Rb_node_type *prev(Rb_node_type *node, Rb_node_type *Nil) {
                if (node->_color == RED && node->_parent->_parent == node)
                    node = node->_right;
                else if (node->_left != Nil) {
                    node = node->_left;
                    while (node->_right != Nil)
                        node = node->_right;
                }
                else {
                    Rb_node_type *parent = node->_parent;
                    while (node == parent->_left) {
                        node = parent;
                        parent = parent->_parent;
                    }
                    node = parent;
                }
                return node;
            }
    }; // Rb_node

	template <typename Key, typename value_type, typename Compare = std::less<Key>, typename Alloc = std::allocator<value_type> >
	class Rb_tree {
	public:
		typedef Rb_node<Key, value_type>                Rb_node_type;
		typedef Alloc                                   allocator_type;
		typedef typename std::allocator<Rb_node_type>   _node_allocator_type;

		Rb_node_type* root;
		Rb_node_type* Nil;
	private:
		_node_allocator_type _node_allocator;

	public:

		Rb_tree(void): root(NULL) {
            Nil = _node_allocator.allocate(1);
            _node_allocator.construct(Nil, Rb_node_type());
			root = Nil;
		}

        ~Rb_tree(void) {
            _node_allocator.destroy(Nil);
            _node_allocator.deallocate(Nil, 1);
        }

		void insert(value_type data) {
			Rb_node_type *y = Nil;
			Rb_node_type *x = root;

			Rb_node_type *z = _node_allocator.allocate(1);
			_node_allocator.construct(z, Rb_node_type(data, Nil, Nil, Nil));
			while (x != Nil) {
				y = x;
				if (Compare()(z->_data.first, x->_data.first)) {
					x = x->_left;
				} else { x = x->_right; };
			}
			z->_parent = y;
			if (y == Nil) {
				root = z;
			} else if(Compare()(z->_data.first, y->_data.first)) {
				y->_left = z;
			} else {
				y->_right = z;
			}
			insertFixup(z);
		}

		void leftRotate(Rb_node_type *node) {
			Rb_node_type *tmp = node->_right;
			node->_right = tmp->_left;
			if (tmp->_left != Nil)
				tmp->_left->_parent = node;
			tmp->_parent = node->_parent;
			if (node->_parent == Nil)
				root = tmp;
			else if (node == node->_parent->_left)
				node->_parent->_left = tmp;
			else
				node->_parent->_right = tmp;
			tmp->_left = node;
				node->_parent = tmp;
		}

		void rightRotate(Rb_node_type *node) {
			Rb_node_type *tmp = node->_left;
			node->_left = tmp->_right;
			if (tmp->_right != Nil)
				tmp->_right->_parent = node;
			tmp->_parent = node->_parent;
			if (node->_parent == Nil)
				root = tmp;
			else if (node == node->_parent->_right)
				node->_parent->_right = tmp;
			else
				node->_parent->_left = tmp;
			tmp->_right = node;
			node->_parent = tmp;
		}

		void insertFixup(Rb_node_type *node) {
			while (node->_parent->_color == RED) {
				if (node->_parent == node->_parent->_parent->_left) {
					Rb_node_type *tmp = node->_parent->_parent->_right;
					if (tmp->_color == RED) {
						node->_parent->_color = BLACK;
						tmp->_color = BLACK;
						node->_parent->_parent->_color = RED;
						node = node->_parent->_parent;
					} else {
						if (node == node->_parent->_right) {
							node = node->_parent;
							leftRotate(node);
						}
						node->_parent->_color = BLACK;
						node->_parent->_parent->_color = RED;
						rightRotate(node->_parent->_parent);
					}
				} else {
					Rb_node_type *tmp = node->_parent->_parent->_left;
					if (tmp->_color == RED) {
						node->_parent->_color = BLACK;
						tmp->_color = BLACK;
						node->_parent->_parent->_color = RED;
						node = node->_parent->_parent;
					} else {
						if (node == node->_parent->_left) {
							node = node->_parent;
							rightRotate(node);
						}
						node->_parent->_color = BLACK;
						node->_parent->_parent->_color = RED;
						leftRotate(node->_parent->_parent);
					}
				}
			}
			root->_color = BLACK;
		}

		Rb_node_type *treeMinimum(Rb_node_type *x) {
			while (x->_left != Nil) {
				x = x->_left;
			}
			return (x);
		}

		void nodeDelete(Rb_node_type *node) {
            Rb_node_type *y = node;
            Rb_node_type *x;
            char y_original_color = y->_color;
            if (node->_left == Nil) {
                x = node->_right;
                transplant(node, node->_right);
            } else if (node->_right == Nil) {
                x = node->_left;
                transplant(node, node->_left);
            } else {
                y = treeMinimum(node->_right);
                y_original_color = y->_color;
                x = y->_right;
                if (y->_parent == node) {
                    x->_parent = y;
                } else {
                    transplant(y, y->_right);
                    y->_right = node->_right;
                    y->_right->_parent = y;
                }
                transplant(node, y);
                y->_left = node->_left;
                y->_left->_parent = y;
                y->_color = node->_color;
            }
            if (y_original_color == BLACK) {
                deleteFixUp(x);
            }
		}

		void transplant(Rb_node_type *u, Rb_node_type *v) {
            if (u->_parent == Nil) {
                root = v;
            } else if (u == u->_parent->_left) {
                u->_parent->_left = v;
            } else {
                u->_parent->_right = v;
            }
            v->_parent = u->_parent;
        }

		void deleteFixUp(Rb_node_type *x) {
			Rb_node_type *w;
			while (x != root && x->_color == BLACK) {
				if (x == x->_parent->_left) {
					w = x->_parent->_right;
					if (w->_color == RED) {
						w->_color = BLACK;
						x->_parent->_color = RED;
						leftRotate(x->_parent);
						w = x->_parent->_right;
					}
					if (w->_left->_color == BLACK && w->_right->_color == BLACK) {
						w->_color = RED;
						x = x->_parent;
					} else {
						if (w->_right->_color == BLACK) {
							w->_left->_color = BLACK;
							w->_color = RED;
							rightRotate(w);
							w = x->_parent->_right;
						}
						w->_color = x->_parent->_color;
						x->_parent->_color = BLACK;
						w->_right->_color = BLACK;
						leftRotate(x->_parent);
						x = root;
					}
				}
				else {
					w = x->_parent->_left;
					if (w->_color == RED) {
						w->_color = BLACK;
						x->_parent->_color = RED;
						rightRotate(x->_parent);
						w = x->_parent->_left;
					}
					if (w->_right->_color == BLACK && w->_left->_color == BLACK) {
						w->_color = RED;
						x = x->_parent;
					} else {
						if (w->_left->_color == BLACK) {
							w->_right->_color = BLACK;
							w->_color = RED;
							leftRotate(w);
							w = x->_parent->_left;
						}
						w->_color = x->_parent->_color;
						x->_parent->_color = BLACK;
						w->_left->_color = BLACK;
						rightRotate(x->_parent);
						x = root;
					}
				}
			}
			x->_color = BLACK;
		}

		void printTree(Rb_node_type *root, int level, std::string side) {
			if (root == Nil)
				return;
			printTree(root->_right, level + 1, "R");
			for (int i = 0; i < level; i++) {
				std::cout << "      ";
			}
			if (root->_color == RED) {
				std::cout << COR;
			}
			std::cout << side << " " << root->_data.first << RES;
			std::cout << std::endl;
			printTree(root->_left, level + 1, "L");
		}

		void printBT(void) {
			printTree(root, 0, "ROOT");
		}

        void nodeDestroy(Rb_node_type *node) {
            _node_allocator.destroy(node);
            _node_allocator.deallocate(node, 1);
        }

        void clear(Rb_node_type *node) {
            if (node == Nil)
                return ;
            clear(node->_left);
            clear(node->_right);
            nodeDestroy(node);
        }

        void printInorder(Rb_node_type *node) {
            if (node == Nil)
                return;
            printInorder(node->_left);
            std::cout << node->_data.first << " ";
            printInorder(node->_right);
        }
	};
}

#endif
