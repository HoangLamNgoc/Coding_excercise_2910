# include <bits/stdc++.h> 

using namespace std ; 

int max_digit(int n) {
    int maxval = -1 , current_pos = -1 , count = 0 ; 
    while ( n > 0 ) {
        int digit = n % 10 ;
        current_pos = current_pos + 1 ;
        if ( digit > maxval) {
            maxval = digit ; 
            count = current_pos ; 
        }
        else if ( digit == maxval ) 
            if ( current_pos > count ) count = current_pos ;     
        n = n / 10 ; 
    } 
    return count ; 
} 

int main () { 
    int n ; 
    cin >> n ; 
    cout << max_digit(n) ; 
    return 0 ; 
}
        
