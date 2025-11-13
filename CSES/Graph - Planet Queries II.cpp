#include <iostream>
#include <vector>
#include <stack>
using namespace std;

const int N = 2e5 + 5;
const int LOG = 20;

int g[N];
int low[N], num[N];
int scc = 1, tin = 0;
vector<vector<int>> comp;
int dist_scc[N];        
vector<int> length;     
int id[N];    
stack<int> st;
bool vis[N], on_stack[N];
int up[N][LOG];
int root[N];          
int dist[N];           
bool in_cycle[N];     
int n, q;


void tarjan(int u) {
    vis[u] = true;
    on_stack[u] = true;
    st.push(u);
    low[u] = num[u] = ++tin;

    int v = g[u];
    if (!vis[v]) {
        tarjan(v);
        low[u] = min(low[u], low[v]);
    } else if (on_stack[v])
        low[u] = min(low[u], num[v]);

    if (low[u] == num[u]) {
        vector<int> order;
        while (true) {
            v = st.top(); st.pop();
            on_stack[v] = false;
            id[v] = scc;
            order.push_back(v);
            if (v == u) break;
        }

        int dem = order.size();
        length.push_back(dem);

        for (int i = 0; i < dem; ++i) {
            int node = order[i];
            dist_scc[node] = i;     
            in_cycle[node] = true;
            root[node] = node;       
            dist[node] = 0;          
        }

        comp.push_back(order);
        scc++;
    }
}

void build() {
    for (int u = 1; u <= n; ++u) {
        up[u][0] = g[u];
    }

    for (int k = 1; k < LOG; ++k) {
        for (int u = 1; u <= n; ++u) {
            up[u][k] = up[up[u][k - 1]][k - 1];
        }
    }


    for (int u = 1; u <= n; ++u) {
        if (!in_cycle[u]) {
            int cur = u, d = 0;
            while (!in_cycle[cur]) {
                cur = g[cur];
                d++;
            }
            root[u] = cur;
            dist[u] = d;
        }
    }
}


int jump(int u, int steps) {
    for (int k = 0; k < LOG; ++k) {
        if (steps & (1 << k))
            u = up[u][k];
    }
    return u;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> q;
    for (int i = 1; i <= n; ++i) cin >> g[i];

    for (int i = 1; i <= n; ++i) {
        if (!num[i]) tarjan(i);
    }

    build();

    while (q--) {
        int u, v;
        cin >> u >> v;

        if (id[u] == id[v] && in_cycle[u] && in_cycle[v]) {
            int len = length[id[u] - 1];
            int ans = (dist_scc[v] - dist_scc[u] + len) % len;
            cout << ans << '\n';
        }
        else if (!in_cycle[u] && !in_cycle[v] && root[u] == root[v]) {
            int steps = dist[v] - dist[u];
            if (steps < 0) cout << -1 << '\n';
            else {
                int reached = jump(u, steps);
                cout << (reached == v ? steps : -1) << '\n';
            }
        }

        else if (!in_cycle[u] && in_cycle[v] && root[u] != v && id[root[u]] == id[v]) {
            int len = length[id[v] - 1];
            int cycle_dist = (dist_scc[v] - dist_scc[root[u]] + len) % len;
            cout << dist[u] + cycle_dist << '\n';
        }
        else {
            cout << -1 << '\n';
        }
    }
}
