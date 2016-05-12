/* Samantha Rack, piestimate.cpp
	CSE 20212
	Program asks user for number of terms to be used in an estimate of pi 
	and returns the requested value.
*/

#include <iostream>
#include <cmath>

using namespace std ;

int main () {
	int terms ;
	cout << "Please enter the number of terms in the series:  " ;
	cin >> terms ;
	while(terms < 2) {		//checks for valid input
		cout << "Error!  Number of terms must be >=2." << endl ;
		cout << "Please enter the number of terms in the series:  " ;	//request a new number of terms until it is >=2
		cin >> terms ;
	}
	int i ;
	double estimate = 0 ;		//initilizes the estimate before any terms are added to it
	for( i = 1 ; i <= terms ; i++) {		//loops until all terms have been added
		estimate+= pow(-1, i+1)*4/(2*i-1) ;		//formula for each term, added to previous estimate during each iteration
		if( i == 1 ) {
			cout << "Estimate after " << i << " term:   " << estimate << endl ;
			continue ;	//prevents reprinting estimate for first term
		}
		cout << "Estimate after " << i << " terms:  " << estimate << endl ;
	}
	return 0 ;
}
