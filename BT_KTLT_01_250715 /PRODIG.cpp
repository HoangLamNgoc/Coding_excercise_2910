#include <iostream>
#include <vector> 
#include <algorithm>

using namespace std;

int main() { 
    freopen ("PRODIG.INP", "r", stdin); 
    freopen ("PRODIG.OUT", "w", stdout); 
    
    long long n; 
    cin >> n; 
    
    long long d = 9; 
    vector<int> s; 
    
    if ( n == 0 ) cout << 10; 
    
    else if ( n <= 9 ) cout << n; 
    
    else {
        while ( n > 1 && d > 1) {
            if ( n % d == 0 ) { 
                n /= d; 
                s.push_back(d); 
            }
        
            else 
                d--; 
        }
    
        if ( n != 1 ) cout << -1 ; 
        else {
            sort(s.begin(), s.end()); 
            for ( int a : s ) 
                cout << a; 
        }
    }
    
    return 0; 
}
