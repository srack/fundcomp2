/*	Samantha Rack, BankAccount.h
	CSE 20212, Lab 3
	This file contains the interface for the base class BankAccount.
*/

#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <iostream>

using namespace std ;

class BankAccount {
	public:
		BankAccount(double = 0, double = 2.5, string = "??", int = 100000) ;		//constructor for class BankAccount objects
		double getBalance() const ;	//returns private data member balance
		void setBalance(double) ;	//set function for private data member balance
		double getRate() const ;	//returns private data member rate
		void setRate(double) ;		//set function for rate
		string getOwner() const ;	//returns private data member owner
		void setOwner(string) ;		//set function for owner
		int getAccountNumber() const ;	//returns private data member accountNumber
		void setAccountNumber(int) ;	//set function for account number

	private:
		double balance ;	//amount in the account
		double rate ;		//rate of interest
		string owner ;		//name of bank account's owner
		int accountNumber ;	//6 digit account number
};

#endif
