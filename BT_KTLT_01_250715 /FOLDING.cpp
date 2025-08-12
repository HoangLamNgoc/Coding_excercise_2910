#include <iostream> 

using namespace std; 

long long fold(long long i, long long j) { 
    long long cnt = 0; 
    bool flag = true;
    
    if ( j > i ) flag = false; 
    
    while ( i > 2 * j && flag) {
        i /= 2; 
        cnt++; 
    } 
    if (!flag) return cnt = 0; 
    else return cnt + 1; 
} 
    
int main() { 
    freopen ( "FOLDING.INP", "r", stdin);
    freopen ( "FOLDING.OUT", "w", stdout); 
    
    long long W, H, w, h; 
    cin >> W >> H >> w >> h; 
    
    long long cnt = fold(W, w); 
    long long dem = fold(H,h); 
    
    if ( cnt == 0 || dem == 0)  
        cout << -1; 
    else 
        cout << cnt + dem << endl;
    return 0; 
}
