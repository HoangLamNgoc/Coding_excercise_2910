# include <bits/stdc++.h>

using namespace std ; 
 
int duong_chay ( long long n ) {
    long long count = 0, dem = 0 , maxval = 1;
    while (n) {
        int units = n % 10 , tens = (n / 10) % 10 ; 
        if ( tens >= units ) {
            dem++ ; 
	        if ( maxval == dem ) count = count + 1 ;
	        else if ( maxval < dem ) {
		        count = 1 ;
				maxval = dem ; 
	        } 
	    }
	    else dem = 0 ;
        n = n / 10 ; 
    }
    return count ; 
}
    
int main () {
    long long num ; 
    cin >> num ; 
    cout << duong_chay ( num ) ; 
    return 0 ; 
}
