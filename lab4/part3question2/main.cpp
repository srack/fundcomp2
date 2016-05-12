/***************************************************************
Samantha Rack, main.cpp
CSE 20212, Lab 4
This file is a driver program to test the class BlackJack. A 
BlackJack object is instantiated, then a BlackJack game is started
using the BlackJack class member function, play().  This game 
continues until the user decides to quit.
****************************************************************/


#include <iostream>
#include "CardDeck.h"
#include "BlackJack.h"

using namespace std ;

int main () {
	BlackJack game ;
	game.play() ;	

	return 0 ;

}
