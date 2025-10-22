#include <iostream>
#include <algorithm>

using namespace std;
const int N = 1e5; 

int sz[N + 1], parent[N + 1]; 

void make_set(int p) {
    parent[p] = p; 
    sz[p] = 1;     
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
}

int main() {
    int n, m; 
    cin >> n >> m; 
    string s; 
    int u, v; 

    while(m--) {
        cin >> s; 
        cin >> u >> v;
        if(parent[u] == 0) make_set(u); 
        if(parent[v] == 0) make_set(v);  

        if(s == "union")  
            merge(u, v);

        if(s == "get") {
            if(find_set(u) == find_set(v)) cout << "YES" << '\n'; 
            else cout << "NO" << "\n"; 
        }
    }
}
