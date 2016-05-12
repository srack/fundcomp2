all: main

main:  main.o C4Board2.o C4Col.o
	g++ main.o C4Board2.o C4Col.o -o main

main.o:  main.cpp
	g++ -c main.cpp

C4Col.o:  C4Col.cpp
	g++ -c C4Col.cpp

C4Board2.o:  C4Board2.cpp
	g++ -c C4Board2.cpp


clean:
	rm -f *.o main
