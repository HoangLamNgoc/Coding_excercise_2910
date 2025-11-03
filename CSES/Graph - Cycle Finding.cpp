#include <iostream>
#include <algorithm>
#include <vector>

using namespace std; 
const int N = (int)25e2 + 5; 
const int M = (int)5e3 + 5; 
const long long oo = (long long)2e16 + 1LL * 5; 
struct edge {
    int u, v, w; 

    edge() {}; 
    edge(int a, int b, int c) : u(a), v(b), w(c) {}; 
}; 

vector<edge> e;
vector<int> path; 
long long d[N]; 
int trace[N]; 
int n, m; 

void bellmanford() {
    fill_n(d, N, 0); 
    fill_n(trace, N, -1); 
 
    for(int i = 1; i < n; ++i) {
        for(edge E : e) {
            int u = E.u, v = E.v, w = E.w; 
            if (d[v] > d[u] + w) {
                d[v] = d[u] + w; 
                trace[v] = u; 
            }
        }
    }
}

bool NegCy() {
    int negst = -1; 

    for(edge E : e) {
        int u = E.u, v = E.v, w = E.w; 
        if (d[v] > d[u] + w) {
            trace[v] = u; 
            negst = v; 
            break;
        }
    }

    if (negst == -1) return 0; 
    
    int u = negst;
    for(int i = 0; i < n; ++i) u = trace[u]; 

    path.emplace_back(u); 
    for(int v = trace[u]; v != u; v = trace[v]) 
        path.emplace_back(v); 
    path.emplace_back(u); 
    reverse(path.begin(), path.end()); 
    return 1; 
}   

signed main() {
    cin >> n >> m; 

    for(int i = 1; i <= m; ++i) {
        int u, v, w; 
        cin >> u >> v >> w; 
        e.emplace_back(edge(u, v, w)); 
    }
    bellmanford(); 
    if (NegCy()) {
        cout << "YES" << '\n'; 
        for(const int& i : path) cout << i << ' '; 
    }
    else cout << "NO" << '\n'; 
}
