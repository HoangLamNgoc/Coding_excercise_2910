#include<bits/stdc++.h>

using namespace std;

void Sol ( long long k ) { 
    long long tong = k * 2; 
    long long minval = 1e12; 
    long long m = -1 , n = -1;
    
    for (long long i = 0; i <= ( k - 1 ) / 2; ++i) { 
        long long n1 = ( tong - 2 * i + 1) / ( 2 * ( i + 1));
        
        if ( abs(n1 - i) <= minval ) { 
            minval = abs(n1 - i) ; 
            if ( n1 > i) { 
                n = n1; 
                m = i;
            }
            
            else { 
                n = i;
                m = n1; 
            }
        }
    }
    
    cout << m << ' ' << n << endl;
    return;
}


int main(){
    freopen("CANARIUM.INP", "r", stdin); 
    freopen("CANARIUM.OUT", "w", stdout); 
    
    long long k; 
    
    while (cin >> k) 
        Sol(k); 
    
    return 0;
}
