/* Samantha Rack, main.cpp
	CSE 20212, lab 1
	This file is the driver program for part 3 of lab one.  The program creates a C4Board object, and
	runs the member function play() to allow the user to play a connect 4 game with either another user
	(when compiled with C4Board.cpp) or with the computer (when compiled with C4Board2.cpp)
*/


#include <iostream>
#include "C4Col.h"
#include "C4Board.h"

using namespace std ;

int main () {
	C4Board c4 ;
	c4.play() ;
}
