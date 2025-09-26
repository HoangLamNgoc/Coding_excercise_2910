#include <bits/stdc++.h>

using namespace std;

int n, m;
const int N = 1e5; 
int j[N + 5], num[N + 5], low[N + 5]; 
int b = 0, tin = 0;
vector<int> g[N];

void dfs(int u, int pre) {
 low[u] = num[u] = ++tin;
 int child = 0; 
 for (auto v : g[u]) {
   if ( v == pre) continue; 
   if (!num[v]) {
     dfs (v, u); 
     low[u] = min(low[u], low[v]);
     child++;
     if ( low[v] == num[v]) b++;
     if (u == pre) { 
        if (child > 1) j[u] = 1;
      } else if ( low[v] >= num[u]) j[u] = 1;
   }
   else low[u] = min(low[u], num[v]); 
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
  int cnt = 0; 
  fill_n(j, 0, N + 5);
  fill_n(num, 0, N + 5); 
  fill_n(low, 0, N + 5); 
  for (int i = 1; i <= n; ++i) {
    if (!num[i]) dfs(i , i); 
  }
  for (int i = 1; i <= n; ++i) cnt += j[i]; 
  cout << cnt << " " << b; 
  return 0;
  
}
