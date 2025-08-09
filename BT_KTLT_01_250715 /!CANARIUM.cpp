#include <iostream> 
#include <algorithm> 

using namespace std; 


void Sol(long long k) { 
    long long m = -1, n = -1; 

    for ( long long n1 = k / 2; n1 >= 2; --n1 ) { 
        for ( long long i = n1 - 1; i >= 1; --i ) { 
             long long k1 = i * n + (i + n + 1 ) / 2  ; 
            if ( k == k1) { 
                m = i; 
                n = n1;
                break; 
            }
        }
    }
    cout << m << ' ' << n << endl;
}


int main () { 
    freopen ("CANARIUM.INP", "r", stdin); 
    freopen ("CANARIUM.OUT", "w", stdout);
    
    long long k; 
    while ( cin >> k) { 
        Sol (k); 
    }
    return 0; 
}
