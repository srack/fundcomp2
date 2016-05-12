/* Samantha Rack, main.cpp
	CSE 20212
	This is the driver program for the class Mortgage.  It creates 2 mortgage objects, one default and
	the other uses the nondefault constructor to initialize private variables.  This program also implements
	member functions from Mortgage.
*/

#include <iostream>
#include "mortgage.h"

using namespace std ;

int main() {
	Mortgage first(10000, 5.0, 500) ;	//uses non-default constructor
	Mortgage second ;			//uses default constructor, mortage for $100,000 at 4.5% interest and $2,500 payment

	second.credit(10000) ;
	cout << "Current balance after rediting second mortgage 10K: " << second.getPrincipal() << endl ;

	cout << "Amortization schedule for first mortgage:" << endl ;
	first.amortize() ;
}
