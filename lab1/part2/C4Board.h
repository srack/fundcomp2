/* Samantha Rack, C4Board.h
	CSE 20212, Lab 1
	This file defines the class C4Board, which uses the C4Col objects as data members.
*/

#ifndef C4BOARD_H
#define C4BOARD_H

#include <iostream>
#include "C4Col.h"

using namespace std ;

class C4Board {
	public:
		C4Board() ;		//default constructor
		void display() ;	//displays the board to the screen
		void play() ;		//begins a game for 2 players

	private:
		int numCols ;
		C4Col board[100] ;	//array of C4Col objects, default constructor for C4Col is run

};


#endif
