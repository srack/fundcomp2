/*	Samantha Rack, main.cpp
 *	CSE 20212, Lab 3
 *	This file contains the driver program to test the classes Package, TwoDayPackage, and OvernightPackage.  Package is the base class of the derived classes TwoDayPackage and OvernightPackage.  Objects of type TwoDayPackage and OvernightPackage are instantiated, and operations are performed on them.
 *	*/

#include <iostream>
#include "Package.h"
#include "TwoDayPackage.h"
#include "OvernightPackage.h"

using namespace std ;

int main () {
	double packageWeight = 6.78 ;	//in ounces
	double pricePerOunce = 1.05 ;	//in dollars
	double twoDayCharge = 5.00 ;	//additional flat rate charge for two day shipping option, in dollars
	double overnightExtraCostPerOunce = 1.45 ;	//in dollars, extra charge per ounce for overnight packages
	cout << endl << "Price Per Ounce to Ship:  $" << pricePerOunce << endl ;
	cout << "Additional Flat Rate for Two Day Shipping:  $" << twoDayCharge << endl ;
	cout << "Additional Price Per Ounce for Overnight Shipping:  $" << overnightExtraCostPerOunce << endl << endl ;
	
	TwoDayPackage twoDay("Brian Kelly", "111 Notre Dame Avenue", "Notre Dame", "IN", 46556, "Regis Philbin", "1325 Avenue of the Americas", "New York", "NY", 10019, packageWeight, pricePerOunce, twoDayCharge) ;
	twoDay.print() ; 
	OvernightPackage overnight("Father Ted Hesburge", "1401 Hesburgh Library", "Notre Dame", "IN", 46556, "Joe Montana", "10500 Franz Valley Road", "Calistoga", "CA", 94515, packageWeight, pricePerOunce, overnightExtraCostPerOunce) ;
	overnight.print() ;

}
