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
	string ownFile = "" ;
	string fileChoices[5] = {"", "sudokuFiles/easy.txt", "sudokuFiles/medium.txt", "sudokuFiles/cc1.txt", ownFile} ;
	cout << endl << "Choose a Sudoku puzzle to be solved: " << endl ;
	cout << " 1) " << fileChoices[1] << "\n 2) " << fileChoices[2] << "\n 3) " << fileChoices[3] << "\n 4) unlisted file" << endl ;
	int choice ;
	cin >> choice ;
	if (choice == 4) {
		cout << "Enter the path to the file: " ;
		cin >> ownFile ;
		fileChoices[4] = ownFile ;
	}

	Puzzle fun2(fileChoices[choice]) ;
	cout << endl << "Original Sudoku:" << endl << fun2 << endl ;
	sleep(2) ;

	cout << "Solved:" << endl ;
	fun2.solve() ;
}
