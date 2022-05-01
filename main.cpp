/* Copyright (c) 2022 Caio Souza. All rights reserved. */
/* 42 */

#include <iostream>

#include <vector>

namespace ft {
    int i = 42;
}

void ft_containers(void) {
    std::vector<int> v;
    v.push_back(0);
    v.push_back(ft::i);

    std::cout << *v.begin() << std::endl;
    std::cout << *(v.begin() + 1);
}

int main(void) {
    ft_containers();
    return (0);
}
