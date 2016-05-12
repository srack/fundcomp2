/*	Samantha Rack, main.cpp
 *	CSE 20212, Lab 3
 *	This file contains the driver program to test the classes Package, TwoDayPackage, and OvernightPackage.  Package is the base class of the derived classes TwoDayPackage and OvernightPackage.  Objects of type TwoDayPackage and OvernightPackage are instantiated, and operations are performed on them.
 *	*/

#include <iostream>
#include <iomanip>
#include "Package.h"
#include "TwoDayPackage.h"
#include "OvernightPackage.h"

using namespace std ;

int main () {
	Package *PackagePtr[6] = {0} ;	//initialize the pointers to NULL	
	TwoDayPackage twoDay1("Brian Kelly", "111 Notre Dame Avenue", "Notre Dame", "IN", 46556, "Regis Philbin", "1325 Avenue of the Americas", "New York", "NY", 10019, 4.56, 1.35, 4.55) ;
	TwoDayPackage twoDay2("Mike Brey", "112 Notre Dame Avenue", "Notre Dame", "IN", 46556, "Brady Quinn", "234 Champion's Drive", "Avon Lake", "OH", 44012, 9.12, 1.15, 4.25) ;
	TwoDayPackage twoDay3("Rev. John Jenkins", "113 Main Circle", "Notre Dame", "IN", 46556, "Rev. Edward Malloy", "5437 Main Street", "South Bend", "IN", 46601, 5.12, 1.20, 5.10) ;
	OvernightPackage overnight1("Father Ted Hesburgh", "1401 Hesburgh Library", "Notre Dame", "IN", 46556, "Joe Montana", "10500 Franz Valley Road", "Calistoga", "CA", 94515, 5.67, 1.40, 1.30) ;
	OvernightPackage overnight2("Mike Golic", "4754 ESPN Avenue", "New York", "NY", 10024, "Muffet McGraw", "876 Sorin Avenue", "Indianapolis", "IN", 76982, 2.56, 1.35, 1.55) ; 
	OvernightPackage overnight3("Charlie Weis", "546 GoIrish Drive", "DeMoinse", "IA", 24893, "Phil Donahue", "420 E. 54th Street", "New York", "NY", 10022, 12.59, 1.05, 1.45) ;

	PackagePtr[0] = &twoDay1 ;	//Package pointer pointing to TwoDayShipping object
	PackagePtr[1] = &twoDay2 ;
	PackagePtr[2] = &twoDay3 ;
	PackagePtr[3] = &overnight1 ;	//Package pointer pointing to OvernightShipping object
	PackagePtr[4] = &overnight2 ;
	PackagePtr[5] = &overnight3 ;

	int i ;
	double totalCost = 0 ;
	cout << endl ;
	for ( i = 0 ; i < 6 ; i++) {
		PackagePtr[i]->printLabel() ;	//will invoke the appropriate derived class member functions printLabel
		totalCost += PackagePtr[i]->calculateCost() ;
	}
	cout << "Total cost to ship the packages is $" << setprecision(2) << fixed << totalCost << "." << endl << endl ;

}
