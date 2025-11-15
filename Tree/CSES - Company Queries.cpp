#include <iostream>
#include <vector>
 
using namespace std; 
const int log = 20; 
const int N = 2e5; 
 
int up[N][log];
vector<int> g[N];
 
int jump(int u, int k) {
    for(int i = 0; (1 << i) <= k; ++i) {
        if (k & (1 << i)) {
            u = up[u][i];
            if (u == 0) return -1;
        }  
    }
    return u; 
}
 
int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0); 
    
    int n, q; cin >> n >> q; 
 
    for(int i = 2; i <= n; ++i) {
        int v; 
        cin >> v;
        up[i][0] = v; 
        g[v].push_back(i);
    }
 
    up[1][0] = 0; 
    for(int j = 1; j < log; ++j) 
        for(int u = 1; u <= n; ++u) 
            up[u][j] = up[up[u][j - 1]][j - 1];
 
    while(q--) {
        int u, k; 
        cin >> u >> k; 
 
        cout << jump(u, k) << '\n'; 
    }
}
