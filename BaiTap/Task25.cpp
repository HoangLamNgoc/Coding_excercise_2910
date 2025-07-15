# include <bits/stdc++.h>

using namespace std ; 
 
long long doan_duong ( long long n ) {
    long long dem = 0 , maxval = 0 ; 
    while (n) {
        int digit = n % 10 ; 
	if ( digit != 0 ) {
            dem = dem + 1 ; 
	    if ( dem > maxval ) maxval = dem ; 
	}
	else dem = 0 ; 	
	n = n / 10 ; 
    }
    return maxval ; 
}
    
int main () {
    long long num ; 
    cin >> num ; 
    cout << doan_duong ( num ) ; 
    return 0 ; 
}
