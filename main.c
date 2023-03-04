#include <iostream>
#include <fstream>

int main() {
	int* ar = nullptr;
	delete [] ar;

	return 0;

	FILE* f;
	f = fopen("test.txt", "w");

	int tempNum = 10;
	fprintf(f, "%dfd%xf12\t%.6X \t %.5d  fksdjfal 10 43\n", 10, tempNum, tempNum, 20);
	fclose(f);

	f = fopen("test.txt", "r");
	if (f == nullptr) {
		std::cerr << "file is not opened!!!" << std::endl;
	}

	char buf[256];
	while(fread(buf, 1, 1, f)) {
		std::cout << buf[0];
	}
	std::cout << std::endl;

	fclose(f);

	f = fopen("test.txt", "r");

	int temp_dec, temp_hex;
	int count = fscanf(f, "%dfd%x\t", &temp_dec, &temp_hex);
	std::cout << temp_dec << " " << std::hex << temp_hex << std::endl;

	fclose(f);



	return 0;
}
