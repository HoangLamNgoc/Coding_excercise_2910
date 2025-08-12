#include <iostream> 

using namespace std; 

long long fold(long long i, long long j) { 
    long long cnt = 0; 
    
    if ( j > i ) return -1;  
    if ( i == j) return 0; 
    while ( i > j ) {
        i = (i + 1) / 2; 
        cnt++; 
    } 
    
    return cnt; 
} 
    
int main() { 
    freopen ( "FOLDING.INP", "r", stdin);
    freopen ( "FOLDING.OUT", "w", stdout); 
    
    long long W, H, w, h; 
    cin >> W >> H >> w >> h; 
    
    long long res = 1e9; 

    long long a1 = fold(W, w), b1 = fold(H, h);
    if (a1 != -1 && b1 != -1) res = min(res, a1 + b1);

    long long a2 = fold(W, h) , b2 = fold(H, w);
    if (a2 != -1 && b2 != -1) res = min(res, a2 + b2);

    if (res == 1e9) cout << -1;
    else cout << res;

    return 0;
}
