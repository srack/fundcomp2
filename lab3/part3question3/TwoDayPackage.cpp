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
	return( flatRate + Package::calculateCost() ) ;		//cannot use pure virtual function calculateCost from Package class because it is not implemented
}

void TwoDayPackage::printLabel() {

	cout << endl << "------------------------------- TWO DAY PACKAGE -----------------------------" << endl ;
	cout << getSName() << endl << getSAddress() << endl << getSCity() << ", " << getSState() << " " << getSZipCode() << endl ;
	cout << setw(30) << " " << getRName() << endl << setw(30) << " " << getRAddress() << endl << setw(30) << " " << getRCity() << ", " << getRState() << " " << getRZipCode() << endl << endl << endl ;
	cout << "-----------------------------------------------------------------------------" << endl ;	
	cout << setw(50) << " " << "Package Weight: " << getWeight() << " oz." << endl ;
	cout << setw(50) << " " << "Price Per Ounce: $" << setprecision(2) << fixed << getCostPerOunce() << endl ;
	cout << setw(50) << " " << "Additional Flat Rate: $" << setprecision(2) << fixed << flatRate << endl ;
	cout << setw(50) << " " << "Shipping Cost: $" << setprecision(2) << fixed << calculateCost() << endl << endl ;
	
}

