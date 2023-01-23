/* Copyright (c) 2023 Caio Souza. All rights reserved. */
/* 42 */

#ifndef STL_UTILITY_HPP
# define STL_UTILITY_HPP

namespace ft {

    template <typename T1, typename T2>
    struct pair {
        typedef T1 first_type;
        typedef T2 second_type;

        T1 first;
        T2 second;

        pair(): first(T1()), second(T2()) {};
        pair(const first_type &a, const second_type &b): first(a), second(b) {};
        template <typename U, typename V>
        pair(const pair<U, V> &pr) : first(pr.first), second(pr.second) {};

        pair &operator=(const pair &pr) {
            first = pr.first;
            second = pr.second;
            return (*this);
        }
    };

    template <typename T1, typename T2>
    bool operator==(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs) {
        return (lhs.first == rhs.first && lhs.second == rhs.second);
    }
    template <typename T1, typename T2>
    bool operator!=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs) {
        return !(lhs == rhs);
    }
    template <typename T1, typename T2>
    bool operator<(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs) {
        return (lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second));
    }
    template <typename T1, typename T2>
    bool operator<=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs) {
        return !(rhs < lhs);
    }
    template <typename T1, typename T2>
    bool operator>(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs) {
        return (rhs < lhs);
    }
    template <typename T1, typename T2>
    bool operator>=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs) {
        return !(lhs < rhs);
    }

    template <typename T1, typename T2>
    pair<T1, T2> make_pair(T1 x, T2 y) {
        return (pair<T1, T2>(x, y));
    }

}

#endif
