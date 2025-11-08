#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 2e5 + 5;
int n, m;
vector<int> g[N];
long long coins[N];

int timer = 0, num[N], low[N], id[N];
bool in_stack[N];
stack<int> st;
int scc_cnt = 0;
long long val_scc[N]; 

void tarjan(int u) {
    num[u] = low[u] = ++timer;
    st.push(u);
    in_stack[u] = true;

    for(int v : g[u]) {
        if(!num[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if(in_stack[v]) {
            low[u] = min(low[u], num[v]);
        }
    }

    if(low[u] == num[u]) {
        ++scc_cnt;
        long long sum = 0;
        int v;
        do {
            v = st.top(); st.pop();
            in_stack[v] = false;
            id[v] = scc_cnt;
            sum += coins[v];
        } while(v != u);
        val_scc[scc_cnt] = sum;
    }
}

vector<int> adj[N];
void buildDAG() {
    for(int u = 1; u <= n; ++u) {
        for(int v : g[u]) {
            if(id[u] != id[v]) {
                adj[id[u]].push_back(id[v]);
            }
        }
    }
}

vector<int> topo;
bool vis[N];
void dfsTopo(int u) {
    vis[u] = true;
    for(int v : adj[u])
        if(!vis[v]) dfsTopo(v);
    topo.push_back(u);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for(int i = 1; i <= n; ++i) cin >> coins[i];
    for(int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }

    fill(num, num + N, 0);
    fill(low, low + N, 0);
    fill(in_stack, in_stack + N, false);

    for(int i = 1; i <= n; ++i)
        if(!num[i]) tarjan(i);

    buildDAG();
    fill(vis, vis + N, false);
    for(int i = 1; i <= scc_cnt; ++i)
        if(!vis[i]) dfsTopo(i);

    reverse(topo.begin(), topo.end());

    long long dp[N] = {0};
    long long ans = 0;
    for(int u : topo) {
        dp[u] = max(dp[u], val_scc[u]);
        for(int v : adj[u])
            dp[v] = max(dp[v], dp[u] + val_scc[v]);
        ans = max(ans, dp[u]);
    }

    cout << ans << "\n";
}
