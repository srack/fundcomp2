/*	Samantha Rack, Rational.h
	CSE 20212, Lab 2
	This file defines the class Rational, which includes private data members storing the numerator
	and denominator of each object.  It also defines functions that can be performed on rational
	numbers, including overloaded operators.
*/

#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>

using namespace std ;

class Rational {
	friend ostream& operator<<(ostream& , Rational) ;	//must be global because Rational type is not first argument


	public:
		Rational(int = 1, int = 1) ;	//nondefault constructor with default values
		Rational operator+(const Rational&) ;	//overloaded + operator
		Rational operator*(const Rational&) ;	//overloaded multiplication operator
		Rational operator!() ;		//overloaded to be the inverse function	
		Rational &operator--() ;		//overloaded pre-decrement operator

	private:
		int numerator ;		//every rational number can be written as a fraction with a numerator
		int denominator ;	//  and a denominator that are integers
		int gcd(int, int) ;	//helper function that finds the greatest common divisor of 2 integers


};

#endif
