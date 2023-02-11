all : main.o mergeSort.o arrayFunc.o
	g++ main.o mergeSort.o arrayFunc.o

main.o : main.c
	g++ -c main.c -std=c++17

mergesort.o	:	mergeSort.cpp
	g++ -c mergeSort.cpp 

arrayFunc.o	:	arrayFunc.c
	g++ -c arrayFunc.c


clean :
	rm -rf *.o a.out
