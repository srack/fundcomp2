/*************************************************************
 * Samantha Rack, Puzzle.h
 * CSE 20212, Lab 6
 * This file contains the interface for the templated class Puzzle, 
 * which is used to implement and solve a game of Sudoku.
 * **********************************************************/

#ifndef PUZZLE_H
#define PUZZLE_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <stdlib.h>

using namespace std ;

class Puzzle {
	friend ostream& operator<<(ostream&, Puzzle&) ;

	public:
		Puzzle(string) ;	//nondefault constructor taking filename as argument
		void print() ;		//prints puzzle object in current state

		void solve() ;		//solves the sudoku puzzle, composition wtih helper functions below to implement search/elimination algorithm and singleton algorithm
		void debugPrint() ;


	private:
		//data members
		vector<vector <vector <int> > > grid ;	//3D vector to store puzzle information, (row, column, potential values)
		int dimension ;		//stores dimensions of the board ie. for 4x4 board, dimension=4
			
		//helper functions
		int valueDetermined(int, int) ;		//determines if a certain location in the grid has been solved, and returns the solved value of this location if it has
		int gameOver() ;	//determines if all of the cells are filled, indicating the end of the game (otherwise returns 0)

		int checkHorizontal(int, int, int) ;	//for elimination algorithm
		int checkVertical(int, int, int) ;
		int checkMiniGrid(int, int, int) ;
		int isEliminated(int, int, int) ;

		int checkHorizontalUnknowns(int, int, int) ;	//for singleton algorithm
		int checkVerticalUnknowns(int, int, int) ;
		int checkMiniGridUnknowns(int, int, int) ;
		int isSingleton(int, int, int) ;		

} ;

#endif

