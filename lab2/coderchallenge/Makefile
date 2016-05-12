all: main

main:  findprimes.o
	g++ findprimes.o -o main

findprimes.o:  findprimes.cpp
	g++ -c findprimes.cpp

clean:
	rm -f *.o main
