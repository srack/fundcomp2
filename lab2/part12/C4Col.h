/*  Samantha Rack, C4Col.h
	CSE 20212, Lab 2
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
		char getDisc(int) const ;	//returns specified element of playersDisks array
		int getMaxDiscs() const ;	//returns maximum number of discs allowed in the column
		int getNumDiscs() const ;	//returns number of discs currently in column
		void addDisc(char) ;		//adds a disc to the column- increments numDisks and adds an element to playersDisks array
		C4Col operator+=(char) ;	//overload of += operator as a member function of C4Col, calls addDisc

	private:
		int numDiscs ;
		int maxDiscs ;
		char playersDiscs[10] ;

};

#endif
