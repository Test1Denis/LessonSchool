all : main.o
	g++ main.o

main.o : main.c
	g++ -c main.c -std=c++17

main.s : main.c
	g++ -s main.c

clean :
	rm -rf *.o a.out
