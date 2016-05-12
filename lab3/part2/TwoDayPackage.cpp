/*	Samantha Rack, TwoDayPackage.cpp
 *	CSE 20212, Lab 3
 *	This file contains the implementation of the derived class TwoDayPackage, which inherits from base class Package.
 *	*/

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include "Package.h"
#include "TwoDayPackage.h"

using namespace std ;

TwoDayPackage::TwoDayPackage(string sn, string sa, string sc, string ss, int szc, string rn, string ra, string rc, string rs, int rzc, double myWeight, double pricePerOunce, double extraCost) : Package(sn, sa, sc, ss, szc, rn, ra, rc, rs, rzc, myWeight, pricePerOunce) {
	setFlatRate(extraCost) ;
	setCost(calculateCost()) ;
}

void TwoDayPackage::setFlatRate(double extraCost) {
	if(extraCost < 0) {
		cout << "Error.  The flat rate for sending a two day package cannot be negative.  Setting to $0.00." << endl ;
		flatRate = 0.0 ;
	} else {
		flatRate = extraCost ;
	}
}

double TwoDayPackage::calculateCost() {
	return( flatRate + Package::calculateCost() ) ;
}

void TwoDayPackage::print() {
	cout << endl << "----------------------------- TWO DAY PACKAGE -----------------------------" << endl ;
	cout << left << setw(40) << "Sender: " << setw(40) << "Recipient:" << endl ;
	cout << setw(40) << getSName() << setw(40) << getRName() << endl ;
	cout << setw(40) << getSAddress() << setw(40) << getRAddress() << endl ;
	cout << setw(40) << getSCity() +  ", " + getSState() << setw(40) << getRCity() + ", " + getRState() << endl ; 
	cout << setw(40) << getSZipCode() << setw(40) << getRZipCode() << endl << endl ;
	cout << "The cost of shipping the Two Day Package weighing " << getWeight() << " ounces is $" << setprecision(2) << fixed << calculateCost() << "." << endl ;
	cout << "----------------------------------------------------------------------------" << endl << endl ;



}

