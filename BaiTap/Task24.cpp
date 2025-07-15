# include <bits/stdc++.h>

using namespace std ; 
 
long long doan_0 ( long long n ) {
    long long count = 0 ;
    bool in_zero = false ; 
    while (n) {
        int digit = n % 10 ; 
        if ( digit == 0 ) { 
            if (!in_zero) {
	        count++ ; 
	        in_zero = true ; 
	    }
	}
        else in_zero = false ;  
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
    
