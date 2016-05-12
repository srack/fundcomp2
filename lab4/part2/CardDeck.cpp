/******************************************************
 * Samantha Rack, CardDeck.cpp
 * CSE 20212, Lab 4
 * This file contains the implementation of constructor
 * and member functions of the class CardDeck. 
 * ****************************************************/

#include <iostream>
#include <deque>
#include <algorithm>
#include <iterator>
#include "CardDeck.h"
#include <ctime>

using namespace std ;

CardDeck::CardDeck(int n) {
	srand(time(0)) ;		//seeds random number generator for shuffle helper function
	int i ;
	for( i = 0 ; i < n ; i++ ) {
		deck.push_back(i) ;	//adds an integer element with value i to end of deque
	}
}	

int CardDeck::getSize() {
	return deck.size() ;	//returns number of cards in the deck
}

void CardDeck::shuffle() {
	random_shuffle(deck.begin(), deck.end()) ;
}


ostream& operator<<(ostream& output, CardDeck cards) {
	deque<int>::const_iterator forward ;	//forward iterator to traverse through deck, printing elements
	for (forward = cards.deck.begin() ; forward != cards.deck.end() ; forward++) {
		if (forward+1 != cards.deck.end() ) {
			output << *forward << ", " ;	//dereferences forward iterator as it traverses the deque to print out the cards
		} else {
			output << *forward << endl ;	//there is a new line after the last card instead of a comma
		}
	}
	return output ;		//allows for cascading

}
