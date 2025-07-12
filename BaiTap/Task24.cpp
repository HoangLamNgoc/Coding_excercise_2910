# include <bits/stdc++.h>

using namespace std ; 
 
int doan_0 ( int n ) {
    int dem = 0 , maxval = 0 , count = 0 ; 
    while ( n > 0 ) {
		int digit = n % 10 ; 
		if ( digit == 0 ) {
			dem = dem + 1 ; 
			if ( dem > maxval ) {
				maxval = dem ; 
				count = 1 ; 
			}
			else if ( dem == maxval ) count = count + 1 ; 
		}
		else dem = 0 ; 
		n = n / 10 ;
	}
    return count ; 
}
    
int main () {
	int num ; 
	cin >> num ; 
    cout << doan_0 ( num ) ; 
    return 0 ; 
}
    
