#include <iostream>
#include <fstream>

//#define TEST
//#undef TEST

#define A(n) (std::cout << #n << " - " << n  << std::endl)
#define SetBit(numBit)	(1 << numBit)

#define Mult(a, b) ((a) * (b))

struct Data {
	int k;
	int k1;
	Data() : k(100), k1(500) {}
};

std::ostream& operator<<(std::ostream& os, const Data& t) {
	os << "{" << t.k << "," << t.k1 << "}";
	return os;
}

int main() {
	std::cout << std::hex << SetBit(31) << " " << SetBit(12) << std::endl;
	std::cout << std::dec << Mult(10,10) << " " << Mult(10 + 10, 2) << std::endl;

	A(100);
	int k = 101;
	A(k);

//	std::cout << Data() << std::endl;

	Data temp;
	A(temp);

	return 0;
}
