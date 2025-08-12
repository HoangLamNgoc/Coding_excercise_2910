#include <iostream> 

using namespace std; 

int main() { 
    freopen ("NUMPOS.INP", "r", stdin); 
    freopen ("NUMPOS.OUT", "w", stdout); 
    
    long long k; 
    cin >> k; 
    
    long long numpos = 0; 
    
    if ( k == 1 ) numpos = 1; 
    if ( k == 2 ) numpos = 2; 
    
    for ( long long i = 3; i <= k; ++i) 
        numpos += 3; 
    
    cout << numpos; 
    return 0; 
}
