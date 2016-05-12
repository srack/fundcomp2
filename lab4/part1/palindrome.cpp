/**********************************************************
 * Samantha Rack, palindrome.cpp
 * CSE 20212, Lab 4
 * 
 * The following program determines if a given vector is a 
 * palindrome.  
 * *******************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std ;

void printVector(vector<int>) ;	//prototype for printVector, prints in form {a b c}

int main() {
	vector<int> vec1 ;		//instantiates vector object of size 0
	vector<int> vec2 ;

	vec1.push_back(4) ;		//adds one element, 4 to the end of vec1
	vec1.push_back(8) ;
	vec1.push_back(5) ;
	vec1.push_back(4) ;
	
	vec2.push_back(5) ;
	vec2.push_back(2) ;
	vec2.push_back(5) ;

	vector<int>::const_iterator forwardIterator ;	//initializes a forward iterator
	vector<int>::const_reverse_iterator backwardIterator ;
	
	int isPalindrome = 1 ;
	
	for (forwardIterator = vec1.begin(), backwardIterator = vec1.rbegin() ; forwardIterator != vec1.end() ; forwardIterator++, backwardIterator++) {
		if(*forwardIterator != *backwardIterator) {	//dereferences forwardIterator and backwardIterator to compare the values
			isPalindrome = 0 ;	//isPalindrome is false if the dereferenced values from forward and backward interators are not equal
			printVector(vec1) ;
			cout << " is not a palindrome." << endl ;
			break ;
		}
	} 
	if (isPalindrome) {
		printVector(vec1) ;
		cout << " is a palindrome." << endl ;
	}
	isPalindrome = 1 ;
	for (forwardIterator = vec2.begin(), backwardIterator = vec2.rbegin() ; forwardIterator != vec2.end() ; forwardIterator++, backwardIterator++) {
		if(*forwardIterator != *backwardIterator) {
			isPalindrome = 0 ;
			printVector(vec1) ;
			cout << " is not a palindrome." << endl ;
			break ;
		}
	}
	if (isPalindrome) {
		printVector(vec2) ;
		cout << " is a palindrome." << endl ;
	}

	return 0 ;
}

void printVector(vector<int> myVec) {
	vector<int>::const_iterator i ;
	cout << "{ " ;
	for(i = myVec.begin() ; i != myVec.end() ; i++) {
		cout << *i << " " ;
	}
	cout<< "}" ;
}
