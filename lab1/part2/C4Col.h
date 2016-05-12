/*  Samantha Rack, C4Col.h
	CSE 20212, Lab 1
	This file defines the class C4Col, which stores the disks for each column in a game 
	of Connect Four.  The class has private data members to store the current number of 
	disks in the column object, the maximum allowed number of disks, and an array to store
	each players' discs.
*/


#ifndef C4COL_H
#define C4COL_H

#include <iostream>

using namespace std ;

class C4Col {
	public:
		C4Col() ;			//default constructor
		int isFull() ;			//returns 1 if the column is full, 0 otherwise
		char getDisc(int) ;		//returns specified element of playersDisks array
		int getMaxDiscs() ;		//returns maximum number of disks allowed in the column
		void addDisc(char) ;		//adds a disc to the column- increments numDisks and adds an element to playersDisks array


	private:
		int numDiscs ;
		int maxDiscs ;
		char playersDiscs[100] ;

};

#endif
