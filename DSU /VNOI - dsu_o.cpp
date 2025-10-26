#include <bits/stdc++.h>
using namespace std;

vector<int> par, sz, col;

void init(int n) {
  par.resize(n + 1);
  sz.resize(n + 1, 1);
  col.resize(n + 1, 0);  
  for(int i = 1; i <= n; i++) par[i] = i;
}

int find_root(int x) {
  if (par[x] == x) return x;
  int p = find_root(par[x]);
  col[x] ^= col[par[x]]; 
  return par[x] = p;
}


bool merge(int u, int v) {
  int ru = find_root(u);
  int rv = find_root(v);
  if (ru == rv) {
    return (col[u] != col[v]);
  }

  if (sz[ru] < sz[rv]) {
    swap(ru, rv);
    swap(u, v);
  }
  
  int shift = col[u] ^ col[v] ^ 1;
  par[rv] = ru;
  col[rv] = shift;
  sz[ru] += sz[rv];
  return true;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, q;
  cin >> n >> q;
  init(n);

  for(int i = 1; i <= q; i++){
    int u, v;
    cin >> u >> v;
    if (!merge(u, v)) {
      cout << i << "\n";
      return 0;
    }
  }
  cout << -1 << "\n";
  return 0;
}
