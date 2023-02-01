#ifndef STL_TREE_HPP
#define STL_TREE_HPP
#include <cstddef>
#include <string>
#include <iostream>
#include <alloca.h>
#include "stl_utility.hpp"
#include "stl_iterator.hpp"
#define BLACK 'b'
#define RED 'r'

#define COR "\033[31m";
#define RES "\033[0m";


namespace ft {
	template <typename Key, typename value_type>
	struct Rb_tree_node {
			typedef Rb_tree_node	Rb_node;
			value_type		_data;
			Rb_node*		parent;
			Rb_node*		left;
			Rb_node*		right;
			char			color;

			Rb_tree_node( void ): parent(NULL), left(NULL), right(NULL), color(BLACK) {};
			Rb_tree_node(
				const value_type& data,
				Rb_node* parent,
				Rb_node* left,
				Rb_node* right,
				char color = RED ): _data(data), parent(parent), left(left), right(right), color(color) {};

			Rb_node *minimum( void ) {
				Rb_node *x = this;
				while (x->left != x->left->parent) { x = x->left; }
				return (x);
			}

			Rb_node *maximum( void ) {
				Rb_node *x = this;
				while (x->right != x->right->parent) { x = x->right; }
				return (x);
			}

			Rb_node* next( void ) {
				Rb_node *x = this;
				if (x->right != x->right->parent) { return x->right->minimum(); }
				Rb_node *y = x->parent;
				while (y != y->right && x == y->right) {
					x = y;
					y = y->parent;
				}
				return y;
			}

            Rb_node* prev( void ) {
                Rb_node *x = this;
                if (x->left != x->left->parent) {
                    return x->left->maximum();
                }
                Rb_node *y = x->parent;
                while (y != y->left && x == y->left) {
                    x = y;
                    y = y->parent;
                }
                return y;
            }
	};

    template <typename Iterator>
    class tree_reverse_iterator {
        private:
            Iterator i;
        public:
            typedef Iterator iterator_type;
            typedef typename ft::iterator_traits<Iterator>::iterator_category iterator_category;
            typedef typename ft::iterator_traits<Iterator>::value_type value_type;
            typedef typename ft::iterator_traits<Iterator>::difference_type difference_type;
            typedef typename ft::iterator_traits<Iterator>::pointer pointer;
            typedef typename ft::iterator_traits<Iterator>::reference reference;

            tree_reverse_iterator(void) : i(NULL) {};
            explicit tree_reverse_iterator(iterator_type it) : i(it) {};
            template <class Iter>
            tree_reverse_iterator(const tree_reverse_iterator<Iter> &rev_it) : i(rev_it.i) {}
            ~tree_reverse_iterator() {};
            tree_reverse_iterator &operator=(tree_reverse_iterator const &rhs) {
                i = rhs.i;
                return (*this);
            };

            iterator_type base() const {return (i);};
            reference operator*() const {
                Iterator it = i;
                return (*--it);
            };
            tree_reverse_iterator operator+(difference_type n) const {return (tree_reverse_iterator(i - n));};
            tree_reverse_iterator operator-(difference_type n) const {return (tree_reverse_iterator(i + n));};
            tree_reverse_iterator &operator++() {
                --i;
                return (*this);
            };
            tree_reverse_iterator    operator++(int) {
                tree_reverse_iterator rev_it(*this);
                --i;
                return (rev_it);
            };
            tree_reverse_iterator &operator+=(difference_type n) {
                i -= n;
                return (*this);
            };
            tree_reverse_iterator &operator-=(difference_type n) {
                i += n;
                return (*this);
            };
            tree_reverse_iterator &operator--() {
                ++i;
                return (*this);
            };
            tree_reverse_iterator    operator--(int) {
                tree_reverse_iterator rev_it(*this);
                ++i;
                return (rev_it);
            };
            pointer operator->() const {return (&(operator*()));};
            reference operator[](difference_type n) const {return (*operator+(n));};
    }; // class tree_reverse_iterator

    template <typename Iterator>
    bool operator==(const tree_reverse_iterator<Iterator> &lhs, const tree_reverse_iterator<Iterator> &rhs) {
        return (lhs.base() == rhs.base());
    }
    template <typename Iterator>
    bool operator!=(const tree_reverse_iterator<Iterator> &lhs, const tree_reverse_iterator<Iterator> &rhs) {
        return (lhs.base() != rhs.base());
    }
    template <typename Iterator>
    bool operator<(const tree_reverse_iterator<Iterator> &lhs, const tree_reverse_iterator<Iterator> &rhs) {
        return (lhs.base() > rhs.base());
    }
    template <typename Iterator>
    bool operator<=(const tree_reverse_iterator<Iterator> &lhs, const tree_reverse_iterator<Iterator> &rhs) {
        return (lhs.base() >= rhs.base());
    }
    template <typename Iterator>
    bool operator>(const tree_reverse_iterator<Iterator> &lhs, const tree_reverse_iterator<Iterator> &rhs) {
        return (lhs.base() < rhs.base());
    }
    template <typename Iterator>
    bool operator>=(const tree_reverse_iterator<Iterator> &lhs, const tree_reverse_iterator<Iterator> &rhs) {
        return (lhs.base() <= rhs.base());
    }

    template <typename Key, typename T>
	class tree_iterator: public ft::iterator<ft::bidirectional_iterator_tag, T> {
		protected:
			typedef tree_iterator						iterator;
			typedef Rb_tree_node<Key, T>				Rb_node;

		private:
			Rb_node* Nil;

			Rb_node* next;
			Rb_node* current;
			Rb_node* prev;

		public:
			tree_iterator( void ): Nil(NULL), next(NULL), current(NULL), prev(NULL) {}

			explicit tree_iterator(Rb_node* x, Rb_node* _prev = NULL): current(x), prev(_prev) {
				Nil = current->minimum()->left;
				if (x != Nil) {
					prev = x->prev();
					next = x->next();
				}
			}

			tree_iterator(const iterator& src): current(src.current) {}

			T& operator*() const { return current->_data; }

			T* operator->() const { return &(operator*()); }

			iterator& operator++() {
				operator++(0);
				return (*this);
			}

			iterator operator++(int) {
				if (current == Nil) {
					current = next;
					next = current->next();
					return (iterator(current->prev()));
				}
				current = current->next();
				next = current->next();
				if (current != Nil) {
					next = current->prev();
				}
				return (iterator(current->prev()));
			}

			iterator& operator--() {
				operator--(0);
				return (*this);
			}

			iterator operator--(int) {
				if (current == Nil) {
					current = prev;
					prev = current->prev();
					return (iterator(current->next()));
				}
				current = current->prev();
				prev = current->prev();
				if (current != Nil) {
					next = current->next();
				}
				return (iterator(next));
			}

			bool operator==(const iterator& x ) const { return current == x.current; }

			bool operator!=(const iterator& x ) const { return current != x.current; }

			~tree_iterator( void ) {}
	};

    template <typename Key, typename value_type, typename Compare = std::less<Key>, typename Alloc = std::allocator<value_type> >
	class Rb_tree {
	public:
		typedef Alloc										allocator_type;
		typedef typename allocator_type::size_type			size_type;
		typedef Compare										key_compare;
		typedef Rb_tree_node<Key, value_type>				Rb_node;
		typedef typename std::allocator<Rb_node>			node_allocator_type;
		typedef ft::tree_iterator<Key, value_type>			iterator;
        typedef ft::tree_iterator<const Key, const value_type>          const_iterator;
        typedef ft::tree_reverse_iterator<iterator>         reverse_iterator;
        typedef ft::tree_reverse_iterator<const_iterator>   const_reverse_iterator;
	public:
		Rb_tree( const key_compare& comp = key_compare() ): _size(0), _comp(comp) {
			Nil = node_allocator.allocate(1);
			node_allocator.construct(Nil, Rb_node());
			Nil->right = Nil;
			Nil->left = Nil;
			Nil->parent = Nil;
			root = Nil;
		}
		Rb_tree( const Rb_tree* x, const key_compare& comp = key_compare() ): _size(x->_size), _comp(comp) {
			Nil = node_allocator.allocate(1);
			node_allocator.construct(Nil, Rb_node());
			Nil->right = Nil;
			Nil->left = Nil;
			Nil->parent = Nil;
			root = copyTree(x->root, Nil);
		}

		Rb_node* copyTree( const Rb_node* node, const Rb_node* Nil ) {
			if (node == node->left) { return (Nil); }
			Rb_node* newNode = node_allocator.allocate(1);
			Rb_node* tmp = node;
			node_allocator.construct(newNode, tmp);

			newNode->left = copyTree(node->left, Nil);
			newNode->right = copyTree(node->right, Nil);
			return (newNode);
		}

		iterator find( const Key& k ) {
			Rb_node* tmp = root;
			while (tmp != Nil) {
				if (_comp(k, tmp->_data.first)) {
					tmp = tmp->left;

				} else if (_comp(tmp->_data.first, k)) {
					tmp = tmp->right;
				} else {
					break;
				}
			}
			return iterator(tmp);
		}

		iterator begin( void ) {
			return (iterator(root->minimum()));
		};

		iterator end( void ) {
			return (iterator(Nil, root->maximum()));
		}

        reverse_iterator rbegin( void ) {
            return (reverse_iterator(iterator(root->maximum())));
        };

        reverse_iterator rend( void ) {
            return (reverse_iterator(iterator(Nil)));
        }

        bool empty( void ) const {
            if (_size == 0)
                return (true);
            return (false);
        }

		size_type size( void ) {
			return (_size);
		}

		size_type countKeys(Rb_node* node, const Key &key) const {
			if (node == Nil) return 0;
			size_type n = 0;
			if (node->_data.first == key) n++;
			n += countKeys(node->left, key);
			n += countKeys(node->right, key);
			return n;
		}

		size_type count( const Key &key )  const{
			size_type n = countKeys(root, key);
			return n;
		}

		iterator insert( value_type data ) {
			Rb_node *y = Nil;
			Rb_node *x = root;

			Rb_node *z = node_allocator.allocate(1);

			node_allocator.construct(z, Rb_node(data, Nil, Nil, Nil));
			while (x != Nil) {
				y = x;
				if (_comp(z->_data.first, x->_data.first)) {
					x = x->left;
				} else { x = x->right; };
			}
			z->parent = y;
			if (y == Nil) {
				root = z;
			} else if(_comp(z->_data.first, y->_data.first)) {
				y->left = z;
			} else {
				y->right = z;
			}
			insertFixup(z);
			_size++;
			return(iterator(z));
		}

		void leftRotate(Rb_node *node) {
			Rb_node *tmp = node->right;
			node->right = tmp->left;
			if (tmp->left != Nil)
				tmp->left->parent = node;
			tmp->parent = node->parent;
			if (node->parent == Nil)
				root = tmp;
			else if (node == node->parent->left)
				node->parent->left = tmp;
			else
				node->parent->right = tmp;
			tmp->left = node;
				node->parent = tmp;
		}

		void rightRotate(Rb_node *node) {
			Rb_node *tmp = node->left;
			node->left = tmp->right;
			if (tmp->right != Nil)
				tmp->right->parent = node;
			tmp->parent = node->parent;
			if (node->parent == Nil)
				root = tmp;
			else if (node == node->parent->right)
				node->parent->right = tmp;
			else
				node->parent->left = tmp;
			tmp->right = node;
			node->parent = tmp;
		}

		void insertFixup(Rb_node *node) {
			while (node->parent->color == RED) {
				if (node->parent == node->parent->parent->left) {
					Rb_node *tmp = node->parent->parent->right;
					if (tmp->color == RED) {
						node->parent->color = BLACK;
						tmp->color = BLACK;
						node->parent->parent->color = RED;
						node = node->parent->parent;
					} else {
						if (node == node->parent->right) {
							node = node->parent;
							leftRotate(node);
						}
						node->parent->color = BLACK;
						node->parent->parent->color = RED;
						rightRotate(node->parent->parent);
					}
				} else {
					Rb_node *tmp = node->parent->parent->left;
					if (tmp->color == RED) {
						node->parent->color = BLACK;
						tmp->color = BLACK;
						node->parent->parent->color = RED;
						node = node->parent->parent;
					} else {
						if (node == node->parent->left) {
							node = node->parent;
							rightRotate(node);
						}
						node->parent->color = BLACK;
						node->parent->parent->color = RED;
						leftRotate(node->parent->parent);
					}
				}
			}
			root->color = BLACK;
		}

		void nodeDelete(Rb_node *node) {
			Rb_node *y = node;
			Rb_node *x;
			char y_originalcolor = y->color;
			if (node->left == Nil) {
				x = node->right;
				transplant(node, node->right);
			} else if (node->right == Nil) {
				x = node->left;
				transplant(node, node->left);
			} else {
				y = node->right->minimum();
				y_originalcolor = y->color;
				x = y->right;
				if (y->parent == node) {
					x->parent = y;
				} else {
					transplant(y, y->right);
					y->right = node->right;
					y->right->parent = y;
				}
				transplant(node, y);
				y->left = node->left;
				y->left->parent = y;
				y->color = node->color;
			}
			if (y_originalcolor == BLACK) {
				deleteFixUp(x);
			}
			_size--;
		}

		void transplant(Rb_node *u, Rb_node *v) {
			if (u->parent == Nil) {
				root = v;
			} else if (u == u->parent->left) {
				u->parent->left = v;
			} else {
				u->parent->right = v;
			}
			v->parent = u->parent;
		}

		void deleteFixUp(Rb_node *x) {
			Rb_node *w;
			while (x != root && x->color == BLACK) {
				if (x == x->parent->left) {
					w = x->parent->right;
					if (w->color == RED) {
						w->color = BLACK;
						x->parent->color = RED;
						leftRotate(x->parent);
						w = x->parent->right;
					}
					if (w->left->color == BLACK && w->right->color == BLACK) {
						w->color = RED;
						x = x->parent;
					} else {
						if (w->right->color == BLACK) {
							w->left->color = BLACK;
							w->color = RED;
							rightRotate(w);
							w = x->parent->right;
						}
						w->color = x->parent->color;
						x->parent->color = BLACK;
						w->right->color = BLACK;
						leftRotate(x->parent);
						x = root;
					}
				}
				else {
					w = x->parent->left;
					if (w->color == RED) {
						w->color = BLACK;
						x->parent->color = RED;
						rightRotate(x->parent);
						w = x->parent->left;
					}
					if (w->right->color == BLACK && w->left->color == BLACK) {
						w->color = RED;
						x = x->parent;
					} else {
						if (w->left->color == BLACK) {
							w->right->color = BLACK;
							w->color = RED;
							leftRotate(w);
							w = x->parent->left;
						}
						w->color = x->parent->color;
						x->parent->color = BLACK;
						w->left->color = BLACK;
						rightRotate(x->parent);
						x = root;
					}
				}
			}
			x->color = BLACK;
		}

		void printTree(Rb_node *root, int level, std::string side) {

			if (root == Nil)
				return;
			printTree(root->right, level + 1, "R");
			for (int i = 0; i < level; i++) {
				std::cout << "      ";
			}
			if (root->color == RED) {
				std::cout << COR;
			}
			std::cout << side << " " << root->_data.first << RES;
			std::cout << std::endl;
			printTree(root->left, level + 1, "L");
		}

		void printBT(void) {
			printTree(root, 0, "ROOT");
		}

		void nodeDestroy(Rb_node *node) {
			node_allocator.destroy(node);
			node_allocator.deallocate(node, 1);
		}

		void clear(Rb_node *node) {
			if (node == Nil)
				return ;
			clear(node->left);
			clear(node->right);
			nodeDestroy(node);
		}

	private:
		node_allocator_type node_allocator;
		Rb_node*	root;
		Rb_node*	Nil;
		size_type	_size;
		key_compare	_comp;
	};


}



#endif
