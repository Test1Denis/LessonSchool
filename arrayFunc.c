#include "arrayFunc.h"


void showEl(const int* ar, int size, char delimited) {
	for (int i = 0; i < size; i++) {
		std::cout << ar[i] << delimited;
	}
	std::cout << std::endl;
}
