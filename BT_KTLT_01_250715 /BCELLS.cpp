#include<bits/stdc++.h>

using namespace std;

int main(){
    freopen("BCELLS.INP", "r" , stdin); 
    freopen("BCELLS.OUT", "w" , stdout);
    long long n, m, r, c; 
    cin >> n >> m >> r >> c; 
    long long tong = n * m; 
    long long so_o_den = tong / 2;
    if ((r + c) % 2 == 0 && tong % 2 != 0) 
        so_o_den += 1; 
    cout << so_o_den; 
    return 0;
}
