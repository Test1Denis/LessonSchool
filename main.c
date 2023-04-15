#include <iostream>
#include <fstream>
#include <cassert>

void test_function(void (*test)(), const std::string& nameFunc) {
	std::cout << "test func" << std::endl;//"\x1b[41mstart \x1b[32mtest\x1b[40m" << std::endl;
	std::cout << "\t" << nameFunc << std::endl;
	test();
}

#define RUN_TEST(f)	(test_function(f, #f))

template<class T>
void assert_equal(const T expr, const T expr_true, 
					const std::string& str_expr, const std::string& str_expr_true)
{
	if (expr == expr_true) {
		std::cout << "\tTest PASSED" << std::endl;
		return;
	}

	std::cout << "\tTest BAD : " << str_expr << " != " << str_expr_true << std::endl;
}

#define ASSERT_EQUAL(expr, expr_true) assert_equal(expr, expr_true, #expr, #expr_true)

void assert1(bool expr, const std::string& str_expr) {
	if (expr == true) {
		std::cout << "\tTest OK" << std::endl;
		return ;
	}
	
	std::cout << "\tTest BAD : " << __func__ << " " << __LINE__ << " " << __FILE__ << " "  << str_expr << std::endl;
}

#define ASSERT(expr)	assert1(expr, #expr)	
#define ASSERT1(expr)	std::cout << __FILE__ << ":" << __LINE__;\
						 assert1(expr, #expr)	

int mult(int a, int b) {
	return a * b;
}

void test1() {
	ASSERT_EQUAL(mult(2,2), 4);
	ASSERT_EQUAL(mult(11,11), 121);
	ASSERT_EQUAL(mult(11,11), 121);
	ASSERT_EQUAL(mult(12,12), 144);
	ASSERT1(mult(2,2) == 3);
	ASSERT1(mult(2,2) == 5);
	std::cout << "OK" << std::endl;
}

int main() {
	RUN_TEST(test1);

	return 0;
}
