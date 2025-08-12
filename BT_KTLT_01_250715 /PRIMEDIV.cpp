#include<bits/stdc++.h>

using namespace std;

int main(){
    freopen("PRIMEDIV.INP", "r", stdin); 
    freopen("PRIMEDIV.OUT", "w", stdout); 
    
    long long n; 
    cin >> n; 
    
    set <long long> v; 
    
    for (long long i = 1; i * i <= n; ++i) { 
        if ( n % i == 0 ) {
            v.insert(i);
            while ( n % i == 0 ) 
                n /= i;
        }
    }
    
    if ( n > 1 ) v.insert(n);
    
    for (const long long& i : v) 
        cout << i << endl;
        
    return 0;
}
