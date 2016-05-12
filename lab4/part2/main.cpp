/***************************************************************
Samantha Rack, main.cpp
CSE 20212, Lab 4
This file is a driver program to test the class CardDeck. A CardDeck 
object is instantiated, initialized to have 10 cards, printed (in 
the sorted order), shuffled, and printed again with it shuffled.
****************************************************************/


#include <iostream>
#include "CardDeck.h"

using namespace std ;

int main () {

	CardDeck cards(10) ;
	cout << "A deck of 10 cards before it is shuffled:" << endl << cards ;
	cards.shuffle() ;
	cout << "The same deck after it has been shuffled:" << endl << cards ;

	return 0 ;

}
