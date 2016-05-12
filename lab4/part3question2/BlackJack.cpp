/******************************************************
 * Samantha Rack, BlackJack.cpp
 * CSE 20212, Lab 4
 * This file contains the implementation for the class
 * BlackJack.
 *****************************************************/

#include <iostream>
#include "CardDeck.h"
#include "BlackJack.h"

using namespace std ;


BlackJack::BlackJack() {	//takes no arguments, BlackJack game/deck is standard
	playerWins = 0 ;	//always begin a game with 0 wins for each
	dealerWins = 0 ;
	newDeck() ;		//deck always has 52 cards numbered 0-51
}


void BlackJack::newDeck() {
	int i ;
	if (cards.getSize() != 0) {
		cards.emptyDeck() ;	//empties the current deck
	}
	for(i = 0 ; i < 52 ; i++) {
		cards.addEndCard(i) ;
	}	//adds 52 cards to the deck
	cards.shuffle() ;	//shuffles the new deck, srand() executed in constructor of CardDeck
//	cout << "New card deck: " << cards ;	//for verifying output
}

int BlackJack::deal() {
	int cardNumber ;
	if(cards.getSize() < 15) {
		newDeck() ;	//open a new deck when not enough cards
	}
	cardNumber = cards.removeTopCard() ;	//cardNumber assigned value of top card
	printWhichCard(cardNumber) ;	//prints the card that was drawn
	cout << endl ;	
	int pointValue = convertToPointValues(cardNumber) ;
	return pointValue ;	//returns a number that will be translated into a meaningful card	
}




int BlackJack::convertToPointValues(int cardNumber) {
	int pointValue ;	
	if (cardNumber % 13 <= 8){	//values 2-10
		pointValue = (cardNumber % 13) + 2 ;
	}else if (cardNumber % 13 >= 9 && cardNumber % 13 <= 11) {
		pointValue = 10 ;	//all face cards (except ace) have a value of 10
	}else {		//only ace cards are left
		pointValue = 11 ;
	}
	return pointValue ;
} 


void BlackJack::printWhichCard(int cardNumber) {
	switch(cardNumber%13) {
		case 0:	cout << "  Two (2 points)" ; break ;
		case 1: cout << "  Three (3 points)" ; break ;
		case 2: cout << "  Four (4 points)" ; break ;
		case 3: cout << "  Five (5 points)" ; break ;
		case 4: cout << "  Six (6 points)" ; break ;
		case 5: cout << "  Seven (7 points)" ; break ;
		case 6: cout << "  Eight (8 points)" ; break ;
		case 7: cout << "  Nine (9 points)" ; break ;
		case 8: cout << "  Ten (10 points)" ; break ;
		case 9: cout << "  Jack (10 points)" ; break ;
		case 10: cout << "  Queen (10 points)" ; break ;
		case 11: cout << "  King (10 points)" ; break ;
		case 12: cout << "  Ace (11 points)" ; break ;
	}
}


int BlackJack::isBust(int total) {
	if(total > 21) return 1 ;
	else return 0 ;
}


void BlackJack::play() {
	int playerTotal ;
	int dealerTotal ;
	int hit ;	//keeps track of if player wants to hit		
	int keepPlaying = 1 ;	//does player want to continue the game?	
	while(keepPlaying) {
		playerTotal = 0 ;	//resets totals for next round
		dealerTotal = 0 ;
		hit = 1 ;
		cout << "---------------------------------" << endl ;
		cout << "PLAYER" << endl ;
		while(hit) {
			playerTotal += deal() ;
			if(isBust(playerTotal)) {
				cout << "Bust! Total points was " << playerTotal << "." << endl ;
				dealerWins++ ;	//increment private data member dealerWins
				break ;
			}
			cout << "Total points is " << playerTotal << ".  Hit? (yes-1, no-0): " ;
			cin >> hit ;
		}
		if (!isBust(playerTotal)) cout << endl << "DEALER" << endl ;
		while(!isBust(playerTotal) && dealerTotal < 17 ) {
			dealerTotal += deal() ;
			if(isBust(dealerTotal)) {
				cout << "Dealer busts! Total points was " << dealerTotal << ". Player wins!"  << endl ;
				playerWins++ ;
				break ;
			}
			usleep(500000) ;	//a new card the dealer draws for a hit is displayed every .5 seconds
		}
		if(!isBust(playerTotal) && !isBust(dealerTotal)) {
			cout << "Player had " << playerTotal << " points.  Dealer had " << dealerTotal << " points." << endl ;
			if (playerTotal > dealerTotal) {
				cout << "Player wins!" << endl ;
				playerWins++ ;
			} else {		//dealer wins on a tie
				cout << "Dealer wins." << endl ;
				dealerWins++ ;
			}		
		}
		cout << endl << "Player's wins:  " << playerWins << endl ;
		cout << "Dealer's wins:  " << dealerWins << endl << endl ;
		cout << "Play again? (1-yes, 0-no): " ;
		cin >> keepPlaying ;	//does not validate input, will continue playing unless 0 is entered
	}
}





