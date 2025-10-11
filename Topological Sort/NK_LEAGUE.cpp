#include <queue>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
const int maxn = 1e3 + 5; 
vector<int> g[maxn], tp; 
int a[maxn], vis[maxn]; 
int n;
bool ok = true; 

void input() {
    cin >> n;

    for(int i = 1; i <= n; ++i) {
        string s; 
        cin >> s;
        for(int j = 0; j < n; ++j) {
            if(s[j] == '1') {
              g[i].push_back(j + 1); 
            }
        }
    }

    fill_n(vis, maxn, false); 
    fill_n(a, maxn, 0); 
}

void dfs(int u) {
    vis[u] = 1; 
    for(int v : g[u]) {
        if(!vis[v]) dfs(v);
    }
    tp.push_back(u);
    vis[u] = 2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();

    for(int i = 1; i <= n; ++i) {
        if(!vis[i]) dfs(i); 
    }
    if ((int)tp.size() < n) {
        cout << -1 << endl; 
        return 0; 
    }

    reverse(tp.begin(), tp.end());
    int cnt = 0; 
    for(int x : tp) cout << x << endl; 
}


/* Link bài : https://oj.vnoi.info/src/10523581
Chứng minh tính đúng sai của thuật toán : https://www.notion.so/NKLEAGUE-2898b4d60bef80299518cbdba1ce92ad?source=copy_link
*/
