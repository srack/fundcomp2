/*	Samantha Rack, BankAccount.cpp
	CSE 20212, Lab 3
	This file contains the implementation of the base class, BankAccount.  It includes member function definitions.
*/

#include <iostream>
#include "BankAccount.h"

using namespace std ;

BankAccount::BankAccount(double myBalance, double interest, string name, int myAccountNumber) {
	setBalance(myBalance) ;
	setRate(interest) ;
	setOwner(name) ;
	setAccountNumber(myAccountNumber) ;
}

double BankAccount::getBalance() const {
	return balance ;
}

void BankAccount::setBalance(double myBalance) {
	if (myBalance >= 0) {
		balance = myBalance ;
	} else {
		cout << "Error.  The balance must be greater than or equal to 0.  Balance set to 0." << endl ;
	}
}

double BankAccount::getRate() const {
	return rate ;
}

void BankAccount::setRate(double interest) {
	if (interest >= 0) {
		rate = interest ;
	} else {
		cout << "Error.  The interest rate must be greater than or equal to 0.  Rate set to 2.5%." << endl ;
	}
}

string BankAccount::getOwner() const {
	return owner ;
}

void BankAccount::setOwner(string name) {
	if(name.length() < 25) {
		owner = name ;
	} else {
		cout << "Error.  The owner's name is too long.  Owner's name set to \?\? ." << endl ;
		owner = "??" ;
	}
}

int BankAccount::getAccountNumber() const {
	return accountNumber ;
}

void BankAccount::setAccountNumber(int myAccountNumber) {
	if (myAccountNumber >= 100000 && myAccountNumber < 1000000) {
		accountNumber = myAccountNumber ;
	} else {
		cout << "Error. Account number is not in valid range.  Account number set to 100000." << endl ;
	}

}
