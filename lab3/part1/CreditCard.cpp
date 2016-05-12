/*	Samantha Rack, CreditCard.cpp
 *	CSE 20212, Lab3
 *	The following program is the implementation of derived class CreditCard, which inherits from the base class BankAccount.
 *	*/

#include <iostream>
#include "BankAccount.h"
#include "CreditCard.h"

using namespace std ;

CreditCard::CreditCard(double myBalance, double interest, string name, int myAccount, double myFee, int dayOfMonth) : BankAccount(myBalance, interest, name, myAccount) {
	setLateFee(myFee) ;
	setDueDate(dayOfMonth) ;
}

double CreditCard::getMinimumPayment() {
	return (.1*getBalance()) ;	//returns 10% of the balance of the account
}

void CreditCard::setLateFee(double myFee) {
	lateFee = (myFee < 0.0) ? 0.0 : myFee ;	//late fee cannot be negative
}

double CreditCard::getLateFee() {
	return lateFee ;
}

void CreditCard::setDueDate(int dayOfMonth) {	//dayOfMonth consistent for every month, therefore must be between the 1st and 28th
	dueDate = (dayOfMonth < 1 || dayOfMonth > 28)? 1 : dayOfMonth ;	//default due date is first of month
}

int CreditCard::getDueDate() {
	return dueDate ;
}

void CreditCard::chargeIt(double charge) {
	double newBalance = getBalance()+charge ;	//uses getBalance() inherited from BankAccount class
	setBalance(newBalance) ;
}

void CreditCard::print() {
	cout << "Credit Card Owner: " << getOwner() << endl ;
	cout << "Account Number: " << getAccountNumber() << endl ;
	cout << "This month you charged " << getBalance() << " gold pieces to your account." << endl <<  "Your minimum payment of " << getMinimumPayment() << " gold pieces is due by the " << getDueDate() ;
	switch(getDueDate()) {
		case 1:
		case 21:
			cout << "st" ;
			break ;
		case 2:
		case 22:
			cout << "nd" ;
			break ;
		default:
			cout << "th" ;
	}
	cout <<" or you'll be charged an extra " << getLateFee() << " gold pieces!!" << endl ;
}
