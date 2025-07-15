#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen ( "BULBS.inp", "r", stdin ) ;
    freopen ( "BULBS.out", "w", stdout ) ;
    int n ;
    cin >> n ;
    int sq = sqrt(n);
    if (sq * sq == n) cout << "ON";
    else cout << "OFF";
    return 0 ; 
}
