//https://www.notion.so/2173C-Kanade-s-Perfect-Multiples-2c18b4d60bef80dfbc97c2c7af22be00?source=copy_link

#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std; 

void solve() {
    int n, k; cin >> n >> k; 
    vector<bool> vis(k + 1, 0); 

    set<int> s; vector<int> ans; 

    for(int i = 1; i <= n; ++i) {
        int u; cin >> u; 
        s.insert(u);
        vis[u] = 1;  
    }

    while(s.size()) {
        int t = *(s.begin()); 
        ans.push_back(t); 

        for(int i = t; i <= k; i += t) {
            if (!vis[i]) {
                cout << -1 << '\n'; 
                return; 
            }
            auto it = s.find(i); 
            if (it != s.end()) s.erase(it);
        }
    }

    cout << ans.size() << '\n'; 
    for(int i : ans) cout << i << ' '; 
    cout << '\n'; 
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0); 

    int T; cin >> T;

    while(T--) {
        solve(); 
    }
}
