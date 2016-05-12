/*	Samantha Rack, main.cpp
 *	CSE 20212, Lab 3
 *	This file is the driver program to test the base class BankAccount and its derived classes SavingsAccount and CreditCard.  The program instantiates two SavingsAccount objects (one use the default arguments for the constructor) and one user defined CreditCard object.
 *	*/


#include <iostream>
#include "BankAccount.h"
#include "SavingsAccount.h"
#include "CreditCard.h"

using namespace std ;

int main () {
	SavingsAccount mySavings(50000, 2) ; 
	mySavings.depositTreasure(400) ;
	mySavings.setBankName("Captain Jack") ;
	mySavings.print() ;
	CreditCard myCreditCard(50, 4) ;
	myCreditCard.chargeIt(60) ;
	myCreditCard.setBankName("Captain Joe") ;
	myCreditCard.print() ;

}
