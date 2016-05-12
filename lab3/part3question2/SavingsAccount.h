/*	Samantha Rack, SavingsAccount.h
	CSE 20212, Lab3
	This file contains the interface for class SavingsAccount, a derived class inheriting from BankAccount.
*/

#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

#include <iostream>
#include "BankAccount.h"

using namespace std ;

class SavingsAccount : public BankAccount {
	public:
		SavingsAccount(double = 10000, int = 0) ;		//constructor for class
		void depositTreasure(double) ;	//deposits money and increases the balance
		void withdrawTreasure(double) ;	//subtracts argument amount from the balance, ensures that the balance is sufficient
		double getMaxBalance() const ;	//returns the maxBalance of the given account
		void setMaxBalance(double) ;	//set function for private data member maxBalance
		int getAccountLevel() const ;	//returns the account type
		void setAccountLevel(int) ;
		void setBankName(string) ;	//gives access to setOwner function in BankAccount object
		void print() ;

	private:
		double maxBalance ;		//the maximum amount of money able to be stored in the account
		int accountLevel ;		//can be Bronze(0), Silver(1), Gold(2), or Platinum(3) member
		BankAccount bank1 ;		//composition, BankAccount object is a private data member of SavingsAccount class
} ;

#endif
