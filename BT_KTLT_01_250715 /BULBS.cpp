#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen ( "BULBS.inp", "r", stdin ) ;
    freopen ( "BULBS.out", "w", stdout ) ;
    int n , uoc = 0 ;
    cin >> n ;
    for ( int i = 1 ; i * i <= n ; ++i ) {
        if( n % i == 0 && n / i != i ) uoc = uoc + 2 ;
        else if ( n % i == 0 && n / i == i) uoc = uoc + 1 ;
    }
    if ( uoc % 2 == 0 ) cout << "OFF" ;
    else cout << "ON" ;
    return 0;
}
