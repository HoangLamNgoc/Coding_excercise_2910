#include <iostream>
#include <algorithm>

using namespace std;
const int N = 3 * 1e5; 

int sz[N + 1], parent[N + 1], mx[N + 1], mn[N + 1]; 

void make_set(int p) {
    parent[p] = p; 
    sz[p] = 1;     
    mn[p] = p;
    mx[p] = p; 
}

int find_set(int v) {
    if(parent[v] == v) return v; 
    int p = find_set(parent[v]);
    parent[v] = p; 
    return p;  
}

void merge(int u, int v) {
    int a = find_set(u); 
    int b = find_set(v); 

    if(a == b) return; 

    if(sz[a] < sz[b]) swap(a, b); 
    sz[a] += sz[b]; 
    parent[b] = a;  
    mx[a] = max(mx[a], mx[b]);  
    mn[a] = min(mn[a], mn[b]); 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m; 
    cin >> n >> m; 
    string s; 
    int u, v; 

    while(m--) {
        cin >> s;    
        if(s == "union") {
            cin >> u >> v;
            if(parent[u] == 0) make_set(u); 
            if(parent[v] == 0) make_set(v);
            merge(u, v);
        }

        if(s == "get") {
            cin >> u; 
            if(parent[u] == 0) make_set(u); 
            u = find_set(u); 
            cout << mn[u] << ' ' << mx[u] << ' ' << sz[u] << '\n'; 
        }
    }
}
