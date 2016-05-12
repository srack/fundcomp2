/*	Samantha Rack, CreditCard.h
 *	CSE 20212, Lab 3
 *	This file contains the interface for the derived class Credit Card, inheriting from base class BankAccount.
 *	*/

#ifndef CREDITCARD_H
#define CREDITCARD_H

#include <iostream>
#include "BankAccount.h"

using namespace std ;

class CreditCard : public BankAccount {
	public:
		CreditCard(double = 30, int = 4) ;	//constructor arguments include those for base class constructor implementation
		double getMinimumPayment() ;	//10% of balance on card
		void setLateFee(double) ;
		double getLateFee() ;
		void setDueDate(int) ;		//day between 1-28 (must be same for each month, February has only 28 days)
		int getDueDate() ;
		void chargeIt(double) ;		//adds a charge to the account
		void print() ;			//prints information about CreditCard account
		void setBankName(string) ;	

	private:
		double lateFee ;	//how much of a late fee must be paid if the payment is late
		int dueDate ;	//day on which the payment is due
		BankAccount bank1 ;	//composition used, BankAccount object is instantiated as a private data member of CreditCard

} ;

#endif
