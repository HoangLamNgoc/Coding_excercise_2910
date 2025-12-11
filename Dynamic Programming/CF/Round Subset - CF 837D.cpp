#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0); 

    int n, k; 
    cin >> n >> k; 

    vector<long long> a(n); 
    for(int i = 0; i < n; ++i) cin >> a[i]; 
    
    vector<int> c2(n), c5(n);
    for(int i = 0; i < n; i++) {
        long long x = a[i];
        while(x % 2 == 0) { c2[i]++; x /= 2; }
        x = a[i];
        while(x % 5 == 0) { c5[i]++; x /= 5; }
    }

    int mx5 = 0; 
    for(int i = 0; i < n; ++i) mx5 += c5[i]; 

    vector<vector<int>> dp(k + 1, vector<int>(mx5 + 1, -1));
    dp[0][0] = 0;  

    for(int i = 0; i < n; ++i) {
        for(int j = k - 1; j >= 0; --j) {
            for(int total = 0; total <= mx5 - c5[i]; ++total) {
                if(dp[j][total] != -1) {
                    dp[j + 1][total + c5[i]] = max(dp[j + 1][total + c5[i]], dp[j][total] + c2[i]);
                }
            }
        }
    }

    int ans = 0;
    for(int f = 0; f <= mx5; f++) {
        if(dp[k][f] != -1) {
            ans = max(ans, min(f, dp[k][f]));
        }
    }

    cout << ans << "\n";
}


//https://www.notion.so/Round-Subset-CF-837D-2c68b4d60bef8072a14bcf7915b708a4
