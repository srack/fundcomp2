/*	Samantha Rack, TwoDayPackage.h
 *	CSE 20212, Lab3
 *	This file contains the interface for the derived class OvernightPackage, which inherits from the base class Package.
 *	*/

#ifndef OVERNIGHTPACKAGE_H
#define OVERNIGHTPACKAGE_H

#include <iostream>
#include "Package.h"

using namespace std ;

class OvernightPackage: public Package {
	public:
		OvernightPackage(string=" ", string=" ", string=" ", string=" ", int=11111, string=" ", string=" ", string=" ", string=" ", int=11111, double=0.0, double =0.00, double=0.00) ;
		void setExtraCostPerOunce(double) ;
		double calculateCost() ;	//includes extra charge per ounce
		void print() ;

	private:
		double extraCostPerOunce ;	//charge per ounce for overnight shipping option		

};

#endif
