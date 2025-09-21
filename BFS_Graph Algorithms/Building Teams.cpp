#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std; 
int n, m; 
const int N = 1e5; 
int visit[N];
vector<int> g[N]; 
bool found = false;

void bfs(int s) {
    visit[s] = 1;
    queue.push(s); 
    
    while(!q.empty) {
        int u = q.front();
        q.pop(); 
        for (auto v : g[u]) {
            if (visit[v] == 0) {
                visit[v] = (visit[u] == 1) ? 2 : 1;
                q.push[v];
            } 
            else if (visit[v] == visit[u]) {
              cout << "IMPOSSIBLE" << endl;
              found = true;
              return; 
            }
        }
    }
}

int main() {
    cin >> n >> m; 
    fill_n(visit, N, 0); 
    while (m--) {
        int u, v;
        cin >> u >> v; 
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    for(int i = 1; i <= n; ++i ) {
        if(found) return 0; 
        if(visit[i]) bfs(i); 
    }
    
    for(int i = 1; i <= n; ++i) {
      cout << visit[i] << " ";
    }
  return 0; 
}
