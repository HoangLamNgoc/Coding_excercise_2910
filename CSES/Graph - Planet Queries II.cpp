#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
const int LOG = 20;

int n, q;
int to[N], id[N], low[N], on[N], scc[N], pos[N], rep[N];
int tmr = 0, cnt = 0;
stack<int> st;
vector<vector<int>> comp;
vector<int> dag[N];
int up[N][LOG + 1], h[N];

void tarjan(int u) {
    id[u] = low[u] = ++tmr;
    st.push(u); on[u] = 1;

    int v = to[u];
    if (!id[v]) {
        tarjan(v);
        low[u] = min(low[u], low[v]);
    }
    else if (on[v]) {
        low[u] = min(low[u], id[v]);
    }

    if (low[u] == id[u]) {
        vector<int> cur;
        while (true) {
            int x = st.top(); st.pop();
            on[x] = 0;
            scc[x] = cnt;
            cur.push_back(x);
            if (x == u) break;
        }
        reverse(cur.begin(), cur.end());

        for (int i = 0; i < (int)cur.size(); i++) pos[cur[i]] = i;

        comp.push_back(cur);

        int r = cur[0];
        for (int x : cur) if (scc[to[x]] != cnt) { r = x; break; }
        rep[cnt] = r;

        cnt++;
    }
}

void buildDAG() {
    for (int u = 1; u <= n; u++) {
        int v = to[u];
        if (scc[u] != scc[v]) dag[scc[u]].push_back(scc[v]);
    }
}

void dfs(int u) {
    for (int v : dag[u]) {
        if (v == up[u][0]) continue;

        up[v][0] = u;
        h[v] = h[u] + 1;

        for (int j = 1; j <= LOG; j++)
            up[v][j] = up[up[v][j - 1]][j - 1];

        dfs(v);
    }
}

int jump(int u, int k) {
    for (int j = 1; (1 << j) <= k; j++)
        if (k & (1 << j)) u = up[u][j];
    return u;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> to[i];

    for (int i = 1; i <= n; i++) if (!id[i]) tarjan(i);

    buildDAG();

    for (int i = 0; i < cnt; i++)
        if (h[i] == 0) dfs(i);

    while (q--) {
        int a, b;
        cin >> a >> b;

        int sa = scc[a], sb = scc[b];

        if (sa == sb) {
            int sz = comp[sa].size();
            int step = (pos[b] - pos[a] + sz) % sz;
            cout << step << "\n";
        }
        else {
            int k = h[sb] - h[sa];
            if (k < 0) { cout << -1 << "\n"; continue; }

            int u = jump(u, k); 
            if(u != sb) {cout << -1 << '\n'; continue;}

            int stepA = (pos[rep[sa]] - pos[a] + comp[sa].size()) % comp[sa].size();
            int stepB = (pos[b] - pos[rep[sb]] + comp[sb].size()) % comp[sb].size();

            cout << stepA + k + stepB + 1<< "\n";
        }
    }
}
