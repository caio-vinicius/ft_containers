#ifndef UNITEST_HPP
#define UNITEST_HPP
#include <iostream>
#include <vector>
#include <cstring>

#define RESET_COLOR "\033[0m"

/*
** testSuite settings
*/

#define TEST_SUITE_NAME_COLOR "\033[1;36m"
#define TEST_SUITE_TEST_COLOR "\033[0m"
#define TEST_SUITE_TEST " Test"

class UnitTest;

class Node {
public:
	void (*data)(UnitTest&);
	Node* next;
	std::string name;
};

class Asserts {
	public:
		Asserts( void ) {};
		virtual ~Asserts( void ) {};
		virtual void assertFalse(bool condition) const = 0;
		virtual void assertTrue(bool condition) const = 0;

};

class UnitTest {
	private:
		std::string _assert_fail;
		std::string _assert_pass;
		std::string _assert_color_fail;
		std::string _assert_color_pass;
		size_t _total;
		size_t _passed;
		Node *_suits;
		bool _mode;
		int _exit_code;
	public:
		UnitTest( std::string assert_fail = "Fail",
			std::string assert_pass = "Pass"):
			_assert_fail(assert_fail),
			_assert_pass(assert_pass),
			_total(0), _passed(0),
			_suits(NULL), _exit_code(0) {
			this->_assert_color_pass = "\033[32m";
			this->_assert_color_fail =  "\033[31m";
			this->_mode = true;
		};

		~UnitTest( void ) {
		};

		void assertTrue(bool condition, std::string message = "") {
			std::ostream* output_stream;

			message = !message.compare("") ? message : " " + message;
			output_stream = condition ?  &std::cerr : &std::cout;
			_passed = condition ? _passed + 1 : _passed;
			_total++;
			std::string result = condition ? _assert_pass : _assert_fail;
			std::string color = condition ? _assert_color_pass : _assert_color_fail;

			if (!_mode) {
				*output_stream << color << result << RESET_COLOR << message << std::endl;
			} else {
				*output_stream << color << "# " << RESET_COLOR;
			}
		};

		template <typename T, typename U>
		void assertArrayEquals(T &x, U &y, size_t n) {
			for (size_t i = 0; i < n; i++) {
				if (x[i] != y[i]) {
					assertTrue(false);
				}
			}
			assertTrue(true);
		};

		void assertFalse(bool condition) {
			assertTrue(!condition);
		};

		void assertFalse(bool condition, std::string message) {
			assertTrue(!condition, message);
		};

		template <typename T>
		void assertEqual(const T actual, const T expected) {
			assertTrue(actual == expected);
		};

		template <typename T>
		void assertEqual(const T* actual, const T* expected) {
			assertTrue(actual == expected);
		};

		template <typename T>
		void assertEqual(const T actual, const T expected, std::string message) {
			assertTrue(actual == expected, message);
		};

		template <typename T>
		void assertEqual(const T* actual, const T* expected, std::string message) {
			assertTrue(actual == expected, message);
		};

		void setMode( bool mode ) {
			_mode = mode;
		}

		int exitStatus( void ) {
			if (_exit_code) {
				return (1);
			} else {
				return (0);
			}
		}

		void addSuit(void (*data)(UnitTest&), std::string name) {
			if (_suits == NULL) {
				_suits = new Node();
				_suits->data = data;
				_suits->name = name;
				_suits->next = NULL;
			} else {
				Node* current = _suits;
				while (current->next != NULL) {
					current = current->next;
				}
				current->next = new Node();
				current->next->data = data;
				current->next->name = name;
				current->next->next = NULL;
			}
		}

		void runTest(void (*test)(UnitTest&), std::string name) {
			std::cout << "\n" << name << "\n" << std::endl;
			test(*this);
		}

		void run(void) {
			Node* current = _suits;
			while (current != NULL) {
				run(current);
				current = current->next;
			}
			if (_passed < _total) {
				_exit_code = 1;
			}
		}

		void run(Node* suit) {
			std::cout << suit->name << "\n";
			suit->data(*this);
			if (_mode) {
				std::cout << std::endl;
			}
			std::cout << "\n";
		}

		void clear( void ) {
			Node *current = _suits;
			Node *next = NULL;
			while (current != NULL) {
				next = current->next;
				delete current;
				current = next;
			}
			_suits = NULL;
			_total = 0;
			_passed = 0;
		}

		void status( void ) {
			std::cout << _passed << "/" << _total << " passed" << " - ";
		}

};

#endif
