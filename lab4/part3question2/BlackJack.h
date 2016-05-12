/******************************************************************
 * Samantha Rack, BlackJack.h
 * CSE 20212, Lab 4
 * This file contains the interface of the class BlackJack, which is
 * used to play a BlackJack game with a Dealer (the computer) and
 * a player.  Each BlackJack object is a continuing game between the
 * dealer and a player (user).
 * ***************************************************************/

#ifndef BLACKJACK_H
#define BLACKJACK_H

#include <iostream>
#include "CardDeck.h"

using namespace std ;

class BlackJack {
	public:
		BlackJack() ;	
		int deal() ;	//ensures that there are enough cards in the deck, then returns and removes the top card of the deck
		void play() ;	//begins a BlackJack game

	private:
		int playerWins ;	//keeps track of the number of wins for each 
		int dealerWins ;	//  both initialized to 0 in the constructor
		CardDeck cards ;	//BlackJack object has a CardDeck object (composition), has default initialization of 52 cards in deck		

		void newDeck() ;	//empties old deck and initializes a new deck of 52 cards
		int convertToPointValues(int) ;	//converts the stored card number to the point value of that card
		void printWhichCard(int) ;	//prints the card value (ie. 2, king, etc)
		int isBust(int) ;

};


#endif
