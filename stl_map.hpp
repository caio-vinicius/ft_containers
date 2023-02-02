#ifndef STL_MAP_HPP
# define STL_MAP_HPP

#include "tests.hpp"
#include "stl_utility.hpp"
#include "stl_functional.hpp"
#include "stl_tree.hpp"

namespace ft {
	template <typename Key, typename T, typename Compare = std::less<Key>, typename Alloc = std::allocator<ft::pair<const Key,T> > >
	class map {
		public:
            typedef Key	key_type;
			typedef T	mapped_type;
			typedef ft::pair<const Key, T>						value_type;
			typedef Compare										key_compare;
			typedef Alloc										allocator_type;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;

            class value_compare : public ft::binary_function<value_type, value_type, bool> {
				friend class map<Key, T, Compare, Alloc>;
				protected:
					Compare comp;
					value_compare(Compare c) : comp(c) {}
				public:
					typedef bool result_type;
					typedef value_type first_argument_type;
					typedef value_type second_argument_type;

					bool operator()(const value_type &x, const value_type &y) const {
						return comp(x.first, y.first);
					}
			};

			typedef ft::Rb_tree<key_type, value_type, key_compare, allocator_type> Rb_type;
			typedef typename Rb_type::iterator iterator;
            typedef typename Rb_type::const_iterator const_iterator;
			typedef typename Rb_type::reverse_iterator reverse_iterator;
            typedef typename Rb_type::const_reverse_iterator const_reverse_iterator;
			typedef typename Rb_type::size_type size_type;

			explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()): _comp(comp), _alloc(alloc) {};
			map(const map &x): rb_tree(x.rb_tree), _comp(x._comp), _alloc(x._alloc) {};
			template <class InputIterator>
			map(InputIterator first, InputIterator last, const key_compare &comp = key_compare(), const allocator_type& alloc = allocator_type()) : _comp(comp), _alloc(alloc) {
                for (; first != last; first++) {
					insert(*first);
				}
            }

            ~map() {};

            map &operator=(const map &rhs) {
                rb_tree = rhs.rb_tree;
                _comp = rhs._comp;
                _alloc = rhs._alloc;
                return (*this);
            }

			pair<iterator, bool> insert (const value_type& val) {
				iterator it = find(val.first);
				if ( it != end() )
					return(ft::make_pair<iterator, bool>(it, false));
				return(ft::make_pair<iterator, bool>(rb_tree.insert(val), true));
			}

            iterator insert(iterator position, const value_type& val) {
                (void)position;
                return (insert(val).first);
            }

            template <class InputIterator>
            void insert(InputIterator first, InputIterator last) {
                for (; first != last; first++)
                    insert(*first);
            }

            void erase(iterator position) {
				rb_tree.nodeDelete(position.base());
			}

			size_type erase(const key_type& k) {
				size_type n = count(k);
				iterator it = find(k);
				if (n) {
					rb_tree.nodeDelete(it.base());
				}
				return (n);
			}

			void erase(iterator first, iterator last) {
				for (; first != last; first++) {
					erase(first);
				}
			}

            void swap(map& x) {
                rb_tree.swap(x.rb_tree);
            }

            key_compare key_comp() const {
                return (_comp);
            }

            value_compare value_comp() const {
                return (value_compare(_comp));
            }

			iterator begin( void ) {
				return (rb_tree.begin());
			}

            const_iterator begin( void ) const {
                return (rb_tree.begin());
            }

			iterator end( void ) {
				return (rb_tree.end());
			}

            const_iterator end( void ) const {
                return (rb_tree.end());
            }

            reverse_iterator rbegin( void ) {
                return (rb_tree.rbegin());
            }

            const_reverse_iterator rbegin( void ) const {
                return (rb_tree.rbegin());
            }

            reverse_iterator rend( void ) {
                return (rb_tree.rend());
            }

            const_reverse_iterator rend( void ) const {
                return (rb_tree.rend());
            }

            bool empty( void ) const {
                return (rb_tree.empty());
            }

			size_type size( void ) {
				return (rb_tree.size());
			}

			iterator find(const key_type &k) {
				return (rb_tree.find(k));
			}

			size_type count(const key_type &k) const {
				return (rb_tree.count(k));
			}

            iterator lower_bound(const key_type &k) {
                return (rb_tree.lower_bound(k));
            }

            const_iterator lower_bound(const key_type &k) const {
                return (rb_tree.lower_bound(k));
            }

            iterator upper_bound(const key_type &k) {
                return (rb_tree.upper_bound(k));
            }

            const_iterator upper_bound(const key_type &k) const {
                return (rb_tree.upper_bound(k));
            }

            ft::pair<const_iterator,const_iterator> equal_range(const key_type &k) const {
                return (rb_tree.equal_range(k));
            }

            ft::pair<iterator,iterator> equal_range(const key_type &k) {
                return (rb_tree.equal_range(k));
            }

			mapped_type& operator[] (const key_type& k) {
				return ((*((insert(ft::make_pair(k,mapped_type()))).first)).second);
			}

            void print( void ) {
				rb_tree.printBT();
			}

            void clear( void ) {
                rb_tree.clear();
            }

		private:
            Rb_type rb_tree;
			key_compare _comp;
			allocator_type _alloc;
	};
}

#endif
