/* Samantha Rack, C4Board.cpp
	CSE 20212, Lab 2
	This file is the implementation of member function of the class C4Board, which uses objects of class C4Column.  The constructor and member functions are defined to allow the Connect Four board to be initialized, displayed, and played with by users.
*/

#include <iostream>
#include "C4Col.h"
#include "C4Board.h"

using namespace std ;


C4Board::C4Board() {
	numCols = 7 ;
	//board has already been initialized by default constructor of C4Col class
}


void C4Board::play() {
	cout << *this << endl ;	//*this is referencing the current C4Board object, so using it is implementing the overloaded << to print the object
	int input ;		//input from user, will be column number or -l to quit
	int turn = 0 ;
	cout << "Type -1 to quit at any time." << endl ;
	cout << "Player 1, choose a column: " ;
	cin >> input ;
	while ( input != -1) {		
		if( board[input].isFull() ) {			//ensures that the column chosen is not already full
			cout << "Column full.  Choose another column:  " ;
			cin >> input ;
			continue ;	//does not increment, so the player number stays the same
		}
		if( input < 0 || input >= numCols) {		//ensures that the column chosen is not outside of the range of column numbers
			cout << "Invalid column number.  Choose another column:  " ;
			cin >> input ;
			continue ;
		}
		cout << endl ;
		//board[input].addDisc( (((turn%2)+1 == 1) ? 'X' : 'O')) ;
		board[input]+= (turn%2+1 == 1 ? 'X' : '0') ;		
		cout << *this << endl ;
		if (hasWon((turn%2) + 1, input)) {	//hasWon() will return 1 or 2 when one of the players has won (which are logically true values)
			break ;
		}
		turn++ ;
		cout << "Player " << (turn%2) + 1 << ", choose a column: " ;
		cin >> input ; 
	}		
}

int C4Board::hasWon(int player, int chosenColumn) {
	//converts player number to respective character
	char c ;
	if (player == 1) c = 'X' ;
	else c = 'O' ;

	int discsInColumn = board[chosenColumn].getNumDiscs() ;		//location of the last disc played in chosenColumn

	//check vertical - will only check below because there are no discs above the one just played
	int i ;
	int discsInSequence = 0 ;		//variable will keep track of how many discs in a row with respect to the disc that was just played
	for ( i = discsInColumn - 1 ; i >= 0 ; i--) {
		if(board[chosenColumn].getDisc(i) == c) {
			discsInSequence++ ;
			if (discsInSequence == 4) {
				cout << endl << "Player " << player << " wins!!" << endl << endl ;
				return player ;
			}
		}
		else break ;
	}
	discsInSequence = 0 ;			//resets counter for discsInSequence

	//check horizontal
	for ( i = 0 ; i < numCols-chosenColumn; i++) {		//count disks to right, includes current disk
		if(board[chosenColumn+i].getDisc(discsInColumn-1) == c ) {
			discsInSequence++ ;
			if (discsInSequence == 4) {
				cout << endl << "Player " << player << " wins!!" << endl << endl ; 
				return player ;
			}
		}
		else break ;
	}
	for ( i = 1 ; i <= chosenColumn ; i++) {		//count disks to left
		if(board[chosenColumn-i].getDisc(discsInColumn-1) == c ) {
			discsInSequence++ ;
			if (discsInSequence == 4) {
				cout << endl << "Player " << player << " wins!!" << endl << endl ;
				return player ;
			}
		}
		else break ;
		
	}
	discsInSequence = 0 ;		//resets counter for discsInSequence

	//check diagonal /
	for ( i = 0 ; i < numCols-chosenColumn && i <= board[chosenColumn].getMaxDiscs()-discsInColumn; i++) {	
	//checks for limits of board, counts up and to the left, includes current disk 
		if(board[chosenColumn+i].getDisc(discsInColumn-1+i) == c) {
			discsInSequence++ ;
			if (discsInSequence == 4) {
				cout << endl << "Player " << player << " wins!!" << endl << endl ;
				return player ;
			}
		}
		else break ;
	}
	for ( i = 1 ; i <= chosenColumn && i < discsInColumn ; i++) {	//checks for limits of board, counts down and to right
		if(board[chosenColumn-i].getDisc(discsInColumn-1-i) == c) {
			discsInSequence++ ;
			if (discsInSequence == 4) {
				cout << endl << "Player " << player << " wins!!" << endl << endl ;
				return player ;
			}
		}
		else break ;
	}
	discsInSequence = 0 ;		//resets counter for discsInSequence
	
	//check other diagonal \           //
	for ( i = 0  ; i < numCols-chosenColumn && i <discsInColumn ; i++) {	//counts down and to right, includes current disc
		if(board[chosenColumn+i].getDisc(discsInColumn-1-i) == c) {
			discsInSequence++ ;
			if (discsInSequence == 4) {
				cout << endl << "Player " << player << " wins!!" << endl << endl ;
				return player ;
			}
		}
		else break ;
	}
	for ( i = 1 ; i <= chosenColumn && i <= board[chosenColumn].getMaxDiscs()-discsInColumn; i++) {	//counts up and to left
		if(board[chosenColumn-i].getDisc(discsInColumn-1+i) == c) {
			discsInSequence++ ;
			if (discsInSequence == 4) {
				cout << endl << "Player " << player << " wins!!" << endl << endl ;
				return player ;
			}
		}
		else break ;
	}

	return 0 ;


}


ostream& operator<<(ostream& output, const C4Board& b1) {	//global overloaded << operator, friend function of C4Board class
	int i, j ;
	for ( i = 0 ; i < b1.numCols; i++) {		//b1.numCols - accesses private data member of C4Board object parameter
		output << " " << i ;
	}
	output << endl ;
	for (i = b1.board[0].getMaxDiscs() - 1 ; i>=0 ; i--) {	
		output << "|" ;	
		for(j = 0 ; j<b1.numCols ; j++) {
			output << b1.board[j].getDisc(i) << "|" ; 
		}
		output << endl ;
	}
	output << "---------------" << endl ;
	return output ;					//return output to enable cascading; ie. cout << board << endl ;
}

