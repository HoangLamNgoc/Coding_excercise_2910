#include <iostream>
#include <vector>
#include <queue>

using namespace std; 
const int log = 20; 
const int N = 2e5 + 5; 

int up[N][log];
vector<int> g[N];
int h[N];
bool vis[N]; 

void bfs(int s) {
    fill_n(vis, N, 0); 
    fill_n(h, N, N); 

    queue<int> q;    
    vis[s] = 1; 
    h[s] = 0;
    q.push(s);

    while(!q.empty()) {
        int u = q.front(); 
        q.pop(); 

        for(int v : g[u]) {
            if (!vis[v]) {
                vis[v] = 1; 
                h[v] = h[u] + 1; 
                up[v][0] = u; 
                q.push(v); 
            }
        }
    } 
}

int jump(int u, int v) {
    if (h[u] != h[v]) {
        if (h[u] < h[v]) swap(u, v); 
        int k = h[u] - h[v];
        for(int i = 0; (1 << i) <= k; ++i) {
            if (k & (1 << i)) {
                u = up[u][i];
                if (u == 0) return -1;
            }
        }  
    }
    if (u == v) return u;

    int k = (int)__lg(h[u]); 
    for (int j = k; j >= 0; --j)
        if (up[u][j] != up[v][j]) 
            u = up[u][j], v = up[v][j];
    return up[u][0]; 
}

int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0); 
    
    int n, q; cin >> n >> q; 

    for(int i = 2; i <= n; ++i) {
        int u, v; 
        cin >> u >> v;

        g[u].push_back(v); 
        g[v].push_back(u); 
    }
    bfs(1); 
    for(int j = 1; j < log; ++j) 
        for(int u = 1; u <= n; ++u) 
            up[u][j] = up[up[u][j - 1]][j - 1];

    while(q--) {
        int u, v; 
        cin >> u >> v; 

        cout << h[u] + h[v] - 2 * h[jump(u, v)] << '\n'; 
    }
}
