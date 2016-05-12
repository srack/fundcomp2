/*	Samantha Rack, Rational.cpp
	CSE 20212, Lab2
	This file defines the implementation of the class Rational.  It includes function definitions
	for a constructor, an overloaded << operator as a friend function of Rational class, helper
	function to find gcd, and overloaded mathematical operators +, *, ! (inverse), and --.
*/

#include <iostream>
#include <cmath>
#include "Rational.h"

using namespace std ;

Rational::Rational(int num, int den) {
	if (den == 0) {
		cout << "Error. Denominator cannot equal 0. Denominator set to 1." << endl ;
		denominator = 1 ;
		numerator = num ;	//gcd will be 1 if denominator = 1
		return ;
	} else if (den < 0) {
		den = -den ;	//ensures that the numerator carries the negative sign
		num = -numerator ; 
	} 
	int divideby = gcd(num, den) ;	//number by which to divide to reduce the rational number
	numerator = num/divideby ;
	denominator = den/divideby ;

}


int Rational::gcd(int num, int den) {	//implements Euclidean algorithm (referenced discrete math notes) to find greatest common denominator
	int big, little ;
	num = abs(double(num)) ; 	//ensures gcd will be positive
	if(num > den) {
		big = num ;
		little = den ;
	}else if(num < den) {
		big = den ;
		little = num ;
	}else {
		return num ;	//numerator and denominator are equal, so gcd = num = den
	}

	if (num == 0) return 1 ;	//no gcd for the pair of numbers- dividing by 1 in constructor and in overloaded operators will have no effect

	int rem ;		//remainder for steps of Euclidean algorithm
	int quotient ;		//number by which to multiple little in each step
	do{
		quotient = big/little ;		//truncates any remainder
		rem = big - quotient*little ;
		big = little ;
		little = rem ;
	}while (rem!=0) ;

	return big ;
}

ostream& operator<<(ostream& output, Rational fraction) {
	if (fraction.numerator == 0) {
		output << fraction.numerator ;		//does not print denominator if numerator = 0
	} else {
		output << fraction.numerator << "/" << fraction.denominator ;	//prints in form x/y
	}
	return output ;
}

Rational Rational::operator+(const Rational& fraction) {
	int num1 = this->numerator ;
	int num2 = fraction.numerator ;
	int den1 = this->denominator ;
	int den2 = fraction.denominator ;
	int num = num1*den2 + num2*den1 ;	//must have common denominator
	int divideby = gcd(num,den1*den2) ;	
	return Rational(num/divideby, den1*den2/divideby) ;
}

Rational Rational::operator*(const Rational& fraction) {
	int num = (this->numerator)*fraction.numerator ;
	int den = (this->denominator)*fraction.denominator ;
	int divideby = gcd(num, den) ;
	return Rational(num/divideby, den/divideby) ;
}

Rational Rational::operator!() {		//returns the inverse of Rational object
	if ((this->numerator) < 0 ) {
		return Rational(-(this->denominator), -(this->numerator)) ;	//ensures that the negative sign remains with numerator
	} else if ((this->numerator) == 0) {
		cout << "0 does not have an inverse." << endl ;
		return Rational(this->numerator, this->denominator) ;
	}
	return Rational(this->denominator, this->numerator) ;
}

Rational &Rational::operator--() {
	this->numerator = this->numerator - this->denominator ;
	return *this ;		
}

	
