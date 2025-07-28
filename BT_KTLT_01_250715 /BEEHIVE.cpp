#include<bits/stdc++.h>

using namespace std;

int main(){
    freopen ("BEEHIVE.INP", "r" , stdin); 
    freopen ("BEEHIVE.OUT", "w" , stdout); 
    long long n, dem = 1; 
    cin >> n; 
    for ( int i = 2; i <= n; ++i) dem += (( i - 1 ) * 6 ); 
    cout << dem << endl; 
    return 0;
}
