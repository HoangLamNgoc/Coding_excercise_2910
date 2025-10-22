#include <iostream>
#include <algorithm>

using namespace std;
const int N = 1e5; 

int sz[N + 1], parent[N + 1], val[N + 1], delta[N + 1]; 

void make_set(int p) {
    parent[p] = p; 
    sz[p] = 1;   
    val[p] = 0; 
    delta[p] = 0; 
}

int find_set(int v) {
    if(parent[v] == v) return v; 
    int p = find_set(parent[v]);
    delta[v] += delta[parent[v]];
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
    delta[b] = val[b] - val[a]; 
}

void add(int x, int v) {
    int a = find_set(x); 
    val[a] += v;  
}

int get(int u) {
    return val[find_set(u)] + delta[u]; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; 
    cin >> n >> m; 
    string s; 
    int u, v; 

    for(int i = 1; i <= n; ++i) make_set(i); 
    while(m--) {
        cin >> s;    
        if(s == "join") {
            cin >> u >> v;
            merge(u, v);
        }

        if(s == "add") {
            cin >> u >> v; 
            add(u, v);  
        }

        if(s == "get") {
            cin >> u; 
            cout << get(u)<< '\n'; 
        }
    }
}

/* 
Hướng tư duy : 
- val[a] là cách bất khả thi 
=> tính từng node riêng lẻ hoặc tách làm 2 tập hợp 
=> delta và val 
*/
