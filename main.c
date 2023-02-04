#include <iostream>

unsigned long long int fact(int n) {
	if (n <= 1) {
		return 1;
	}

	return n * fact(n-1);
}

int main() {
	int n = 10;
	fact(100000);
	while(1) {
		std::cout <<	"n = " << n << " " << fact(n) << std::endl;
		n += 100;

	}
	return 0;
}
