# include <bits/stdc++.h>

using namespace std ; 
 
int duong_chay ( long long n ) {
    long long dem = 0 , maxval = 0 ; 
    n = abs(n) ;
    while ( n > 0 ) {
        int unit = n % 10 , tens = ( n / 10 ) % 10 ; 
        if ( unit <= tens ) {
             dem++ ; 
	     if ( dem > maxval ) maxval = dem ; 
	}
	else dem = 0 ; 	
	n = n / 10 ; 
    }
    return maxval + 1 ; 
}
    
int main () {
    long long num ; 
    cin >> num ; 
    cout << duong_chay ( num ) ; 
    return 0 ; 
}
    
