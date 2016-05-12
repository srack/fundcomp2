/*******************************************************************
 * Samantha Rack, Puzzle.cpp
 * CSE 20212, Lab 6
 * This file contains the implementation of the Puzzle class, which
 * defines the processes of reading in a puzzle from a file (through 
 * its constructor), printing the current puzzle to the screen, checking
 * if a value is valid for a certain block, and solving the given puzzle.
***********************************************************************/


#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include <vector>
#include <list>
#include "Puzzle.h"

using namespace std ;

Puzzle::Puzzle(string filename) {	//reads in sudoku puzzle file and stores data in 3D vector
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
		numItems++ ;
	}
	dimension = sqrt(numItems) ;
	dataFile.close() ;
	
	int i, j, k ;
	int value ;
	vector < int > tempValues ;	//temporary vector for holding value read in (will be only one or zero values)
	vector <vector <int> > tempRow ;	//temporary vector to hold each of the rows
	dataFile.open(filename.c_str()) ;
	for ( i = 0 ; i < dimension ; i++ ) {
		for ( j = 0 ; j < dimension ; j++) {
			c = dataFile.get() ;		//file information gotten character by character
			if (c == ' ' || c == '\n' || c == EOF) {
				j-- ;	//subtract one so spaces aren't counted as one of the numbers
				continue ;
			}
			value = atoi(&c) ;
			for( k = 0 ; k < dimension ; k++) {
				if (value == 0) {
					tempValues.push_back(1) ;	//push_back 1 for each location
				} else {
					if (k == value-1) {
						tempValues.push_back(1) ;	//puts 1 only in location of vector corresponding to correct value
					}else {
						tempValues.push_back(0) ;
					}
				}
			}
			tempRow.push_back(tempValues) ;	//push back tempValues vector (containing the read in value) into 2nd dimension vector
			tempValues.clear() ;		//clears the temporary vectors for the next line of input
		}
		grid.push_back(tempRow) ;		//puts temporary vector into the first dimension vector
		tempRow.clear() ;
	}
	dataFile.close() ;
}



void Puzzle::print() {		//prints from the 3D vector data member using valueDetermined function
	int i , j , k ;
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
			cout << valueDetermined(i, j) ;
		}
		cout << "|" << endl ;
	}
	cout << "  " << string(dimension*2 + 1, '-') << endl ;
}

ostream& operator<<(ostream& output, Puzzle& sudoku) {
	sudoku.print() ;
	return output ;
}



int Puzzle::valueDetermined(int row, int column) {	//returns 0 if value is not yet determined, the correct value if it has been determined
	int value ;
	int onesCount = 0 ;
	int k ;	
	for ( k = 0 ; k < dimension ; k++ ) {
		if (grid[row][column][k] == 1) {
			onesCount++ ;
			value = k + 1 ;		//add one because of vector indexing offset from values
		}	
	}
	if (onesCount == 1) return value ;
	else return 0 ;		//more than one possibility remaining
}



int Puzzle::gameOver() {
	int i, j ;
	for ( i = 0 ; i < dimension ; i++ ) {
		for ( j = 0 ; j < dimension ; j++ ) {
			if(!valueDetermined(i, j)) return 0 ;
		}
	}
	return 1 ;
}






///////////////////////SOLVE FUNCTION//////////////////////////////////////////

void Puzzle::solve() {
	int i, j, k, m;
	
	while (!gameOver()) {
		int change = 0 ;	//for determining if the puzzle cannot be solved by the program

		for ( i = 0 ; i < dimension ; i++ ) {		//traverse rows
			for ( j = 0 ; j < dimension ; j++ ) {		//traverse columns
				if (valueDetermined(i, j)) continue ;	//don't need to process a location if it has already been solved for
				for ( k = 0 ; k < dimension ; k++ ) {
					if (grid[i][j][k] == 1 && isEliminated(i, j, k+1)) {	//search/elimination algorithm implementation
						grid[i][j][k] = 0 ; 
						change++ ;
					} else if (grid[i][j][k] == 1 && isSingleton(i, j, k+1)) {	//singleton algorithm implementation
						for (m = 0 ; m < dimension ; m++) {
							if ( m!=k ) grid[i][j][m] = 0 ;
						}
						change++ ;
					}		
				}
			}
		}
		if (change == 0) {	//we got stuck - no change after trying both the singleton and search/elimination algorithms
			cout << "uh oh.........here's what we got:" << endl ;
			print() ;
			exit(1) ;
		}
	}

	print() ;
	cout << "The puzzle is solved!!!!" << endl ;

}




//////////////////////SEARCH/ELIMINATION ALGORITHM FUNCTIONS////////////////////////////////////////////////

int Puzzle::isEliminated(int row, int column, int entry) {	//entry already exists in row, column, and/or miniGrid
	if(!checkHorizontal(row, column, entry)) return 1 ;
	if(!checkVertical(row, column, entry)) return 1 ;
	if(!checkMiniGrid(row, column, entry)) return 1 ;
	return 0 ;
}

int Puzzle::checkHorizontal(int row, int column, int entry) {		//returns 0 if entry already exists in row, 1 if not
	int i ;
	for ( i = 0 ; i < dimension ; i++) {
		if(i == column) continue ;	//don't compare to self
		if(valueDetermined(row, i) == entry) return 0 ;	//the value of the entry already exists in the row
	}
	return 1 ;	//entry not found in the row
}

int Puzzle::checkVertical(int row, int column, int entry) {
	int i ;
	for ( i = 0 ; i < dimension ; i++) {
		if(i == row) continue ;
		if(valueDetermined(i, column) == entry) return 0 ;	//the value of entry already exists in the column
	}
	return 1 ;	//entry not found in the column
}

int Puzzle::checkMiniGrid(int row, int column, int entry) {
	int i , j ;
	int minCol, maxCol, minRow, maxRow ;
	int miniGridSize = sqrt(dimension) ;
	//determining the range of the check	
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

	//where the check actually happens
	for ( i = minRow ; i < maxRow ; i++ ) {
		for ( j = minCol ; j < maxCol ; j++ ) {
			if(i == row && j == column) continue ;
			if(valueDetermined(i, j) == entry) return 0 ;
		}
	}
	return 1 ;
}



//////////////////////SINGLETON ALGORITHM FUNCTIONS////////////////////////////////////////////////

int Puzzle::isSingleton(int row, int column, int value) {	//returns 1 if the given location is a singleton in row, column, or grid
	if (checkHorizontalUnknowns(row, column, value)) return 1 ;	//horizontal singleton
	if (checkVerticalUnknowns(row, column, value)) return 1 ;	//vertical singleton
	if (checkMiniGridUnknowns(row, column, value)) return 1 ;	//mini grid singleton
	return 0 ;
}


int Puzzle::checkHorizontalUnknowns(int row, int column, int entry) {
	int i ;
	for ( i = 0 ; i < dimension ; i++) {
		if( i == column) continue ;
		if(!valueDetermined(row, i)) {	//only check the unknown locations in row
			if(grid[row][i][entry-1] == 1) return 0 ;	//is NOT a singleton
		} else {
			if (!checkHorizontal(row, column, entry)) return 0 ;	//check that it has not already been found in the row during singleton algorithm implementation
		}
	}
	return 1 ;
}

int Puzzle::checkVerticalUnknowns(int row, int column, int entry) {
	int i ;
	for ( i = 0 ; i < dimension ; i++) {
		if( i == row) continue ;
		if(!valueDetermined(i, column)) {	//only check the unknown locations in row
			if(grid[i][column][entry-1] == 1) return 0 ;	//is NOT a singleton
		} else {
			if (!checkVertical(row, column, entry)) return 0 ;	//check that it has not already been found in the column during singleton algorithm implementation
		}
	}
	return 1 ;
}
	
int Puzzle::checkMiniGridUnknowns(int row, int column, int entry) {
	int i , j ;
	int minCol, maxCol, minRow, maxRow ;
	int miniGridSize = sqrt(dimension) ;
	//determining the range of the check	
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

	//where the check actually happens
	for ( i = minRow ; i < maxRow ; i++ ) {
		for ( j = minCol ; j < maxCol ; j++ ) {
			if(i == row && j == column) continue ;
			if(!valueDetermined(i, j)) {
				if(grid[i][j][entry-1] == 1) return 0 ;	//is NOT a singleton
			} else {
				if(valueDetermined(i, j) == entry) return 0 ;
			}
		}
	}
	return 1 ;
}		
