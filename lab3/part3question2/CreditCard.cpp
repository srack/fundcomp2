/*	Samantha Rack, CreditCard.cpp
 *	CSE 20212, Lab3
 *	The following program is the implementation of derived class CreditCard, which inherits from the base class BankAccount.
 *	*/

#include <iostream>
#include "BankAccount.h"
#include "CreditCard.h"

using namespace std ;

CreditCard::CreditCard(double myFee, int dayOfMonth) {	//BankAccount private data member bank1 initialized by its default constructor
	setLateFee(myFee) ;
	setDueDate(dayOfMonth) ;
}

double CreditCard::getMinimumPayment() {
	return (.1*bank1.getBalance()) ;	//with composition, each member function implemented from bank1 has to be referred to using . operator
}

void CreditCard::setLateFee(double myFee) {
	lateFee = (myFee < 0.0) ? 0.0 : myFee ;	//late fee cannot be negative
}

double CreditCard::getLateFee() {
	return lateFee ;
}

void CreditCard::setDueDate(int dayOfMonth) {
	dueDate = (dayOfMonth < 1 || dayOfMonth > 28)? 1 : dayOfMonth ;	//default due date is first of month
}

int CreditCard::getDueDate() {
	return dueDate ;
}
 
void CreditCard::chargeIt(double charge) {
	double newBalance = bank1.getBalance()+charge ;
	bank1.setBalance(newBalance) ;
}

void CreditCard::print() {
	cout << "Credit Card Owner: " << bank1.getOwner() << endl ;
	cout << "Account Number: " << bank1.getAccountNumber() << endl ;
	cout << "This month you charged " << bank1.getBalance() << " gold pieces to your account." << endl <<  "Your minimum payment of " << getMinimumPayment() << " gold pieces is due by the " << getDueDate() ;
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

void CreditCard::setBankName(string name) {
	bank1.setOwner(name) ;
}
