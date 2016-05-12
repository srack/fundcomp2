/*************************************************************
 * Samantha Rack, Puzzle.h
 * CSE 20212, Lab 5
 * This file contains the interface for the class Puzzle, which
 * is used to implement a game of Sudoku.
 * **********************************************************/

#ifndef PUZZLE_H
#define PUZZLE_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std ;

class Puzzle {
	public:
		Puzzle(string) ;	//nondefault constructor taking filename as argument
		void print() ;		//prints puzzle object in current state

	private:
		vector<vector <int> > grid ;	//2D vector to store puzzle information
		int dimension ;		//stores dimensions of the board ie. for 4x4 board, dimension=4
} ;

#endif
