/*	Samantha Rack, SavingsAccount.cpp
	CSE 20212, Lab 3
	This file contains the implementation of SavingsAccount, a derived class inheriting from BankAccount.  It includes member function definitions.
*/

#include <iostream>
#include "SavingsAccount.h"
#include "BankAccount.h"

using namespace std ;

SavingsAccount::SavingsAccount(double myMax, int myLevel){	//BankAccount private data member bank1 initialized by BankAccount's default constructor
	setMaxBalance(myMax) ;
	setAccountLevel(myLevel) ;
}	

void SavingsAccount::depositTreasure(double myDeposit) {
	if(myDeposit < 0) {
		cout << "Error.  The balance must be greater than 0!  Nothing was deposited." << endl ;
		return ;
	}
	if(myDeposit + bank1.getBalance() > getMaxBalance()) {
		cout << "Error.  You have exceeded your maximum balance.  Only " << getMaxBalance()-bank1.getBalance() << " was deposited." << endl ;
		setBalance(getMaxBalance()) ;
	}
	bank1.setBalance(bank1.getBalance() + myDeposit) ;	//each member function of BankAccount must be called using the . operator
	cout << "New balance is " << bank1.getBalance() << "." << endl ;
}

void SavingsAccount::withdrawTreasure(double myMoney) {
	if(myMoney > bank1.getBalance() ) {
		cout << "Error.  The withdrawl amount is greater than the balance.  " << bank1.getBalance() << " was withdrawn." << endl ;
		bank1.setBalance(0) ;
		return ;
	}
	bank1.setBalance(bank1.getBalance() - myMoney) ;
	cout << "New balance is " << bank1.getBalance() << endl ;
}

double SavingsAccount::getMaxBalance() const {
	return maxBalance ;
}

void SavingsAccount::setMaxBalance(double myMax) {
	if(myMax >= 1000) {
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
	cout << "Savings Account Owner: " << bank1.getOwner() << endl ;
	cout << "Account Number: " << bank1.getAccountNumber() << endl ; 
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
	cout << "Don't forget that you can only hold up to " << getMaxBalance() << " gold pieces!  That's only " << getMaxBalance()-bank1.getBalance() << " more." << endl << endl ;
}

void SavingsAccount::setBankName(string name) {
	bank1.setOwner(name) ;
}
