/*	Samantha Rack, Package.cpp
 *	CSE 20212, Lab 3
 *	This file contains the implementation of the base class Package.
 *	*/

#include <iostream>
#include "Package.h"

using namespace std ;

Package::Package(string senderName, string senderAddr, string senderCity, string senderState, int senderZC, string recipientName, string recipientAddr, string recipientCity, string recipientState, int recipientZC, double myWeight, double pricePerOunce) {
	sName = senderName ;
	sAddress = senderAddr ;
	sCity = senderCity ;
	sState = senderState ;
	sZipCode = senderZC ;
	rName = recipientName ;
	rAddress = recipientAddr ;
	rCity = recipientCity ;
	rState = recipientState ;
	rZipCode = recipientZC ;
	setWeight(myWeight) ;
	setCostPerOunce(pricePerOunce) ;
	setCost(calculateCost()) ;
}

double Package::calculateCost() {
	return (costPerOunce*weight) ;
}

void Package::setWeight(double  myWeight) {
	if (myWeight < 0) {
		cout << "Error.  The weight cannot be negative.  Setting to default of 0.00 ounces. " << endl ;
		weight = 0.0 ;
	}else {
		weight = myWeight ;
	}
	setCost(calculateCost()) ;
}

void Package::setCostPerOunce(double pricePerOunce) {
	if (pricePerOunce < 0) {
		cout << "Error.  The cost per ounce cannot be negative.  Setting to default of $0.00." << endl ;
	}else {
		costPerOunce = pricePerOunce ;
	}
	setCost(calculateCost()) ;
}

double Package::getWeight() const {
	return weight ;
}

double Package::getCostPerOunce() const {
	return costPerOunce ;
}

void Package::setCost(double myCost){
	cost = (myCost < 0) ? 0.00 : myCost ;
}

string Package::getSName() const {
	return sName ;
}

string Package::getSAddress() const {
	return sAddress ;
}

string Package::getSCity() const {
	return sCity ;
}

string Package::getSState() const {
	return sState ;
}	

int Package::getSZipCode() const {
	return sZipCode ;
}

string Package::getRName() const {
	return rName ;
}

string Package::getRAddress() const {
	return rAddress ;
}

string Package::getRCity() const {
	return rCity ;
}

string Package::getRState() const {
	return rState ;
}

int Package::getRZipCode() const {
	return rZipCode ;
}



