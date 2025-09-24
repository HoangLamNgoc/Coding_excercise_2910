#include <bits/stdc++.h>
using namespace std;

string bfs(int n) {
    vector<bool> visit(n, false);
    queue<pair<int,string>> q; 

    q.push({1 % n, "1"});
    visit[1 % n] = true;

    while (!q.empty()) {
        auto [rem, s] = q.front(); q.pop();
        if (rem == 0) return s; 
        
        int rem0 = (rem * 10) % n;
        if (!visit[rem0]) {
            visit[rem0] = true;
            q.push({rem0, s + "0"});
        }

        int rem1 = (rem * 10 + 1) % n;
        if (!visit[rem1]) {
            visit[rem1] = true;
            q.push({rem1, s + "1"});
        }
    }
    return ""; 
}

int main() {
    int k; 
    cin >> k;
    while (k--) {
        int n; 
        cin >> n;
        cout << bfs(n) << "\n";
    }
    return 0;
}
