#include <bits/stdc++.h> 

using namespace std;
struct edge {
    int u, v; 
    
    edge() {}; 
    edge(int a, int b) : u(a), v(b) {}; 
}; 

struct DSU {
    vector<int> root, d; 

    void init(int n) {
        root.resize(n + 5);  
        d.resize(n + 5); 

        for(int i = 1; i <= n; ++i) {
            root[i] = i;
            d[i] = 0; 
        }
    }

    int rt(int v) {
        if ( v == root[v]) return v; 

        int p = rt(root[v]); 
        d[v] += d[root[v]];
        return root[v] = p;   
    }

    void merge(int a, int b) {
        root[a] = b; 
        d[a] = 1;  
    }
} dsu; 

int main() {
    int n, q; 
    cin >> n >> q; 
    
    dsu.init(n); 
    int t, a, b; 
    while(q--) {
        cin >> t >> a;

        if ( t == 1) {
            cin >> b; 
            dsu.merge(a, b); 
        } 

        else {
            dsu.rt(a);
            cout << dsu.d[a] << '\n'; 
        }
    }
}
