# include <bits/stdc++.h>

using namespace std ; 
 
int duong_chay ( int n ) {
    int dem = 0 , count = 0 , maxval = 0  ; 
    while ( n > 0 ) {
        int unit = n % 10 , tens = ( n / 10 ) % 10 ; 
	    if ( unit <= tens ) {
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
    cout << duong_chay ( num ) ; 
    return 0 ; 
}
    
