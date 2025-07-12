# include <bits/stdc++.h>

using namespace std ; 
 
int duong_chay ( int n ) {
    int dem = 0 , maxval = 0 ; 
    while ( n > 0 ) {
        int unit = n % 10 , tens = ( n / 10 ) % 10 ; 
	    if ( unit = tens - 1 ) {
            dem = dem + 1 ; 
	        if ( dem > maxval ) maxval = dem ; 
	    }
	else dem = 0 ; 	
	n = n / 10 ; 
    }
    return maxval ; 
}
    
int main () {
    int num ; 
    cin >> num ; 
    cout << duong_chay ( num ) ; 
    return 0 ; 
}
    
