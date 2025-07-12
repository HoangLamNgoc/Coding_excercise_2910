 # include <bits/stdc++.h>

using namespace std ; 
 
int doan_duong ( int n ) {
    int dem = 0 , maxval = 0 ; 
    while ( n > 0 ) {
		int digit = n % 10 ; 
		if ( digit != 0 ) {
		  dem = dem + 1 ; 
			if ( dem > maxval )
				maxval = dem ; 
		}
		else dem = 0 ; 	
		n = n / 10 ; 
	}
    return maxval ; 
}
    
int main () {
	int num ; 
	cin >> num ; 
    cout << doan_duong ( num ) ; 
    return 0 ; 
}
    
