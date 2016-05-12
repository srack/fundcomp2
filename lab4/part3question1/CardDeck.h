/********************************************************
 * Samantha Rack, CardDeck.h
 * CSE 20212, Lab 4
 * This file contains the interface for the class CardDeck.
 * *****************************************************/

#ifndef CARDDECK_H
#define CARDDECK_H

#include <iostream>
#include <deque>
#include <algorithm>

using namespace std ;

class CardDeck{
	friend ostream& operator <<(ostream&, CardDeck) ;	//overloaded output operator

	public:
		CardDeck(int = 52) ;		//nondefault constructor with default value of 52 cards
		int getSize() ;			//returns the number of cards in CardDeck object
		void shuffle() ;		//shuffles the cards in the deck using STL algorithm
		int inOrder() ;			//returns true(1) if the deck is currently in increasing order, false(0) if not


	private:
		deque<int> deck ; 

};

#endif
