/* Samantha Rack, C4Board.cpp
	CSE 20212, Lab 1
	This file is the implementation of member function of the class C4Board, which uses objects of class C4Column.  The constructor and member functions
	are defined to allow the Connect Four board to be initialized, displayed, and played with by users.
*/

#include <iostream>
#include "C4Col.h"
#include "C4Board.h"

using namespace std ;


C4Board::C4Board() {
	numCols = 7 ;
	//board has already been initialized by default constructor of C4Col class
}


void C4Board::display() {
	int i, j ;
	cout << " 0 1 2 3 4 5 6 " << endl ;
	for (i = board[0].getMaxDiscs() - 1 ; i>=0 ; i--) {	//board[0].getMaxDiscs() returns maxDiscs of each of the columns (initialized by constructor),
		cout << "|" ;						//  subtract one because of the arrays indexing; this for loop moves down the rows
		for(j = 0 ; j<numCols ; j++) {			//this for loop moves across the columns
			cout << board[j].getDisc(i) << "|" ; 
		}
		cout << endl ;
	}
	cout << "---------------" << endl ;
}


void C4Board::play() {
	display() ;
	int input ;		//input from user, will be column number or -l to quit
	int turn = 0 ;
	cout << "Type -1 to quit at any time." << endl ;
	cout << "Player 1, choose a column: " ;
	cin >> input ;
	while ( input != -1 ) {		//&& !hasWon()
		if( board[input].isFull() ) {
			cout << "Column full.  Choose another column:  " ;
			cin >> input ;
			continue ;
		}
		if( input < 0 || input >= numCols) {
			cout << "Invalid column number.  Choose another column:  " ;
			cin >> input ;
			continue ;
		}
		cout << endl ;
		board[input].addDisc( (((turn%2)+1 == 1) ? 'X' : 'O')) ;
		display() ;
		turn++ ;
		cout << "Player " << (turn%2) + 1 << ", choose a column: " ;
		cin >> input ; 
	}		

}


