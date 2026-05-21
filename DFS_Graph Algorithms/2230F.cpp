#include <bits/stdc++.h>

using namespace std; 
const int MAXN = 2e5 + 5; 

vector<int> adj[MAXN]; 
pair<int, long long> maxv[MAXN][3]; 
long long ans = 0; 

bool upd(int u, int f, long long val) {
    vector<pair<int, long long>> temp;
    
    temp.push_back({f, val}); 
    for(int i = 0; i < 3; ++i) 
        if (maxv[u][i].first != f && maxv[u][i].first) 
            temp.push_back(maxv[u][i]); 

    sort(temp.begin(), temp.end(), [](const pair<int, long long>& a, const pair<int, long long>& b) {
        return a.second > b.second; 
    });

    bool ok = 0;
    int m = (int)temp.size(); 
    for(int i = 0; i < 3; ++i) {
        pair<int, long long> next = (i < m ? temp[i] : make_pair(0, 0LL)); 
        if (maxv[u][i].second != next.second) //bug1 : Neu m de la maxv[u][i] != next thi bi sai do khong du chat. how about neu minh co nhieu dinh co cung second ? gia tri lan truyen co thay doi khong ? neu the thi co can duoc ghi nhan khong ? 
            ok = 1; 
        maxv[u][i] = next; 
    }
    ans = max(ans, maxv[u][1].second);
    return ok; 
}

long long gtmx2(int u, int v) {
    int uf2 = maxv[u][1].first; 
    int uf1 = maxv[u][0].first; 

    if (uf2 != v && uf1 != v) return maxv[u][1].second;
    else return maxv[u][2].second;  
}

bool vis[MAXN]; 
void bfs(int s, int p) {
    queue<int> q; 
    
    if (upd(p, s, 1)) {
        q.push(p);
        vis[p] = 1;
    }
    
    upd(s, p, gtmx2(p, s) + 1);
    
    while (!q.empty()) {
        int u = q.front(); 
        q.pop();

        vis[u] = 0;  

        for(int v : adj[u]) {
            long long g = gtmx2(u, v) + 1; 
            if (upd(v, u, g)) 
                if (!vis[v]) {
                    q.push(v);
                    vis[v] = 1; //bug2 : push xong phai biet danh dau :) nao de o duoi chan a
                } 

        }
    }
}

void solve(int i, int u) {

    adj[i].emplace_back(u); 
    adj[u].emplace_back(i); 
 
    bfs(i, u); 
    cout << ans + 1 << '\n'; 
}



int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 

    int q; cin >> q; 

    for(int i = 2; i <= q + 1; ++i) {
        int u; cin >> u; 

        solve(i, u); 
    }
}
