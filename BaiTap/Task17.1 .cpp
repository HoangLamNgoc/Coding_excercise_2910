# include <bits/stdc++.h>

using namespace std ; 

bool isPrime ( int num ) {
    if ( num < 2 ) return false ;
    for ( int i = 2 ; i * i <= num ; ++i )
        if ( num % i == 0 ) return false ; 
    return true ; 
}

int main () {
    int n , dem = 0 ; 
    cin >> n ; 
    while ( n > 0 ) {
        if ( isPrime ( n % 10 )) dem = dem + 1 ; 
        n = n / 10 ; 
    }
    cout << dem ; 
    return 0 ; 
}
