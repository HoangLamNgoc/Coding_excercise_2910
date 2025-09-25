#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;
const int N = 1e6;  
int end1, start1;
vector<int> g[N + 6];
int par[N + 6]; 
bool visit[N + 6]; 
bool found = false;

void bfs (int s) {
    visit[s] = true; 
    par[s] = -1;

    queue<int> q; 
    q.push(s);

    while ( !q.empty()) {
        auto r1 = q.front();
        q.pop(); 

        for ( auto v : g[r1]) {
            if ( visit[v] == false) {
                q.push(v); 
                visit[v] = true; 
                par[v] = r1; 
            } 
            else {
                if ( v != par[r1]) {
                    found = true; 
                    end1 = v;
                    start1 = r1;
                    return; 
                }
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    while (m--) {
        int u, v; 
        cin >> u >> v; 

        g[u].push_back(v); 
        g[v].push_back(u);
    }
                            
    for (int i = 1; i <= n; ++i ) {
        if (found) break;
        if ( visit[i] == false ) bfs(i); 
    }
    if ( found == false) 
        cout << "IMPOSSIBLE" << endl; 
    else {
      int x = start1, y = end1; 
       while (x != -1) {
            path1.push_back(x);
            x = par[x];
        }
      
        while (y != -1) {
            path2.push_back(y);
            y = par[y];
        }

        reverse(path1.begin(), path1.end());
        reverse(path2.begin(), path2.end());

        int i = 0;
        while (i < (int)path1.size() && i < (int)path2.size() && path1[i] == path2[i]) i++;
        i--;

        vector<int> cycle;
        for (int j = path1.size() - 1; j >= i; j--) 
            cycle.push_back(path1[j]);
        for (int j = i + 1; j < (int)path2.size(); j++) 
            cycle.push_back(path2[j]);
        cycle.push_back(path1[path1.size() - 1]); 

        cout << cycle.size() << "\n";
        for (int v : cycle) cout << v << " ";
        cout << "\n";
    }
    return 0; 
}
  

