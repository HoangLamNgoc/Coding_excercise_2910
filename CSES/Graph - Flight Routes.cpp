#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std; 
const int N = (int)1e5 + 5;  

bool ss(const int& x, const int& y) {
    return x > y; 
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;  

    vector<pair<int,int>> g[N]; 
    while(m--) {
        int u, v, w; 
        cin >> u >> v >> w; 

        g[u].emplace_back(make_pair(v, w));
    }

    vector<vector<int>> d;
    const int INF = 1e9; 
    d.resize(n + 1);
    d[1].emplace_back(0);  
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
    q.push({0, 1});

    while (!q.empty()) {
        pair<int,int> e = q.top(); q.pop(); 
        int c = e.first; 
        int u = e.second; 

        if (d[u].size() == k && c > d[u].front()) continue;   

        for(pair<int,int> e1 : g[u]) {
            int v = e1. first; 
            int w = e1.second; 

            if ((int)d[v].size() < k ) {
                d[v].emplace_back(w + c);
                sort(d[v].begin(), d[v].end(),ss); 
                q.push({w + c, v});
            }
            else {
                if(c + w < d[v][0]) {
                    d[v].emplace_back(c + w); 
                    d[v].erase(d[v].begin()); 
                    sort(d[v].begin(), d[v].end(),ss); 
                    q.push({c + w, v}); 
                }
            } 
        }
    }
    sort(d[n].begin(), d[n].end()); 
    for(int i : d[n]) cout << i << ' ';
}
