/*************************************************************
 * Samantha Rack, Puzzle.h
 * CSE 20212, Lab 5
 * This file contains the interface and implementation for the 
 * templated class Puzzle, which is used to implement a game of 
 * Sudoku or Wordoku.
 * **********************************************************/

//////INCLUDE FILES//////
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <stdlib.h>

using namespace std ;


//////BEGIN INTERFACE//////
#ifndef PUZZLE_H
#define PUZZLE_H

template <typename T>
class Puzzle {
	public:
		Puzzle(string) ;	//nondefault constructor taking filename as argument
		void print() ;		//prints puzzle object in current state
		void play() ;

	private:
		vector<vector <T> > grid ;	//2D vector to store puzzle information
		int dimension ;		//stores dimensions of the board ie. for 4x4 board, dimension=4
		int isValidEntry(int, int, T) ;	//returns 1 if the cell is not occupied and is within the dimensions of the grid
		int checkHorizontal(int, int, T) ;
		int checkVertical(int, int, T) ;
		int checkMiniGrid(int, int, T) ;
		int gameOver() ;	//determines if all of the cells are filled, indicating the end of the game
} ;

#endif


//////BEGIN IMPLEMENTATION//////
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
	cout << "   " ;
	for (i = 0 ; i < dimension ; i++) {
		cout << i << " " ;
	}
	cout << endl ;
	for ( i = 0 ; i < dimension ; i++) {
		if (i % breaks == 0) cout << "  " << string(dimension*2 + 1, '-') << endl ;
		cout << i << " " ;		
		for ( j = 0 ; j < dimension ; j++) {
			if (j % breaks == 0) cout << "|" ;
			else cout << " " ;
			cout << grid[i][j] ;
		}
		cout << "|" << endl ;
	}
	cout << "  " << string(dimension*2 + 1, '-') << endl ;

}

template <typename T>
void Puzzle<T>::play() {
	int row, column ;
	int continueGame = 1 ;
	T value ;
	print() ;	//print initial board
	cout << "Type -1 to quit at any time." << endl ;
	while(!gameOver() && continueGame) {
		do {
			cout << "Enter a row, column, and the desired value (separated by ENTER) :  " ;
			cin >> row ;
			if (row == -1) {
				continueGame = 0 ;
				break ;
			}
			cin >> column ;
			cin >> value ;
		} while (!isValidEntry(row, column, value)) ;
		if (continueGame) {
			grid[row][column] = value ;	//set chosen element to value entered by user
			print() ;	//print updated board
		}
	}
}




template <typename T>
int Puzzle<T>::isValidEntry(int row, int column, T entry) {
	if (row < 0 || column < 0 || row >= dimension || column >= dimension){	//outside range of grid
		cout << "**Error.  Outside range of grid.**" << endl ;
		 return 0 ;	
	}
	if (grid[row][column] != '0' && grid[row][column] != 0) {	//cell already occupied
		cout << "**Error.  Cell already contains a value.**" << endl ;	
		return 0 ;
	}
	if (!checkHorizontal(row, column, entry)) {	//the entered value is already in the row
		cout << "**The value " << entry << " is already in row " << row << ".**" << endl ;
		return 0 ;
	}
	if (!checkVertical(row, column, entry)) {
		cout << "**The value " << entry << " is already in column " << column << ".**" << endl ;
		return 0 ;
	}
	if (!checkMiniGrid(row, column, entry)) {
		cout << "**The value " << entry << " is already in the mini grid.**" << endl ;
		return 0 ;
	}
	return 1 ;
}

template <typename T>
int Puzzle<T>::checkHorizontal(int row, int column, T entry) {
	int i ;
	for ( i = 0 ; i < dimension ; i++) {
		if(i == column) continue ;
		if(entry == grid[row][i]) return 0 ;	//the value of entry already exists in the row
	}
	return 1 ;	//entry not found in the row
}

template <typename T>
int Puzzle<T>::checkVertical(int row, int column, T entry) {
	int i ;
	for ( i = 0 ; i < dimension ; i++) {
		if(i == row) continue ;
		if(entry == grid[i][column]) return 0 ;	//the value of entry already exists in the column
	}
	return 1 ;	//entry not found in the column
}

template <typename T>
int Puzzle<T>::checkMiniGrid(int row, int column, T entry) {
	int i , j ;
	int minCol, maxCol, minRow, maxRow ;
	int miniGridSize = sqrt(dimension) ;
	if (row < miniGridSize) {
		minRow = 0 ;
		maxRow = miniGridSize ;
	}else if(row < 2*miniGridSize) {
		minRow = miniGridSize ;
		maxRow = 2*miniGridSize ;
	}else {	//this condition would only be true for 3x3 grid
		minRow = 2*miniGridSize ;
		maxRow = 3*miniGridSize ;	//dimension of 3x3 grid
	}	//would have to add more cases to account for a 4x4 grid
	if (column < miniGridSize) {
		minCol = 0 ;
		maxCol = miniGridSize ;
	}else if (column < 2*miniGridSize) {
		minCol = miniGridSize ;
		maxCol = 2*miniGridSize ;
	}else {
		minCol = 2*miniGridSize ;
		maxCol = 3*miniGridSize ;
	}

	for ( i = minRow ; i < maxRow ; i++ ) {
		for ( j = minCol ; j < maxCol ; j++ ) {
			if(i == row && j == column) continue ;
			if(entry == grid[i][j]) return 0 ;
		}
	}
	return 1 ;
}

template <typename T>
int Puzzle<T>::gameOver() {
	int i, j ;
	for ( i = 0 ; i < dimension ; i++ ) {
		for ( j = 0 ; j < dimension ; j++ ) {
			if(grid[i][j] == '0' || grid[i][j] == 0) return 0 ;
		}
	}
	cout << "Puzzle complete.  Game over." << endl ;
	return 1 ;
}




