#include "UnitTest.hpp"

UnitTest::UnitTest( std::string assert_fail,
	std::string assert_pass):
	_assert_fail(assert_fail),
	_assert_pass(assert_pass),
	_total(0), _passed(0),
	_suits(NULL), _exit_code(0) {
		this->_assert_color_pass = "\033[32m";
		this->_assert_color_fail =  "\033[31m";
		this->_mode = true;
}

UnitTest::~UnitTest( void ) {}

void UnitTest::assertTrue(bool condition, std::string message) {
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
}

void UnitTest::assertFalse(bool condition) {
	assertTrue(!condition);
}

void UnitTest::assertFalse(bool condition, std::string message) {
	assertTrue(!condition, message);
}

void UnitTest::setMode( bool mode ) {
	_mode = mode;
}

int UnitTest::exitStatus( void ) {
	if (_exit_code) {
		return (1);
	} else {
		return (0);
	}
}

void UnitTest::addSuit(void (*data)(UnitTest&), std::string name) {
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

void UnitTest::runTest(void (*test)(UnitTest&), std::string name) {
	std::cout << "\n" << name << "\n" << std::endl;
	test(*this);
}

void UnitTest::run(void) {
	Node* current = _suits;
	while (current != NULL) {
		run(current);
		current = current->next;
	}
	if (_passed < _total) {
		_exit_code = 1;
	}
}

void UnitTest::run(Node* suit) {
	std::cout << suit->name << "\n";
	suit->data(*this);
	if (_mode) {
		std::cout << std::endl;
	}
	std::cout << "\n";
}

void UnitTest::clear( void ) {
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

void UnitTest::status( void ) {
	std::cout << _passed << "/" << _total << std::endl;
}
