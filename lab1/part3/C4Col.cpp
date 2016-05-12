/*  Samantha Rack, C4Col.cpp
	CSE 20212, Lab 1
	This file contains the implementation of member functions of the class C4Col.  It includes 
	a default constructor, initializing the column, and various member functions to perform 
	operations on the column.
*/

#include <iostream>
#include "C4Col.h"

using namespace std ;


C4Col::C4Col() {
	numDiscs = 0 ;		//initial number of discs in the column
	maxDiscs = 6 ;		//number of rows in the grid
	int i ;
	playersDiscs = new char [maxDiscs] ;	//playersDiscs points to dynamically allocated array of maxDiscs(6) chars
	for( i = 0 ; i < maxDiscs ; i++) {	//initializes the array playerDiscs with ' '
		playersDiscs[i] = ' ' ;
	}
}

C4Col::~C4Col() {
	delete [] playersDiscs ;	//frees the dynamically allocated memory
}

int C4Col::isFull() {
	if (numDiscs == getMaxDiscs()) return 1;	//column is full when number of disks equals the max number of disks allowed
	else return 0 ;
}

char C4Col::getDisc(int discNumber) {
	if (discNumber < 0 || discNumber > maxDiscs-1) {
		cout << "Error.  The disc requested does not exist." << endl ;
		return ' ' ;
	}
	return playersDiscs[discNumber] ;
}

int C4Col::getMaxDiscs() {		//get function for private variable maxDiscs
	return maxDiscs ;
}

int C4Col::getNumDiscs() {
	return numDiscs ;
}

void C4Col::addDisc(char newDisc) {
	if( isFull() ) {
		cout << "Error.  The column is full." << endl ;
		return ;
	}
	playersDiscs[numDiscs] = newDisc ;
	numDiscs++ ;			//increment after because array is indexed beginning with 0	

}
