/* Samantha Rack, C4Board.cpp
	CSE 20212, Lab 1
	This file is the implementation of member functions of the class C4Board, which uses objects of 
	class C4Column.  The constructor and member functions are defined to allow the Connect Four board 
	to be initialized, displayed, and played with by users.
	This version of the implementation of the member function play introduces a computer player as 
	player 2.
*/

#include <iostream>
#include "C4Col.h"
#include "C4Board.h"
#include <ctime>
#include <cstdlib>

using namespace std ;


C4Board::C4Board() {
	numCols = 7 ;
	board = new C4Col [numCols] ; 	//assigns board as a pointer to dynamically allocated array of numCols (7) C4Col objects
}

C4Board::~C4Board() {
	delete [] board ;
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
	cout << "---------------" << endl ;		//used to display a bottom for the board
}


void C4Board::play() {
	display() ;
	int input ;		//input from user, will be column number or -l to quit
	int compChoice ;
	cout << "Type -1 to quit at any time." << endl ;
	cout << "Player 1, choose a column: " ;
	cin >> input ;
	while ( input != -1) {		
		if( input < 0 || input >= numCols) {		//ensures that the column chosen is not outside of the range of column numbers
			cout << "Invalid column number.  Choose another column:  " ;
			cin >> input ;
			continue ;	//input for player 1 will again be checked
		}
		if( board[input].isFull() ) {			//ensures that the column chosen is not already full
			cout << "Column full.  Choose another column:  " ;
			cin >> input ;
			continue ;	//input for player 1 will again be checked
		}

		cout << endl ;
		board[input].addDisc('X') ;
		display() ;
		if(hasWon(1, input)) break ;

		//computer (player 2) plays
		srand(time(0)) ;
		compChoice = rand() % numCols ;		//computer randomly chooses a column
		while (board[compChoice].isFull()) {	//verifies that the computer's choice is valid
			compChoice = rand() % numCols ;
		}
		board[compChoice].addDisc('O') ;
		cout << endl << "Player 2 (computer) chooses column " << compChoice << "." << endl << endl ;
		display() ;
		if(hasWon(2, compChoice)) break ;

		cout << "Player 1, choose a column: " ;
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
