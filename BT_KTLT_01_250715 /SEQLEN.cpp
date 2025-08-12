#include <iostream> 

using namespace std; 

int main() { 
    freopen ("SEQLEN.INP", "r", stdin); 
    freopen ("SEQLEN.OUT", "w", stdout); 
    
    long long n; 
    cin >> n; 
    
    long long dem = 1;
    long long cntdigit = 0 ; 
    long long copy_n = n; 
    
    while ( copy_n > 0 ) { 
        copy_n /= 10; 
        dem *= 10;  
        cntdigit++; 
    }
    
    dem /= 10; 
    long long cnt = 0; 
    long long i = 1; 
    
    for ( long long digit = 1; digit < cntdigit; ++digit) {
            cnt += 9 * i * digit; 
            i *= 10; 
    }
    
    cnt += ( n - dem + 1 ) * cntdigit; 
    
    cout << cnt << endl; 
    return 0; 
}
