#include <bits/stdc++.h>
using namespace std;
const int N = 1e5; 
const int mod = 1e9 + 7; 

int min_prime[N + 1];
long long ans[N + 5], inv[N * 20]; 
map<int,int> f[N + 5];
vector<int> g[N + 1];  

void sieve() {
    for(int i = 2; i * i <= N; ++i) {
        if(!min_prime[i]) {
            for(int j = i * i; j <= N; j += i) {
                if(!min_prime[j]) min_prime[j] = i;  
            }
        }
    }
    for(int i = 2; i <= N; ++i)
        if(!min_prime[i]) min_prime[i] = i;
}

void dfs(int u, int pre = 0) {
    for(int v : g[u]) {
        if (v == pre) continue; 
        dfs(v, u); 

        ans[u] = 1LL * ans[u] * ans[v] % mod; 
        if(f[u].size() < f[v].size()) swap(f[u], f[v]); 

        for(auto x : f[v]) {
            if(f[u][x.first]) 
                ans[u] = 1LL * ans[u] * (f[u][x.first] + x.second + 1) % mod
                         * inv[f[u][x.first] + 1] % mod
                         * inv[x.second + 1] % mod; 
            f[u][x.first] += x.second; 
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    sieve();

    int n, q;
    cin >> n >> q;

    inv[1] = 1;
    for(int i = 2; i < 20*N; ++i)
        inv[i] = 1LL * (mod - mod / i) * inv[mod % i] % mod;

    for(int i = 1; i <= n; ++i) {
        int x; cin >> x;
        ans[i] = 1;
        int cnt = 0;

        while(x > 1) {
            int p = min_prime[x];
            if(!f[i][p]) {
                ans[i] = ans[i] * (cnt + 1) % mod;
                cnt = 0;
            }
            cnt++;
            f[i][p]++;
            x /= p;
        }
        ans[i] = ans[i] * (cnt + 1) % mod;
    }

    for(int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1);

    while(q--) {
        int x; cin >> x;
        cout << ans[x] << ' ';
    }
}
