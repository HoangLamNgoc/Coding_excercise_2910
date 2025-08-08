#include<bits/stdc++.h>

using namespace std;

bool isPrime( long long n) { 
    if ( n < 2 ) return false; 
    for ( long long i = 2; i * i <= n; ++i) {
        if ( n % i == 0 ) return false;
    }
    return true; 
}

int main(){
    freopen("PRIMEDIV.INP", "r", stdin); 
    freopen("PRIMEDIV.OUT", "w", stdout); 
    
    long long n; 
    cin >> n; 
    
    set <long long> v; 
    
    for (long long i = 1; i * i <= n; ++i) { 
        if ( isPrime(i) && n % i == 0 ) {
            v.insert(i);
        
            long long j = n / i; 
            if ( i != j && isPrime(j)) 
                v.insert(j); 
            while ( n % i == 0 ) 
                n /= i;
        }
    }
    
    if ( n > 1 ) v.insert(n);
    
    for (const long long& i : v) 
        cout << i << endl;
        
    return 0;
}
