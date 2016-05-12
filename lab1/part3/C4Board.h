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
		~C4Board() ;		//destructor
		void display() ;	//displays the board to the screen
		void play() ;		//begins a game for 2 players

	private:
		int numCols ;
		C4Col * board ;		//pointer to C4Col so an array can be dynamically allocated
		int hasWon(int, int) ;	//determines if either player has won; returns the number of the player who won or 0 if neither has won

};


#endif
