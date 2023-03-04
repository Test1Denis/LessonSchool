#include <iostream>
#include <fstream>
#include "linkedList.h"

void test_LL() {
	int num_test = 0;
	{
		std::cout << "test - " << ++num_test << std::endl;
		LinkedList *test = new LinkedList();

		for (int i = 0; i < 10; i++) {
			test->push_back(Data(i + 1));
		}

		for (int i = 0; i < 20; i++) {
			Data temp = test->pop_back();
			std::cout << temp.val << " ";
		}
		std::cout << std::endl;
		std::cout << "test - " << num_test << " is OK" << std::endl; 
		delete test;
	}
	{
		std::cout << "test - " << ++num_test << std::endl;
		LinkedList *test = new LinkedList();

		for (int i = 0; i < 29; i++) {
			test->push_back(Data(i + 1));
		}

		for (int i = 0; i < 20; i++) {
			Data temp = test->pop_back();
			std::cout << temp.val << " ";
		}

		for (int i = 0; i < 5; i++) {
			test->push_back(Data(i*20 + 1));
		}

		for (int i = 0; i < 20; i++) {
			Data temp = test->pop_back();
			std::cout << temp.val << " ";
		}
		std::cout << std::endl;
		std::cout << "test - " << num_test << " is OK" << std::endl; 
		delete test;
	}
}


int main() {

	test_LL();


	return 0;
}
