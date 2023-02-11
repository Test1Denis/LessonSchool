#include <iostream>
#include "mergeSort.hpp"
#include "arrayFunc.h"

int binSearch(int* ar, int size, int el) {
	if (ar[size >> 1] == el) {
		return (size >> 1);
	}
	if (size == 1) {
		return -1;
	}

	if (el > ar[size >> 1]) {
		return binSearch(&ar[size >> 1], size - (size >> 1), el) + (size >> 1); 
	}

	if (el < ar[size >> 1]) {
		return binSearch(ar, size >> 1, el);
	}


	return -1;
}

void test_binSearch()  {
	std::cout << "\t---" << __func__ << "---" << std::endl;
	{	//test 1
		int ar[] = {1,2,3,4,5,6,7,8,9,10};
		if (binSearch(ar, 10, 1) != 0) {
			std::cerr << "TEST1 failed" << std::endl;
		}
		else {
			std::cerr << "TEST1 OK" << std::endl;
		}
		std::cout << "ind = 0, now = " << binSearch(ar, 10, 1) << std::endl;
		std::cout << "ind = 1, now = " << binSearch(ar, 10, 2) << std::endl;
		std::cout << "ind = 8, now = " << binSearch(ar, 10, 9) << std::endl;
		std::cout << "ind = 9, now = " << binSearch(ar, 10, 10) << std::endl;

	} 
	{	//test2
		int ar[] = {1,2,3,4,5,6,7,8,9,10};
		std::cout << "ind = -1, now = " << binSearch(ar, 10, 0) << std::endl;
		if (binSearch(ar, 10, 16) != -1) {
			std::cout << "test2 2 FAILED" << std::endl;
		}
		else {
			std::cout << "test2 2 PASSED" << std::endl;
		}
	}

	std::cout << "--------------" << std::endl;
}

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

void quickSort(int* ar, int size) {
	int left = 0;
	int right = size - 1;
	int pivot = ar[size >> 1];

	while(left <= right) {
		while(ar[left] < pivot) {
			left++;
		}

		while (ar[right] > pivot) {
			right--;
		}

		if (left <= right) {
			swap(ar[right], ar[left]);
			right--;
			left++;
		}
	}
	if (right > 0) {
		quickSort(&ar[0], right + 1);
	}

	if (left < size) {
		quickSort(&ar[left], size - left);
	}
}

void test_merge() {
	std::cout << "\t---" << __func__ << "---" << std::endl;
	int countTest = 1;
	{
		std::cout << "test " << countTest++ << std::endl;
		const int SIZE_AR = 10;
		int ar[SIZE_AR] = {1, 2, 1, 2, 0, 0, -9, 90, -11};
		showEl(ar, SIZE_AR);
		mergeSort(ar, SIZE_AR);
		showEl(ar, SIZE_AR);
	}

	std::cout << "-------------" << std::endl;
}

void test_quickSort() {

	std::cout << "\t----" << __func__ << "----" << std::endl;
	int ar_test[] = {5,3,2,8,99,23,11,6,0,7};
	for (int i = 0; i < 10; i++) {
		std::cout << ar_test[i] << " "; //std::endl;
	}
	std::cout << std::endl;
	quickSort(ar_test, 10);
	for (int i = 0; i < 10; i++) {
		std::cout << ar_test[i] << " "; //std::endl;
	}

	std::cout << std::endl;
	std::cout << "------------" << std::endl;
}

int main() {
	test_merge();
	test_quickSort();


	test_binSearch();
	return 0;
}
