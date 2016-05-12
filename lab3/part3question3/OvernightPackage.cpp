/*	Samantha Rack, OvernightPackage.cpp
 *	CSE 20212, Lab 3
 *	This file contains the implementation of the derived class OvernightPackage, which inherits from base class Package.
 *	*/

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include "Package.h"
#include "OvernightPackage.h"

using namespace std ;

OvernightPackage::OvernightPackage(string sn, string sa, string sc, string ss, int szc, string rn, string ra, string rc, string rs, int rzc, double myWeight, double pricePerOunce, double extraCharge) : Package(sn, sa, sc, ss, szc, rn, ra, rc, rs, rzc, myWeight, pricePerOunce) {
	setExtraCostPerOunce(extraCharge) ;	
	setCost(calculateCost()) ;
}

void OvernightPackage::setExtraCostPerOunce(double extraCharge) {
	extraCostPerOunce = (extraCharge < 0.00) ? 0.00 : extraCharge ;		//verifies that the extra charge is not negative
} 

double OvernightPackage::calculateCost() {
	return(getWeight()*(extraCostPerOunce+getCostPerOunce())) ;	//adds extraCostPerOunce times the weight to the base cost
}

void OvernightPackage::printLabel() {
	cout << endl << "---------------------------- OVERNIGHT PACKAGE -----------------------------" << endl ;
	cout << getSName() << endl << getSAddress() << endl << getSCity() << ", " << getSState() << " " << getSZipCode() << endl ;
	cout << setw(30) << " " << getRName() << endl << setw(30) << " " << getRAddress() << endl << setw(30) << " " << getRCity() << ", " << getRState() << " " << getRZipCode() << endl << endl << endl ;
	cout << "----------------------------------------------------------------------------" << endl ;
	cout << setw(50) << " " << "Package Weight: " << getWeight() << " oz." << endl ;
	cout << setw(50) << " " << "Price Per Ounce: $" << setprecision(2) << fixed << getCostPerOunce() << endl ;
	cout << setw(50) << " " << "Additional Price: $" << setprecision(2) << fixed << extraCostPerOunce << "/oz." <<  endl ;
	cout << setw(50) << " " << "Shipping Cost: $" << setprecision(2) << fixed << calculateCost() << endl << endl ;
}

