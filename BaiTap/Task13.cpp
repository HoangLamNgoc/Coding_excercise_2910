#include <bits/stdc++.h> 

using namespace std; 

int main () {
    int n; int tong = 0 ; 
    cin >> n ; 
    while ( n > 0 ) {
		int i = n % 10 ; 
        if ( i % 2 == 1 ) tong = tong + i; 
        n = n / 10 ; 
	}
	cout << tong ; 
	return 0 ; 
} 
        
