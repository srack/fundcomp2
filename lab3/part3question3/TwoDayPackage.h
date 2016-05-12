/*	Samantha Rack, TwoDayPackage.h
 *	CSE 20212, Lab3
 *	This file contains the interface for the derived class TwoDayPackage, which inherits from the base class Package.
 *	*/

#ifndef TWODAYPACKAGE_H
#define TWODAYPACKAGE_H

#include <iostream>
#include "Package.h"

using namespace std ;

class TwoDayPackage: public Package {
	public:
		TwoDayPackage(string=" ", string=" ", string=" ", string=" ", int=11111, string=" ", string=" ", string=" ", string=" ", int=11111, double=0.0, double =0.00, double=0.00) ;
		void setFlatRate(double) ;
		virtual double calculateCost() ;	//virtual function, implemetned in TwoDayPacakge.cpp
		virtual void printLabel() ;		//virtual function, prints the label information for both the sender and recipient

	private:
		double flatRate ;	//charge for two day shipping option		

};

#endif
