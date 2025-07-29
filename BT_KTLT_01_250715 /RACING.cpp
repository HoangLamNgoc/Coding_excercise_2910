#include<bits/stdc++.h>

using namespace std;

double thoigian (int x, int t, int v) { 
    int s = t * v ;
    int n = t * 2 ; 
    int chu_ky = x / s ; 
    int du = x - chu_ky * s ; 
    double ket_qua = chu_ky * n + (double)du / v ; 
    if ( du == 0 ) ket_qua = chu_ky * n - t ;
    return ket_qua; 
}

int main(){
    freopen ( "RACING.INP", "r", stdin ); 
    freopen ( "RACING.OUT", "w", stdout ); 
    
    int t1, v1, t2, v2, x;
    cin >> t1 >> v1 >> t2 >> v2 >> x; 
    
    double x1 = thoigian (x, t1, v1) ; 
    double x2 = thoigian (x, t2, v2) ; 
    
    if ( x1 > x2 ) cout << "First" ; 
    else if ( x1 == x2) cout << "Draw" ; 
    else cout << "Second"; 
    return 0;
}
