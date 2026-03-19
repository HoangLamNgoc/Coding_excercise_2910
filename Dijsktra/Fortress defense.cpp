//https://www.marisaoj.com/problem/646

#include <bits/stdc++.h>

using namespace std; 
const int N = 2e5 + 5;
const long long INF = 1e18;

#define int long long 

struct edge {
    long long to, w, id; 
};

vector<edge> adj[N];
int n, m; 

void dijkstra(int s, vector<long long>& dist) {
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;
    fill(dist.begin(), dist.end(), INF);
    dist[s] = 0;
    q.push({0, s});

    while (!q.empty()) {
        pair<long long,int> r = q.top();
        q.pop();

        long long du = r.first; 
        int u = r.second; 
        if (du != dist[u]) continue;

        for (auto [v, w, i] : adj[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                q.push({dist[v], v});
            }
        }
    } 
}

vector<edge> edges; 

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 

    cin >> n >> m;

    edges.resize(m + 1); 

    for(int i = 1; i <= m; ++i) {
        int u, v, w; 
        cin >> u >> v >> w; 

        adj[u].push_back({v, w, i}); 
        adj[v].push_back({u, w, i}); 

        edges[i] = {u, v, w}; 
    }

    vector<long long> d1(n + 1, 0); 
    vector<long long> dn(n + 1, 0); 

    dijkstra(1, d1); 
    dijkstra(n, dn); 

    long long ori = d1[n]; 
    vector<bool> in(m + 1, 0); 
    vector<int> p_nodes;
    vector<int> p_edges; 
    int curr = 1;
 
    bool found = 0; 
    while (curr != n) {
        found = 0; 
        p_nodes.push_back(curr);

        for(auto [v, w, id] : adj[curr]) {
            if (dn[v] + d1[curr] + w == ori) { 
                p_edges.push_back(id);  
                in[id] = 1; 

                curr = v;
                found = 1;  
                break;  
            }
        }
        if (!found) break; 
    }
    p_nodes.push_back(n);

    int k = p_nodes.size(); 

    vector<int> pos(n + 1, 0); 
    for(int i = 0; i < k; ++i) pos[p_nodes[i]] = i + 1; 

    vector<pair<long long, int>> order; 
    for(int i = 1; i <= n; ++i) order.push_back({d1[i], i}); 
    sort(order.begin(), order.end());

    vector<int> L(n + 1, 0);  

    for(auto [di, i] : order) {
        if (pos[i]) 
            L[i] = pos[i]; 
        else 
            for(auto [v, w, id] : adj[i]) 
                if (d1[v] + w == d1[i] ) L[i] = max(L[i], L[v]);
    }

    vector<int> R(n + 1, k + 1);   

    order.clear(); 
    for(int i = 1; i <= n; ++i) order.push_back({dn[i], i});
    sort(order.begin(), order.end());

    for(auto [di, i] : order) {
        if (pos[i]) 
            R[i] = pos[i]; 
        else 
            for(auto [v, w, id] : adj[i]) 
                if (dn[v] + w == dn[i]) 
                    R[i] = min(R[i], R[v]); 

    }

    vector<vector<long long>> add(k + 1), rem(k + 1);

    for(int i = 1; i <= m; ++i) {
        if (in[i]) continue; 

        long long u = edges[i].to;
        long long v = edges[i].w; 
        long long w = edges[i].id; 

        long long cost1 = d1[u] + w + dn[v]; 
        if (L[u] > 0 && R[v] <= k && L[u] < R[v]) {
            add[L[u]].push_back(cost1); 
            rem[R[v]].push_back(cost1); 
        }

        long long cost2 = d1[v] + w + dn[u]; 
        if (L[v] > 0 && R[u] <= k && L[v] < R[u]) {
            add[L[v]].push_back(cost2); 
            rem[R[u]].push_back(cost2); 
        }
    }

    multiset<long long> ms; 
    vector<long long> new_d(m + 1, ori);
    for(int i = 1; i < k; ++i) {
        for(long long c : rem[i]) ms.erase(ms.find(c));
        for(long long c : add[i]) ms.insert(c);
        if (!ms.empty()) new_d[p_edges[i - 1]] = *ms.begin();  
    }

    long long mx = -1;
    int cnt = 0; 
    for(int i = 1; i <= m; ++i) {
        long long d = (in[i] ? new_d[i] : ori); 
        if (d > mx) {
            mx = d; 
            cnt = 1; 
        }
        else if (d == mx) ++cnt; 
    }
    cout << mx << ' ' << cnt; 
}
