/* Samantha Rack, C4Board.h
	CSE 20212, Lab 2
	This file defines the class C4Board, which uses the C4Col objects as data members.
*/

#ifndef C4BOARD_H
#define C4BOARD_H

#include <iostream>
#include "C4Col.h"

using namespace std ;

class C4Board {
	friend ostream& operator<<(ostream&, const C4Board&) ;		//overloads the << operator to output the C4Board passed

	public:
		C4Board() ;		//default constructor
		void play() ;		//begins a game for 2 players

	private:
		int numCols ;
		C4Col board[10] ;	//array of C4Col objects, default constructor for C4Col is run
		int hasWon(int, int) ;	//determines if either player has won; returns the number of the player who won or 0 if neither has won

};


#endif
