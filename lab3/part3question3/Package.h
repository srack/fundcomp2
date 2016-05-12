/*	Samantha Rack, Package.h
 *	CSE 20212, Lab3
 *	This file contains the interface for base class Package. 
 *	*/

#ifndef PACKAGE_H
#define PACKAGE_H

#include <iostream>

using namespace std ;

class Package {
	public:
		Package(string=" ", string=" ", string=" ", string=" ", int=11111, string=" ", string=" ", string=" ", string=" ", int=11111, double=0.00, double=0.00) ;	//nondefault constructor with default values, initializes all private variables and verifies validity of the inputs
		virtual double calculateCost() ;	//virtual function
		virtual void printLabel() = 0 ;		//pure virtual function
		
		void setWeight(double) ;	//verifies that weight is valid (ie. not negative)
		double getWeight() const ;
		void setCostPerOunce(double) ;
		double getCostPerOunce() const ;
		void setCost(double) ;
		
		string getSName() const ;
		string getSAddress() const ;
		string getSCity() const ;
		string getSState() const ;
		int getSZipCode() const ;
		string getRName() const ;
		string getRAddress() const ;
		string getRCity() const ;
		string getRState() const ;
		int getRZipCode() const ;
		

	private:
		string sName ;		//sender information
		string sAddress ;
		string sCity ;
		string sState ;
		int sZipCode ;
		
		string rName ;		//recipient information
		string rAddress ;
		string rCity ;
		string rState ;
		int rZipCode ;

		double weight ;	//weight of the package being sent, in ounces
		double costPerOunce ;	//in dollars 
		double cost ;	//cost to ship from sender to recipient at the given weight

};

#endif
