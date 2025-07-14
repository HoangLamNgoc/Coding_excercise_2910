#include <bits/stdc++.h>

using namespace std; 

bool isPrime ( int n ) {
    if ( n < 2 ) return false ; 
    for ( int i = 2 ; i * i <= n ; ++i ) 
        if ( n % i == 0 ) return false ; 
    return true ; 
} 

vector <int> PrimeFactors(int n) { 
    vector <int> Factors ; 
    for ( int i = 2 ; i * i <= n ; ++i ) { 
        while ( n % i == 0 ) {
            if (isPrime(i)) Factors.push_back(i) ; 
            n = n / i ; 
        }
    }
    if ( n > 1 ) Factors.push_back(n) ; 
    return Factors; 
}
int main () {
    int num ; 
    cin >> num ; 
    vector <int> Factors = PrimeFactors(num) ; 
    for ( int x : Factors ) cout << x << " " ; 
    return 0 ; 
}
