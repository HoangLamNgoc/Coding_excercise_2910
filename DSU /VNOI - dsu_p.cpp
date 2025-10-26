#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;
const int maxn = 2e5 + 5; 
const int maxq = 2e5 + 5; 

struct edge {
    int u, v; 
    edge() {}; 
    edge(int a, int b) : u(a), v(b) {}; 
};

struct Node {
    int node, old_sz; 
    bool pc; 

    Node() {}; 
    Node(int n, int os, bool _pc) : node(n), old_sz(os), pc(_pc) {}; 
}; 

stack<Node> rollback;
vector<int> root(maxn), sz(maxn); 
vector<int> setpoint; 

void init(int n) {
    for(int i = 1; i <= n; ++i) {
        sz[i] = 1; 
        root[i] = i; 
    }
}

int rt(int v) {
    if ( v == root[v]) return v; 
    return root[v] = rt(root[v]); 
}

int cur_comp; 
void merge(int u, int v) {
    u = rt(u); 
    v = rt(v); 

    if(u == v) return; 

    if(sz[u] < sz[v]) swap(u,v); 

    rollback.push(Node(u, sz[u], 1)); 
    rollback.push(Node(v, sz[v], 0)); 
    root[v] = u; 
    sz[u] += sz[v]; 
    --cur_comp; 
}

void get_ans() { 
    int v = setpoint.back();
    setpoint.pop_back();

    while(rollback.size() > v) {
        int a = rollback.top().node;
        int b = rollback.top().old_sz; 
        bool f = rollback.top().pc; 
        rollback.pop(); 

        if(!f) {
            root[a] = a;  
        }

        sz[a] = b;
        if (f == 0) ++cur_comp; 
    } 
}

int main() {
    int n, q; 
    cin >> n >> q; 

    init(n); 

    string t; int u, v; 
    cur_comp = n; 
    for(int i = 1; i <= q; ++i) {
        cin >> t; 
        if(t == "persist") {
            setpoint.emplace_back(rollback.size()); 
        }

        else if ( t == "union") {
            cin >> u >> v; 
            merge(u, v); 
            cout << cur_comp << '\n'; 
        }

        else { 
            get_ans(); 
            cout << cur_comp << '\n'; 
        }
    }
}
