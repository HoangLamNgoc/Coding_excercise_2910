#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int parent[N], sz[N], mx[N];

void make_set(int v) {
    parent[v] = v;
    sz[v] = 1;
    mx[v] = v; 
}

int find_set(int v) {
    if (v == parent[v]) return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (sz[a] < sz[b]) swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
        mx[a] = max(mx[a], mx[b]);
    }
}

void leave(int v) {
    union_sets(v, v + 1); 
}

int find_next(int p) {
    p = find_set(p);
    return mx[p];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n + 1; ++i) make_set(i); 

    while (q--) {
        string cmd;
        int x;
        cin >> cmd >> x;
        if (cmd == "-") leave(x);
        else if (cmd == "?") {
            int ans = find_next(x);
            if (ans > n) cout << -1 << "\n";
            else cout << ans << "\n";
        }
    }
}
