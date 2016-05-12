#include <iostream>
using namespace std ;
#define NUM_LETTERS 7

int main() {
	char str[NUM_LETTERS] ;
	long long names = 0 ;	
	int repeat ;

	for(int i = 'A' ; i <= 'Z' ; i++) {
		str[0] = i ;
		for(int j = 'A' ; j <= 'Z' ; j++) {
			str[1] = j ;
			for(int k = 'A' ; k <= 'Z' ; k++) {
				str[2] = k ;
				for(int l = 'A' ; l <= 'Z' ; l++) {
					str[3] = l ;
					for(int m = 'A' ; m <= 'Z' ; m++) {
					str[4] = m ;
						for(int o = 'A' ; o <= 'Z' ; o++) {
							str[5] = o ;
							for(int p = 'A' ; p <= 'Z' ; p++) {
								repeat = 0 ;
								str[6] = p ;
								for(int n = 0 ; n < NUM_LETTERS-2; n++) {
									if(str[n] == str[n+1] && str[n] == str[n+2]) repeat = 1 ;
								}
								if(!repeat) {
									//cout << str << endl ;
									//usleep(50000) ;
									names++ ;
								}
							}
						}
					}
				}
			}
		}
	}
	cout << names << " names possible" << endl ;
}
