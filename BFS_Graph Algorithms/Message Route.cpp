#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
 
using namespace std;
int n, m;
const int N = 1e5 * 2;
bool visit[N];
int par[N];
vector<int> g[N];
int d[N];
 
void bfs(int s) {
    fill_n(visit, N, false);
    fill_n(par, N, 0);
    fill_n(d, N, 0);
    par[s] = -1;
    d[s] = 1;
 
    visit[s] = true;
    queue<int> q;
    q.push(s);
    while(!q.empty()) {
        auto u = q.front();
        q.pop();
        for (auto v : g[u]) {
            if(!visit[v]) {
                par[v] = u;
                visit[v] = true;
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }
}
 
int main() {
    cin >> n >> m;
 
    while (m--) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
 
    bfs(1);
    if(!visit[n]) cout << "IMPOSSIBLE";
    else {
        vector<int> path;
        for (int v = n; v != -1; v = par[v])
            path.push_back(v);
        reverse(path.begin(), path.end());
        cout << d[n] << endl;
        for( int& i : path) cout << i << " ";
    }
    return 0;
}
