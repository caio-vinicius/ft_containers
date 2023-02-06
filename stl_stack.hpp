#ifndef STL_STACK_HPP
# define STL_STACK_HPP

#include "stl_vector.hpp"

namespace ft {

		template <typename T, typename Container = ft::vector<T> >
		class stack {
				public:
						typedef T value_type;
						typedef Container container_type;
						typedef size_t size_type;

						explicit stack(const container_type& ctnr = container_type()) : c(ctnr) {}

						bool empty() const {
								return (c.empty());
						}

						size_type size() const {
								return (c.size());
						}

						value_type& top() {
								return (c.back());
						}

						const value_type& top() const {
								return (c.back());
						}

						void push(const value_type& val) {
								c.push_back(val);
						}

						void pop() {
								c.pop_back();
						}

						friend bool operator==(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
								return (lhs.c == rhs.c);
						}

						friend bool operator!=(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
								return (lhs.c != rhs.c);
						}

						friend bool operator<(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
								return (lhs.c < rhs.c);
						}

						friend bool operator<=(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
								return (lhs.c <= rhs.c);
						}

						friend bool operator>(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
								return (lhs.c > rhs.c);
						}

						friend bool operator>=(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
								return (lhs.c >= rhs.c);
						}

				protected:
						container_type c;
		}; // class stack

		template <typename T, typename Container>
		bool operator==(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
				return (lhs.c == rhs.c);
		}

		template <typename T, typename Container>
		bool operator!=(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
				return (lhs.c != rhs.c);
		}

		template <typename T, typename Container>
		bool operator<(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
				return (lhs.c < rhs.c);
		}

		template <typename T, typename Container>
		bool operator<=(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
				return (lhs.c <= rhs.c);
		}

		template <typename T, typename Container>
		bool operator>(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
				return (lhs.c > rhs.c);
		}

		template <typename T, typename Container>
		bool operator>=(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
				return (lhs.c >= rhs.c);
		}

} // namespace ft

#endif // STL_STACK_HPP
