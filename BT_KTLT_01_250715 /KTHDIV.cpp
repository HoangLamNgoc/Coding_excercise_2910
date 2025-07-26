#include<bits/stdc++.h>

using namespace std;

int divisor (int n, int k) {
    int dem = 0 ; 
    for ( int i = 1 ; i <= n ; ++i ) {
        if (n % i == 0 ) { 
            dem++; 
            if ( dem == k ) return i ;
        }
    }
    return -1 ; 
}

int main(){
    freopen ( "KTHDIV.INP", "r", stdin ) ;
    freopen ( "KTHDIV.OUT", "w", stdout ) ;
    int n , k ; 
    cin >> n >> k ; 
    cout << divisor(n, k) ; 
    return 0;
}
