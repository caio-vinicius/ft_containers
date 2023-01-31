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


			typedef ft::Rb_tree<key_type, value_type, key_compare, allocator_type> Rb_type;
			typedef typename Rb_type::iterator iterator;
			typedef typename Rb_type::size_type size_type;


			explicit map (const key_compare& comp = key_compare(),
			  const allocator_type& alloc = allocator_type()): _comp(comp), _alloc(alloc) { };
			map(const map &x): rb_tree(x.rb_tree), _comp(x._comp), _alloc(x._alloc) { };

			template <class InputIterator>
			map(InputIterator first, InputIterator last, const key_compare &comp = key_compare(), const allocator_type& alloc = allocator_type()) : _comp(comp), _alloc(alloc) {
                for (; first != last; first++) {
					insert(*first);
				}
            }

			pair<iterator, bool> insert (const value_type& val) {
				iterator it = find(val.first);
				if ( it != end() )
					return(ft::make_pair<iterator, bool>(it, false));
				return(ft::make_pair<iterator, bool>(rb_tree.insert(val), true));
			}

			iterator begin( void ) {
				return (rb_tree.begin());
			}

			iterator end( void ) {
				return (rb_tree.end());
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

			mapped_type& operator[] (const key_type& k) {
				return ((*((insert(ft::make_pair(k,mapped_type()))).first)).second);
			}
			void print( void ) {
				rb_tree.printBT();
			}

		private:
			Rb_type rb_tree;
			key_compare _comp;
			allocator_type _alloc;
	};
}

#endif
