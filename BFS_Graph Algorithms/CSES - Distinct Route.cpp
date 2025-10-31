#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int N = 505;
vector<int> g[N];
int par[N];
bool vis[N];

int main() {
    int n, m; 
    cin >> n >> m;
    while(m--){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }

    vector<vector<int>> paths;
    while(true){
        fill(par, par+N, -1);
        fill(vis, vis+N, 0);

        queue<int> q;
        q.push(1);
        vis[1] = true;
        bool found = false;

        while(!q.empty() && !found){
            int u = q.front(); q.pop();
            for(int v : g[u]){
                if(!vis[v]){
                    vis[v] = true;
                    par[v] = u;
                    q.push(v);
                    if(v == n){
                        found = true;
                        break;
                    }
                }
            }
        }

        if(!found) break;
        
        vector<int> path;
        for(int cur = n; cur != -1; cur = par[cur]) path.push_back(cur);
        reverse(path.begin(), path.end());
        paths.emplace_back(path);

        for(int i = 0; i + 1 < path.size(); ++i){
            int u = path[i], v = path[i + 1];
            auto it = find(g[u].begin(), g[u].end(), v);
            if(it != g[u].end()) g[u].erase(it);
        }
    }

    cout << paths.size() << '\n';
    for(auto &p : paths){
        cout << p.size() << '\n';
        for(int v : p) cout << v << ' ';
        cout << '\n';
    }
}
