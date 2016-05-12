/*************************************************************
 * Samantha Rack, Puzzle.h
 * CSE 20212, Lab 5
 * This file contains the interface and implementation for the 
 * templated class Puzzle, which is used to implement a game of 
 * Sudoku or Wordoku.
 * **********************************************************/


#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <stdlib.h>

using namespace std ;


//BEGIN INTERFACE
#ifndef PUZZLE_H
#define PUZZLE_H

template <typename T>
class Puzzle {
	public:
		Puzzle(string) ;	//nondefault constructor taking filename as argument
		void print() ;		//prints puzzle object in current state

	private:
		vector<vector <T> > grid ;	//2D vector to store puzzle information
		int dimension ;		//stores dimensions of the board ie. for 4x4 board, dimension=4
} ;

#endif


//BEGIN IMPLEMENTATION
template <typename T>
Puzzle<T>::Puzzle(string filename) {
	ifstream dataFile ;
	dataFile.open(filename.c_str()) ;	//filename string converted to a C string 
	int numItems = 0 ;		//to determine if the dimension of the board, ie. 4x4 or 9x9
	int numDigits = 0 ;	//used to keep track of number of digits found, if equals numItems, then the puzzle is Sudoku
	char c ;	//gets information from file one element at a time	
	while(!dataFile.eof()) {
		c = dataFile.get() ;	//gets a single character
		if(c == ' ' || c == '\n' || c == EOF) {
			continue ;	//does not increment numItems with spaces, new lines, or EOF characters
		}
		if (isdigit(c)) numDigits++ ;	
		numItems++ ;
	}
	dimension = sqrt(numItems) ;
	dataFile.close() ;
	
	int i, j ;
	int value ;
	vector < T > temp ;	//temporary vector to hold each of the rows
	dataFile.open(filename.c_str()) ;
	for ( i = 0 ; i < dimension ; i++ ) {
		for ( j = 0 ; j < dimension ; j++) {
			c = dataFile.get() ;		//file information gotten character by character
			if (c == ' ' || c == '\n' || c == EOF) {
				j-- ;	//subtract one so spaces aren't counted as one of the numbers
				continue ;
			}
			if (numItems == numDigits){
				value = atoi(&c) ;
				temp.push_back(value) ;
			} else temp.push_back(c) ;
		}
		grid.push_back(temp) ;		//puts temporary vector into the 2D vector grid
		temp.clear() ;		//clears the temporary vector for the next line of input
	}
	dataFile.close() ;
}

template <typename T>
void Puzzle<T>::print() {
	int i , j ;
	int breaks = sqrt(dimension) ;	//where there will be lines to separate the mini grids
	cout << endl << dimension << "x" << dimension << " PUZZLE" << endl ;
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
