#ifndef STL_MAP_ITERATOR_HPP
# define STL_MAP_ITERATOR_HPP

#include "stl_iterator_base_types.hpp"

namespace ft {
    template <typename Node>
    class map_iterator : public std::iterator<ft::bidirectional_iterator_tag, Node> {
        public:
            typedef Node node_type;

            map_iterator() : _current_node(NULL) {}
            map_iterator(node_type *node) : _current_node(node) {}

            Node &operator*() const { return *_current_node; }
            Node *operator->() const { return _current_node; }

            map_iterator &operator++() {
                _current_node = node_type::next(_current_node, _Nil);
                return (*this);
            }
            map_iterator operator++(int) {
                map_iterator tmp(*this);
                operator++();
                return tmp;
            }
            map_iterator &operator--() {}
            map_iterator operator--(int) {}
            bool operator==(const map_iterator &rhs) const {
                return _current_node == rhs._current_node;
            }
            bool operator!=(const map_iterator &rhs) const {
                return _current_node != rhs._current_node;
            }

        private:
            node_type *_current_node;
            node_type *_Nil;
    };
}

#endif
