#include <iostream> 
#include <algorithm> 

using namespace std; 

long long Conseq(long long w, long long m, long long k) {
    long long result = 1; 
    
    for ( long long i = m; i <= 1e16 ; ++i) {
        long long dem = 0; 
        long long cnt = 0;

        long long j = i;
        while ( j > 0) { 
            j /= 10; 
            dem++; 
        }
        
        cnt += dem * k ; 
        if ( cnt > w ) 
            return result; 
            
        else if ( cnt == w ) 
            return result + 1;
            
        else 
            result++; 
    }
    return result; 
}


int main() {
    freopen ("CONSEQ.INP", "r", stdin); 
    freopen ("CONSEQ.OUT", "w", stdout);
    long long w, m, k; 
    cin >> w >> m >> k; 
    long long res = Conseq ( w, m, k); 
    cout << res << endl; 
}
