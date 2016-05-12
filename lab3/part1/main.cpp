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
	SavingsAccount s1(10000, 3.4, "Captain Jack", 123456, 50000, 2) ; 
	s1.depositTreasure(400) ;
	s1.print() ;
	CreditCard c1(600, 6.7, "Captain Joe", 234567, 50, 4) ;
	c1.chargeIt(60) ;
	c1.print() ;

}
