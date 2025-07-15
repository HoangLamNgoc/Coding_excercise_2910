#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen ( "FLOWERS.inp", "r", stdin ) ;
    freopen ( "FLOWERS.out", "w", stdout ) ;
    int a , b , c , max_val = 0 ;
    cin >> a >> b >> c;
    for ( int y = 0 ; y <= c / b ; ++y ) {
        int x = ( c - b * y ) / a ;
        int tong = a * x + b * y ;
        max_val = max(max_val,tong) ;
    }
   cout << max_val ;
   return 0 ;
}
