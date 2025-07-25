#include<bits/stdc++.h>

using namespace std;

long long tienve ( long long n, long long k, long long p1, long long p2 ) { 
    if ( k == 0) return n * p1 ; 
    long long le = n * p1 ; 
    long long si = ((n + k - 1) / k ) * p2 ; 
    long long si_le = ( n / k ) * p2 + ( n % k ) * p1 ; 
    return min ({si_le, le, si }) ;     
}

int main() {
    freopen ("TICKETS.INP" , "r", stdin) ; 
    freopen ("TICKETS.OUT" , "w", stdout) ;
    long long n, k, p1, p2 ;
    cin >> n >> k >> p1 >> p2 ; 
    long long so_tien_toi_thieu = tienve ( n, k, p1, p2 ) ;
    cout << so_tien_toi_thieu; 
    return 0;
}
