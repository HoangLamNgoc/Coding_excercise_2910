#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e5 + 5;
const int INF = INT_MAX;

vector<int> g[maxn << 1];
int n, m;
int NOT(int x) {
    return x + (x <= m ? m : -m);
}

int low[maxn << 1], num[maxn << 1];
int tin = 0, scc = 0;
stack<int> st;
int id[maxn << 1];

void dfs (int s) {
    low[s] = num[s] = ++tin;
    st.push(s);

    for(int v : g[s]) {
        if (id[v] != 0) continue;
        if (!num[v]) {
            dfs(v);
            low[s] = min(low[s], low[v]);
        }
        else low[s] = min(low[s], num[v]);
    }

    if (num[s] == low[s]) {
        int v;
        ++scc;
        do {
            v = st.top();
            st.pop();
            id[v] = scc;
        } while (v != s);
    }
}

int main() {
    cin >> n >> m;

    for(int i = 1; i <= n; ++i) {
        char t1, t2;
        int u, v;
        cin >> t1 >> u >> t2 >> v;

        if (t1 == '-') u = NOT(u);
        if (t2 == '-') v = NOT(v);

        g[NOT(u)].emplace_back(v);
        g[NOT(v)].emplace_back(u);
    }

    fill_n(low, maxn << 1, INF);
    fill_n(num, maxn << 1, 0);
    fill_n(id, maxn << 1, 0);

    for(int i = 1; i <= 2 * m; ++i) {
        if (!id[i]) dfs(i);
    }

    for(int i = 1; i <= m; ++i) {
        if(id[i] == id[NOT(i)]) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }


    for(int i = 1; i <= m; ++i) cout << (id[i] > id[NOT(i)] ? '-' : '+') << ' ';
}
