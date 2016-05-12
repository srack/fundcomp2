/*	Samantha Rack, Rational.cpp
	CSE 20212, Lab2
	This file defines the implementation of the class Rational.  It includes function definitions
	for a constructor, an overloaded << operator as a friend function of Rational class, helper
	function to find gcd, and overloaded mathematical operators +, *, ! (inverse), and --.
*/

#include <iostream>
#include <cmath>
#include <ctime>

using namespace std ;

int gcd(int num, int den) ;
int * reallocate(int *ptr, int numPrimes) ;
void print(int *arr, int numElements) ;

int main () {
	int numPrimes = 1 ;
	int *primes = new int [numPrimes] ;
	primes[0] = 2 ;		//initializes first prime
	int i, j ;
	int isPrime ;
	int initTime = time(NULL) ;	//to keep track of 5 minutes (300 seconds) 
	for(i = 3 ; ; i++) {
		isPrime = 1 ;
		for ( j = 0 ; j < numPrimes ; j++) {
			if (gcd(i, primes[j]) != 1) {		//not a prime number
				isPrime = 0 ;
				break ;
			}
		}
		if (isPrime) {
			numPrimes++ ;
			primes = reallocate(primes, numPrimes) ;
			primes[numPrimes-1] = i ;
		//	cout << i << "     " ;
		//	if (numPrimes%10 == 0) cout << endl ;
		}
		if (time(NULL) - initTime > 300) break ;	//program finishes after 5 minutes		 
	}
	print(primes, numPrimes) ;
}



int gcd(int num, int den) {	//implements Euclidean algorithm (referenced discrete math notes) to find greatest common denominator
	int big, little ;
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

int * reallocate(int *ptr, int numPrimes) {
	int *temp = new int [numPrimes] ;
	int i ;
	for ( i = 0 ; i < numPrimes-1 ; i++) {
		temp[i] = ptr[i] ;
	}
	delete [] ptr ;
	ptr = temp ;
	temp = 0 ;
	return ptr ;
}
	

void print(int *arr, int numElements) {
	int i ;
	for (i = 0 ; i < numElements ; i++) {
		cout << arr[i] << "     " ;
		if(i%10 == 0) {
			cout << endl ;
		}
	}
	cout << endl << "Total number of primes found:  " << numElements << endl ;
}


	
