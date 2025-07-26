#include<bits/stdc++.h>

using namespace std;

long long divisor (long long n, int k) {
    vector<long long> uoc; 
    for ( long long i = 1 ; i * i <= n ; ++i ) {
        if (n % i == 0 ) {
            uoc.push_back(i); 
            if ( i != n / i ) uoc.push_back(n / i); 
        }
    }
    sort (uoc.begin(), uoc.end()); 
    if ( k <= uoc.size()) return uoc[k - 1];
    return -1 ; 
}

int main(){
    freopen ( "KTHDIV.INP", "r", stdin ) ;
    freopen ( "KTHDIV.OUT", "w", stdout ) ;
    long long n , k ; 
    cin >> n >> k ; 
    cout << divisor(n, k) ; 
    return 0;
}
