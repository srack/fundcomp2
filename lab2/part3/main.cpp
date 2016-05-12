/*	Samantha Rack, main.cpp
	CSE 20212, Lab2
	This file is the driver program for the class Rational.  This program instantiates two objects of fraction
	class, both initialized by accepting user input.  The program then uses overloaded operators of the class
	Rational to add and multiply the two numbers, to take the inverse of the first number (if such a number
	exists), and to decrement the second number by one.  
*/

#include <iostream>
#include "Rational.h"

using namespace std ;

int main () {
	int num1, num2, den1, den2 ;
	cout << "Please enter a rational number (in form x/y):  " ;
	cin >> num1 ;
	cin.ignore() ;		//ignores "/" character separating the numerator from the denominator
	cin >> den1 ;
	Rational f1(num1, den1) ;	//instantiates first Rational object
	cout << "Please enter a second rational number:  " ;
	cin >> num2 ;
	cin.ignore() ; 
	cin >> den2 ;
	Rational f2(num2, den2) ;	//instantiates second Rational object
	
	cout << "The sum of " << f1 << " + " << f2 << " is " << f1 + f2 << "." << endl ;	//displays the sum of the instantiated objects
	cout << "The product of " << f1 << " and " << f2 << " is " << f1*f2 << "." << endl ;	//displays the product
	if (num1 == 0) {
		Rational dummy = !f1 ;		//for side effects- will tell user that 0 does not have an inverse
	}else {
		cout << "The inverse of " << f1 << " is " << !f1 << "." << endl ;	//displays the inverse of first rational number
	}
	cout << "Decrementing " << f2 ;
	cout << " by 1 results in " << --f2 << "." << endl ;	//decrements second rational number
}
