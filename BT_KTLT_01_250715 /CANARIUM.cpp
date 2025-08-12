#include <iostream> 
#include <cmath>

using namespace std; 


void Sol(long long k) { 
    long long m = -1, n = -1; 
    long long tong = k * 4 - 1; 
    bool kiem = false; 
    
    if ( tong <= 1) kiem = true; 
    
    for ( long long m1 = sqrt(tong); m1 >= 3 && !kiem; --m1) { 
        if (tong % m1 == 0) {
            long long n1 = tong / m1;  
            if (m1 % 2 == 1 && n1 % 2 == 1) { 
                m = ( m1 - 1 ) / 2; 
                n = ( n1 - 1 ) / 2;
                kiem = true;
            }
        }
    }
    cout << m << " " << n << endl;
}


int main () { 
    freopen ("CANARIUM.INP", "r", stdin); 
    freopen ("CANARIUM.OUT", "w", stdout);
    
    long long k; 
    while ( cin >> k ) {
        Sol(k);
    }
    return 0; 
}
