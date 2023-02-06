#include "tests.hpp"

static void testConstructor(UnitTest& unit) {
		ft::stack <int> s1;

		unit.assertTrue(s1.empty(), "empty stack");
		unit.assertTrue(s1.size() == 0, "empty stack size");
}

static void testEmpty(UnitTest& unit) {
		ft::stack<int> s;

		unit.assertTrue(s.empty(), "empty stack is empty");
}

static void testSize(UnitTest& unit) {
		ft::stack<int> s;

		unit.assertTrue(s.size() == 0, "empty stack has size 0");

		s.push(1);
		unit.assertTrue(s.size() == 1, "stack with 1 element has size 1");

		s.push(2);
		unit.assertTrue(s.size() == 2, "stack with 2 elements has size 2");
}

static void testTop(UnitTest& unit) {
		ft::stack<int> s;

		s.push(1);
		unit.assertTrue(s.top() == 1, "top of stack with 1 element is 1");

		s.push(2);
		unit.assertTrue(s.top() == 2, "top of stack with 2 elements is 2");
}

static void testPush(UnitTest& unit) {
		ft::stack<int> s;

		s.push(1);
		unit.assertTrue(s.top() == 1, "pushed 1 to stack");

		s.push(2);
		unit.assertTrue(s.top() == 2, "pushed 2 to stack");
}

static void testPop(UnitTest& unit) {
		ft::stack<int> s;

		s.push(1);
		s.push(2);
		s.pop();
		unit.assertTrue(s.top() == 1, "popped 2 from stack");
}

static void testRelationalOperators(UnitTest& unit) {
		ft::stack<int> s1;
		ft::stack<int> s2;

		s1.push(1);
		s1.push(2);
		s1.push(3);

		s2.push(1);
		s2.push(2);
		s2.push(3);

		unit.assertTrue(s1 == s2, "stacks are equal");

		s2.push(4);
		unit.assertTrue(s1 != s2, "stacks are not equal");

		s1.pop();
		unit.assertTrue(s1 < s2, "stack 1 is less than stack 2");

		s1.push(3);
		s1.push(4);
		s1.push(5);
		unit.assertTrue(s1 > s2, "stack 1 is greater than stack 2");

		s1.pop();
		unit.assertTrue(s1 <= s2, "stack 1 is less than or equal to stack 2");

		s2.pop();
		unit.assertTrue(s1 >= s2, "stack 1 is greater than or equal to stack 2");
}

void stack_member_functions(UnitTest& unit) {
		unit.runTest(testConstructor, "testConstructor");
		unit.runTest(testEmpty, "testEmpty");
		unit.runTest(testSize, "testSize");
		unit.runTest(testTop, "testTop");
		unit.runTest(testPush, "testPush");
		unit.runTest(testPop, "testPop");
		unit.runTest(testRelationalOperators, "testRelationalOperators");
}
