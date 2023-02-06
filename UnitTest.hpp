#ifndef UNITEST_HPP
#define UNITEST_HPP
#include <iostream>
#include <vector>
#include <cstring>
#include <iterator>
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
			std::string assert_pass = "Pass");
		~UnitTest( void );
		void assertTrue(bool condition, std::string message = "");
		void assertFalse(bool condition);
		void assertFalse(bool condition, std::string message);
		void setMode( bool mode );
		int exitStatus( void );
		void addSuit(void (*data)(UnitTest&), std::string name);
		void runTest(void (*test)(UnitTest&), std::string name);
		void run(void);
		void run(Node* suit);
		void clear( void );
		void status( void );

};

#endif
