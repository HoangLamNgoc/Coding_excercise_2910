#include<bits/stdc++.h>

using namespace std;

long long So_ngay_xau (int k, long long n) {
    int dem = 0; 
    for ( int i = 1; i <= n ; ++i ) {
        int thu = (k + 12) % 7; 
        if (thu == 5) return (( n - i) / 7 + 1); 
        k = (k + 30) % 7;
    }
    return dem ; 
}
int main() {
    freopen ( "FRIDAY.INP", "r" , stdin ); 
    freopen ( "FRIDAY.OUT", "w" , stdout ); 
    long long n; 
    int k ; 
    cin >> n >> k ; 
    cout << So_ngay_xau(k, n); 
    return 0;
}
