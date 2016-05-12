/* Samantha Rack, mortgage.cpp
	CSE 20212
	This is the implementation file for class Mortgage.  It defines the constructors (both default and nondefault)
	and member functions that credit the account, return the private variable principal, and
	display the amortization table.
*/	


#include <iostream>
#include <iomanip>
#include "mortgage.h"

using namespace std ;

Mortgage::Mortgage() {	//default constructor definition
	principal = 100000.00 ;
	rate = 4.5 ;		//in percent form, will be converted for calculations
	payment = 2500.00 ;
}


Mortgage::Mortgage(double myPrincipal, double myRate, double myPayment) {	//nondefault constructor
	if(myRate < 0) {
		cout << "Error.  The interest rate cannot be negative.  Interest rate set to default (4.5%)." << endl ;
		myRate = 4.5 ; 			//interest rate is set to default when invalid rate is entered
	}
	if(myPrincipal < 0) {
		cout << "Error.  The principal cannot be negative.  Principal set to default ($100,000)." << endl ;
		myPrincipal = 100000.00 ;	//set to default principal when invalid principal is entered
	}
	if(myPayment < 0) {
		cout << "Error.  The payment cannot be negative.  Payment set to default ($2,500)." << endl ;
		myPayment = 2500.00 ;		//set to default payment when invalid amount is entered
	}

	principal = myPrincipal ;
	rate = myRate ;
	payment = myPayment ;
}

void Mortgage::credit(double value) {		//credits value to the account
	if(value<0) {		//checks that value is a valid input (ie. greater than 0)
		cout << "Error.  The credit cannot be negative" << endl ; 
		value = 0 ;
	}
	principal-= value ;
}

double Mortgage::getPrincipal() {
	return principal ;
}

void Mortgage::amortize() {		//displays amortization table of the mortgage or returns an error message if the payment is too small
	cout << "Month   Payment    Interest    Balance" << endl ;
	int i ;
	double balance = getPrincipal() ;

	if (payment < rate/1200*balance) {
		cout << "Error.  The payment is too small." << endl ;
		return ;
	}

	for (i = 1 ; balance > 0 ; i++) {
		if(payment > balance+rate/1200*balance) payment = balance+rate/1200*balance ;
		cout << setw(5) <<  i  << fixed << setprecision(2) << setw(10) << payment << setw(12) <<  rate/1200*balance << setw(11) << balance + rate/1200*balance - payment ;
		balance= balance - payment + rate/1200*balance ;
		cout << endl ;
	}
}
