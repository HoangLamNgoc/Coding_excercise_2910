#include <iostream>

using namespace std;

int main(){
    freopen("BRVY.INP", "r", stdin); 
    freopen("BRVY.OUT", "w", stdout); 
    
    long long x, dx, d, dd, t, dt, v, dv ; 
    cin >> x >> dx >> d >> dd >> t >> dt >> v >> dv; 
    
    long long x1 = 0 ,d1 = 0, t1 = 0 , v1 = 0, s = 0; 
    
    for (long long i = x; i > 0 ; --i ) { 
        long long cdai = i * dx; 
        if ( cdai % dt != 0) continue; 
        
        long long t2 = cdai / dt; 
        if ( t2 > t ) continue; 
        
        for ( long long j = d; j > 0; --j ) { 
            long long crong = j * dd; 
            if ( crong % dv != 0) continue; 
            
            long long v2 = crong / dv; 
            if ( v2 > v ) continue; 
            
            long long maxval = crong * cdai; 
            if ( maxval > s) { 
                s = maxval; 
                x1 = i; 
                d1 = j;
                t1 = t2; 
                v1 = v2; 
            }
        }
    }
    
    cout << s << endl << x1 << " " << d1 << " " << t1 << " " << v1 << endl; 
    return 0;
}
