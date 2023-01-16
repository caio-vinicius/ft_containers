/* Copyright (c) 2023 Caio Souza. All rights reserved. */
/* 42 */

#ifndef TEST_HPP
# define TEST_HPP

#include <functional>
#include <iostream>
#include <vector>
#include <cstdarg>

class test {
    private:
        std::vector<bool (*)()> tests;
        int n_tests;
        int n_tests_passed;
    public:
        test(): n_tests(0), n_tests_passed(0) {}
        test(std::vector<bool (*)()> tests_vector): tests(tests_vector), n_tests(tests_vector.size()), n_tests_passed(0) {};

        void run(void) {
            for (int i = 0; i < n_tests; i++) {
                bool res = tests[i]();
                if (res) {
                    n_tests_passed++;
                } else {
                    std::cout << "Test " << i + 1 << " FAILED\n";
                }
            }
            std::cout << "Run completed, # of failed tests/total tests: " << n_tests - n_tests_passed << "/" << n_tests << std::endl;
        }

        void make(int num_args, ...) {
            va_list args;
            std::vector<bool (*)()> funcs;
            va_start(args, num_args);

            for (int i = 0; i < num_args; i++) {
                funcs.push_back(va_arg(args, bool (*)()));
            }
            va_end(args);
            n_tests = funcs.size();
            tests = funcs;
        }
};

#endif
