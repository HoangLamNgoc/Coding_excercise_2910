#include<bits/stdc++.h>

using namespace std;

vector<int> divisor (int n) {
    vector<int> Divisor ;
    for ( int i = 1 ; i <= n ; ++i ) {
        if (n % i == 0 ) Divisor.push_back(i) ; 
        if ( n % i == 0 && n / i == i ) Divisor.push_back(i) ; 
    }
    sort(Divisor.begin(), Divisor.end());
    return Divisor ; 
}

int main(){
    freopen ( "KTHDIV.INP", "r", stdin ) ;
    freopen ( "KTHDIV.OUT", "w", stdout ) ;
    int n , k ; 
    cin >> n >> k ; 
    vector<int> Divisor = divisor(n) ; 
    cout << Divisor[k-1] ; 
    return 0;
}
