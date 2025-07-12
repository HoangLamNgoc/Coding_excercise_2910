# include <bits/stdc++.h> 

using namespace std ; 

int main () {
    int n , tong = 0 ; 
    cin >> n ; 
    for ( int i = 1 ; i * i <= n ; ++i) {
       if ( n % i == 0 ) { 
           if ( i == n / i ) tong = tong + i ; 
           if ( i != n / i ) tong = tong + n / i + i ;
       }
    } 
    cout << tong ; 
    return 0 ; 
}
