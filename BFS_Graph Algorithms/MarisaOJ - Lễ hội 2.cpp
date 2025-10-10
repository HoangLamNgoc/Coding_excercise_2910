#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;
const int maxn = 3e3 + 1;  
vector<int> g[maxn]; 
int d[maxn][maxn]; 

void bfs(int s,int i) {
	bool vis[maxn]; 
	fill_n(vis, maxn, 0);
	d[i][s] = 0; 
	
	vis[s] = true; 
	queue<int> q;
	q.push(s); 
	
	while(!q.empty()) {
		int u = q.front(); q.pop();
		for(int v : g[u]) {
			if (!vis[v]) {
                vis[v] = true; 
                d[i][v] = d[i][u] + 1; 
                q.push(v);
            }
        }
    }
}

int main() {
    int n, k, m; 
    cin >> n >> m >> k; 
    int res = 2e9;

    int a[maxn]; 
    int m1 = m; 
    for(int i = 0; i < k; ++i) {
        cin >> a[i]; 
    }
    pair<int,int> p[maxn]; 
    for(int i = 0; i < m; ++i) {
        int u, v; 
        cin >> u >> v; 

        g[u].push_back(v);
        g[v].push_back(u);
        p[i] = make_pair(u, v);  
    }

    for(int i = 0; i < k; ++i) {
        bfs(a[i], i); 
    }

    for(int i1 = 0; i1 < m1; ++i1) {
        int ans = 0;
        auto [u, v] = p[i1];
        for(int i = 0; i < k; ++i) {
            ans += min(d[i][v], d[i][u]); 
        }
        res = min(res, ans); 
    }
    cout << res << endl;
    return 0;
}
