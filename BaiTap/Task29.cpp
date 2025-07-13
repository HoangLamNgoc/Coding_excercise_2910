# include <bits/stdc++.h> 

using namespace std ; 

int min_digit(int n) {
    int minval = 10 ; 
    while ( n > 0 ) {
        int digit = n % 10 ; 
        if ( digit < minval && digit != 0 ) minval = digit ; 
        n = n / 10 ; 
    } 
    if ( minval == 10 ) return -1 ; 
    else return minval ; 
} 

int main () { 
    int n ; 
    cin >> n ; 
    cout << min_digit(n) ; 
    return 0 ; 
}
        
    
