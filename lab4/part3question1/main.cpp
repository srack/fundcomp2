/********************************************************
Samantha Rack, main.cpp
CSE 20212, Lab 4
This file is a driver program for Part 3 question 1 of 
lab 4.  It instantiates three CardDeck objects (with 7, 
8, and 9 cards), then performs a monkey sort until the 
cards are in order.
*********************************************************/

#include <iostream>
#include "CardDeck.h"

using namespace std ;

int main () {
	CardDeck monkey7(7) ;	//instantiate CardDeck objects with 7	
	CardDeck monkey8(8) ;	//  8 and 9 cards
	CardDeck monkey9(9) ;

	monkey7.shuffle() ;	//shuffle() to get the cards out of order for the first time through the while loop
	monkey8.shuffle() ;
	monkey9.shuffle() ;

	int timesShuffled_m7 = 0 ;
	int timesShuffled_m8 = 0 ;
	int timesShuffled_m9 = 0 ;

	while(!monkey7.inOrder()) {
		timesShuffled_m7++ ;
		monkey7.shuffle() ;	//member function shuffle simulates the monkey drawing cards in random order
	}

	while(!monkey8.inOrder()) {
		timesShuffled_m8++ ;
		monkey8.shuffle() ;
	}
	
	while(!monkey9.inOrder()) {
		timesShuffled_m9++ ;
		monkey9.shuffle() ;	//member function shuffle simulates the monkey drawing cards in random order
	}

	cout << endl << "MONKEY SHUFFLE - TIMES SHUFFLED" << endl ;		//output results of monkey shuffle
	cout << "Seven Card Deck: " << timesShuffled_m7 << endl ;
	cout << "Eight Card Deck: " << timesShuffled_m8 << endl ;
	cout << "Nine Card Deck: " << timesShuffled_m9 << endl << endl ;

	return 0 ;
}
