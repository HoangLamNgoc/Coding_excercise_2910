# include <bits/stdc++.h> 

using namespace std ; 

int max_digit(int n) {
    int maxval = -1 ; 
    while ( n > 0 ) {
        int digit = n % 10 ;
        if ( digit % 2 == 0 && digit > maxval) maxval = digit ; 
        n = n / 10 ; 
    } 
    return maxval ; 
} 

int main () { 
    int n ; 
    cin >> n ; 
    cout << max_digit(n) ; 
    return 0 ; 
}
        
