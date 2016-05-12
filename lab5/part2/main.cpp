/**********************************************************
	Samantha Rack, main.cpp
	CSE 20212, Lab 5
	This file contains the driver program for the class
	Puzzle. 
**********************************************************/

#include "Puzzle.h"
#include <iostream>

#include <cstring>
#include <cmath>
#include <vector>
#include <stdlib.h>

using namespace std ;

int main(int argc, char **argv) {
	/*if (argc != 2) {
		cout << "  Format: ./main <filename>" << endl ;
		return 1 ;
	}
	Puzzle<int> fun(argv[1]) ;		//takes second argument from the command line as file name 
	*/

	Puzzle<char> fun("wordoku.txt") ;
	Puzzle<int> fun2("sudoku.txt") ;

	fun.print() ;
	fun2.print() ;
}
