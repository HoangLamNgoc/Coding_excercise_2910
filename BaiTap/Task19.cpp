# include <bits/stdc++.h> 

using namespace std ; 

int main () {
    int n , dem = 0 ; 
    cin >> n ; 
    for ( int i = 1 ; i * i <= n ; ++i) {
       if ( n % i == 0 ) { 
           if ( i == n / i ) dem = dem + 1 ; 
           if ( i != n / i ) dem = dem + 2 ;
       }
    } 
    cout << dem ; 
    return 0 ; 
}
