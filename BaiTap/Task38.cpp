#include <bits/stdc++.h>

using namespace std; 

set <long long> PrimeFactors(long long n) { 
    set <long long> Factors ; 
    for ( long long i = 2 ; i * i <= n ; ++i ) { 
        while ( n % i == 0 ) {
            Factors.insert(i) ; 
            n = n / i ; 
        }
    }
    if ( n > 1 ) Factors.insert(n) ; 
    return Factors; 
}
int main () {
    long long num ; 
    cin >> num ; 
    set <long long> Factors = PrimeFactors(num) ; 
    for ( long long x : Factors ) cout << x << " " ; 
    return 0 ; 
}
