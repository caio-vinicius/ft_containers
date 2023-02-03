/* Copyright (c) 2023 Caio Souza. All rights reserved. */
/* 42 */

#ifndef STL_FUNCTIONAL_HPP
# define STL_FUNCTIONAL_HPP

namespace ft {

		template <class Arg1, class Arg2, class Result>
				struct binary_function {
						typedef Arg1 first_argument_type;
						typedef Arg2 second_argument_type;
						typedef Result result_type;
				};

}

#endif
