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
	return(Package::calculateCost() + getWeight()*extraCostPerOunce) ;	//adds extraCostPerOunce times the weight to the base cost
}

void OvernightPackage::print() {
	cout << endl << "---------------------------- OVERNIGHT PACKAGE ----------------------------" << endl ;
	cout << left << setw(40) << "Sender: " << setw(40) << "Recipient:" << endl ;
	cout << setw(40) << getSName() << setw(40) << getRName() << endl ;
	cout << setw(40) << getSAddress() << setw(40) << getRAddress() << endl ;
	cout << setw(40) << getSCity() +  ", " + getSState() << setw(40) << getRCity() + ", " + getRState() << endl ; 
	cout << setw(40) << getSZipCode() << setw(40) << getRZipCode() << endl << endl ;
	cout << "The cost of shipping the Overnight Package weighing " << getWeight() << " ounces is $" << setprecision(2) << fixed << calculateCost() << "." << endl ;
	cout << "----------------------------------------------------------------------------" << endl << endl ;

}

