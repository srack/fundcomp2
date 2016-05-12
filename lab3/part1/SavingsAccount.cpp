/*	Samantha Rack, SavingsAccount.cpp
	CSE 20212, Lab 3
	This file contains the implementation of SavingsAccount, a derived class inheriting from BankAccount.  It includes member function definitions.
*/

#include <iostream>
#include "SavingsAccount.h"
#include "BankAccount.h"

using namespace std ;

SavingsAccount::SavingsAccount(double myBalance, double interest, string name, int myNumber, double myMax, int myLevel) : BankAccount( myBalance, interest, name, myNumber) {
	setMaxBalance(myMax) ;		//set functions verify the input
	setAccountLevel(myLevel) ;
}	

void SavingsAccount::depositTreasure(double myDeposit) {
	if(myDeposit <= 0) {
		cout << "Error.  The balance must be greater than 0!  Nothing was deposited." << endl ;
		return ;
	}
	setBalance(getBalance() + myDeposit) ;		//uses setBalance and getBalance functions inherited from BankAccount class
	cout << "New balance is " << getBalance() << "." << endl ;
}

void SavingsAccount::withdrawTreasure(double myMoney) {
	if(myMoney > getBalance() ) {
		cout << "Error.  The withdrawl amount is greater than the balance.  " << getBalance() << " was withdrawn." << endl ;
		setBalance(0) ;
		return ;
	}
	setBalance(getBalance() - myMoney) ;
	cout << "New balance is " << getBalance() << endl ;
}

double SavingsAccount::getMaxBalance() const {
	return maxBalance ;
}

void SavingsAccount::setMaxBalance(double myMax) {
	if(myMax >= 1000) {		//maximum balance must be at least 1000
		maxBalance = myMax ;
		return ;
	}
	cout << "Error.  Maximum balance must be at least 1000 gold pieces!  Set to 1000. " << endl ;
	maxBalance = 1000 ;
}

int SavingsAccount::getAccountLevel() const {
	return accountLevel ;
}

void SavingsAccount::setAccountLevel(int myLevel) {
	if(myLevel >=0 && myLevel <=3) {
		accountLevel = myLevel ;
		return ;
	}
	cout << "Error.  Invalid account level was entered.  Set to bronze (level 0) member." << endl ;	
	accountLevel = 0 ;
}

void SavingsAccount::print() {
	cout << "Savings Account Owner: " << getOwner() << endl ;
	cout << "Account Number: " << getAccountNumber() << endl ; 
	cout << "You are at account level " ;
	switch(getAccountLevel()) {
		case 0: 
			cout << "bronze. " << endl ;
			break ;
		case 1:
			cout << "silver.  Moving up!" << endl ;
			break ;
		case 2:
			cout << "gold.  A valued customer!" << endl ;
			break ;
		case 3:
			cout << "platinum!  What a pirate!" << endl ;
			break ;
	}
	cout << "Don't forget that you can only hold up to " << getMaxBalance() << " gold pieces!  That's only " << getMaxBalance()-getBalance() << " more." << endl << endl ;
}


