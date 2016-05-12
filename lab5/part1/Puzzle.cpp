/********************************************************
 * Samantha Rack, Puzzle.cpp
 * CSE 20212, Lab 5
 * This file contains the implementation of member functions
 * of class Puzzle.
 * ******************************************************/

#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include <vector>
#include <stdlib.h>
#include "Puzzle.h"

#include <stdio.h>


using namespace std ;

Puzzle::Puzzle(string filename) {
	ifstream dataFile ;
	dataFile.open(filename.c_str()) ;	//filename string converted to a C string 
	int numItems = 0 ;		//to determine if the dimension of the board, ie. 4x4 or 9x9
	char c ;	
	while(!dataFile.eof()) {
		c = dataFile.get() ;	//gets a single character
		if(c == ' ') {
			continue ;	//does not increment numItems with spaces
		}
		numItems++ ;

	}
	dimension = sqrt(numItems) ;
	dataFile.close() ;
	
	int i, j ;
	int value ;
	vector < int > temp ;	//temporary vector to hold each of the rows
	dataFile.open(filename.c_str()) ;
	for ( i = 0 ; i < dimension ; i++ ) {
		for ( j = 0 ; j < dimension ; j++) {
			c = dataFile.get() ;
			if (c == ' ') {
				j-- ;	//subtract one so spaces aren't counted as one of the numbers
				continue ;
			}
			value = atoi(&c) ;
			temp.push_back(value) ;
		}
		grid.push_back(temp) ;		//puts temporary vector into the 2D vector grid
		temp.clear() ;		//clears the temporary vector for the next line of input
	}
	dataFile.close() ;
}

void Puzzle::print() {
	int i , j ;
	int breaks = sqrt(dimension) ;	//where there will be lines to separate the mini grids
	cout << endl << dimension << "x" << dimension << " SUDOKU" << endl ;
	for ( i = 0 ; i < dimension ; i++) {
		if (i % breaks == 0) cout << string(dimension*2 + 1, '-') << endl ;
		for ( j = 0 ; j < dimension ; j++) {
			if (j % breaks == 0) cout << "|" ;

			else cout << " " ;
			cout << grid[i][j] ;
		}
		cout << "|" << endl ;
	}
	cout << string(dimension*2 + 1, '-') << endl ;


}
