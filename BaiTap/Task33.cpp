# include <bits/stdc++.h> 

using namespace std ; 

int min_digit(int n) {
    int minval = 10 , current_pos = -1 , count = 0 ; 
    while ( n > 0 ) {
        int digit = n % 10 ;
        current_pos = curent_pos + 1 ;
        if ( digit != 0 && digit < minval) {
            minval = digit ; 
            count = current_pos ; 
        }
        else if ( digit !=0 && digit == minval ) 
            if ( count > current_pos ) count = current_pos ;     
        n = n / 10 ; 
    } 
    return count ; 
} 

int main () { 
    int n ; 
    cin >> n ; 
    cout << min_digit(n) ; 
    return 0 ; 
}
        
