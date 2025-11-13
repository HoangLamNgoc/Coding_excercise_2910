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

// Tarjan để tìm SCC / cycle
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
        if (dem > 1 || g[u] == u) {
            for (int i = 0; i < dem; ++i) {
                int node = order[i];
                dist_scc[node] = i;
                in_cycle[node] = true;
                root[node] = node;
                dist[node] = 0;
            }
            length.push_back(dem);
            scc++;
            comp.push_back(order);
        } else {
            in_cycle[u] = false;
            id[u] = 0;
        }
    }
}

// DFS fill root/dist ngoài chu trình, O(n)
void dfs_dist(int u) {
    if (in_cycle[u]) {
        root[u] = u;
        dist[u] = 0;
        return;
    }
    if (root[u]) return; // đã tính
    int v = g[u];
    dfs_dist(v);
    root[u] = root[v];
    dist[u] = dist[v] + 1;
}

// Build up[][] và fill root/dist
void build() {
    for (int u = 1; u <= n; ++u)
        up[u][0] = g[u];

    for (int k = 1; k < LOG; ++k) {
        for (int u = 1; u <= n; ++u) {
            up[u][k] = up[up[u][k - 1]][k - 1];
        }
    }

    for (int u = 1; u <= n; ++u)
        dfs_dist(u);
}

// Jump nhanh bằng binary lifting
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
    fill_n(g + 1, n, 0);
    fill_n(low + 1, n, 0);
    fill_n(num + 1, n, 0);
    fill_n(dist_scc + 1, n, 0);
    fill_n(id + 1, n, 0);
    fill_n(dist + 1, n, 0);
    fill_n(root + 1, n, 0);
    fill_n(in_cycle + 1, n, false);
    fill_n(vis + 1, n, false);
    fill_n(on_stack + 1, n, false);
    for (int i = 1; i <= n; ++i) cin >> g[i];

    for (int i = 1; i <= n; ++i) {
        if (!num[i]) tarjan(i);
    }

    build();

    while (q--) {
        int u, v;
        cin >> u >> v;

        // debug các node
         vector<int> p;
         p.push_back(u);
         p.push_back(v);

         for(int i : p) {
             //cout << id[i] << ' ' << in_cycle[i] << ' ' << dist[i] << ' ' << dist_scc[i] << ' ' << length[i] << '\n';
         }
        //cout << '\n';

        // 1. Cả u và v đều trong cùng chu trình
        if (id[u] == id[v] && in_cycle[u] && in_cycle[v]) {
            //cout << 1;
            int len = length[id[v] - 1];
            int ans = (dist_scc[u] - dist_scc[v] + len) % len;
            cout << ans << '\n';
        }
        // 2. Cả u và v đều ngoài chu trình cùng dẫn tới 1 root
        else if (!in_cycle[u] && !in_cycle[v] && root[u] == root[v]) {
            //cout << 2;
            int steps = dist[u] - dist[v];
            if (steps < 0) cout << -1 << '\n';
            else {
                int reached = jump(u, steps);
                cout << (reached == v ? steps : -1) << '\n';
            }
        }
        // 3. u ngoài chu trình, v trong chu trình
        else if (!in_cycle[u] && in_cycle[v] && id[root[u]] == id[v]) {
            int len = length[id[v] - 1];
            //cout << 3;
            int cycle_dist = (dist_scc[root[u]] - dist_scc[v] + len) % len;
            cout << dist[u] + cycle_dist << '\n';
        }
        // 4. Không đi được
        else {
            //cout << 4;
            cout << -1 << '\n';
        }
    }
}
