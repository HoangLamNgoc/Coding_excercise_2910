#include <iostream>
#include <vector>

using namespace std; 

int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 

    int n, q; cin >> n >> q; 

    string g[n + 1]; 
    for(int i = 0; i < n; ++i) 
        cin >> g[i]; 

    vector<vector<long long>> pref(n + 1, vector<long long>(n + 1, 0)); 

    for(int i = 1; i <= n; ++i) 
        for(int j = 1; j <= n; ++j) 
            pref[i][j] = (g[i - 1][j - 1] == '*') * 1LL + pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1]; 

    
    while (q--) {
        int r1, c1, r2, c2; 
        cin >> r1 >> c1 >> r2 >> c2; 

        cout << pref[r2][c2] - pref[r1 - 1][c2] - pref[r2][c1 - 1] + pref[r1 - 1][c1 - 1] << '\n';
    }
}
