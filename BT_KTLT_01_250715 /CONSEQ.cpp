#include <iostream>

using namespace std;

long long Conseq(long long w, long long m, long long k) { 
    long long dem = 0; 
    long long cnt = 1; 
    
    long long copy_m = m;
    while (copy_m > 0) {
        dem++;
        cnt *= 10; 
        copy_m /= 10;
    }

    
    long long tong = 0;
    long long s = 0; 
    
    while ( w > 0) { 
        long long y = w / k / dem ; 
        if ( y <= cnt - m ) { 
            tong += y; 
            break; 
        } 
        
        else { 
            s = cnt - m; 
            tong += cnt - m; 
            w = w - s * k * dem; 
        } 
        
        m = cnt; 
        cnt *= 10; 
        ++dem; 
    }
    return tong; 
} 

    
int main(){
    freopen("CONSEQ.INP", "r", stdin); 
    freopen("CONSEQ.OUT", "w", stdout); 
    
    long long w, m, k; 
    cin >> w >> m >> k; 
    
    cout << Conseq(w, m, k) << endl; 
    return 0;
}
