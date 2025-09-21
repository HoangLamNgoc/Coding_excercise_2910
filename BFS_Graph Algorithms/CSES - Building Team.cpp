#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int n, m;
const int N = 1e5 * 2;
bool visit[N];
vector<int> g[N];

void bfs(int s) {
    visit[s] = true;
    queue<int> q;
    q.push(s);
    while(!q.empty()) {
        auto u = q.front();
        q.pop();
        for (auto v : g[u]) {
            if(!visit[v]) {
                visit[v] = true;
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

    fill_n(visit, N, false);
    bfs(1);
    int j = 1;
    long long cnt = 0;

    vector<pair<int,int>> path;
    for(int i = 2; i <= n; ++i) {
        if (!visit[i]) {
            ++cnt;
            path.push_back({j, i});
            j = i;
            bfs(i);
        }
    }
    cout << cnt << endl;
    if (cnt != 0 ) for(auto [v, u] : path) cout << v << " " << u << endl;
    return 0;
}
