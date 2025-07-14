# include <bits/stdc++.h>

using namespace std; 

int main () {
    long long n, dem_0 = 0 ; 
    cin >> n ; 
    for ( long long i = 5 ; n / i >= 1 ; i*= 5 ) 
        dem_0 = dem_0 + n / i ; 
    cout << dem_0 ; 
    return 0 ; 
}
