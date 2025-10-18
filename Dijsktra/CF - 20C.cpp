#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std; 
const int N = 1e5 + 5;
const long long INF = 1e18; 

vector<pair<int,int>> g[N];
priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> q; 
long long dist[N];
int trace[N]; 

void dij(int s) {
    fill_n(dist, N, INF); 
    fill_n(trace, N, 0); 
    dist[s] = 0; 
    trace[s] = -1; 
    q.push({0, s});

    while(!q.empty()) {
        pair<long long,int> r = q.top(); q.pop(); 
        int u = r.second; 
        long long du = r.first; 

        if(du != dist[u]) continue; 
        for(pair<long long,int> i : g[u]) {
            long long v = i.first; 
            int w = i.second; 
            if(dist[v] > dist[u] + w) {
                trace[v] = u; 
                dist[v] = dist[u] + w;  
                q.push({dist[v], v});
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    while(m--) {
        int u, v, w; 
        cin >> u >> v >> w; 
        g[u].push_back({v, w}); 
    }

    dij(1); 
    vector<long long> path; 
    for(int v = n; v != -1; v = trace[v]) 
        path.push_back(v); 
    reverse(path.begin(), path.end()); 
    for(const long long& i : path) cout << i << ' '; 
    return 0; 
}
