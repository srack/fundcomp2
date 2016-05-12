/* Samantha Rack, mortgage.h
	CSE 20212
	This class will store information about a mortgage including the principal, interest rate, 
	and payment per month.  The constructor initializes those there variables.
*/



#ifndef MORTGAGE_H
#define MORTGAGE_H

#include <iostream>

using namespace std ;

class Mortgage {
	public:
		Mortgage(double, double, double) ;	//nondefault constructor
		Mortgage() ;				//default constructor
		void credit(double value) ;		//credits the mortgage with a payment of amount value
		double getPrincipal() ;			//get function for private variable principal
		void amortize() ;			//displays amortization table or displays an error message if the payment is too small

	private:
		double principal ;
		double rate ;
		double payment ;

};

#endif
