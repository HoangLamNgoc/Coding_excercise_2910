#include <iostream>
#include <algorithm>

using namespace std; 
const int MOD = 1e9 + 7; 

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0); 

    int sz, maxv; cin >> sz >> maxv; 

    int arr[sz + 1]; 
    for(int i = 1; i <= sz; ++i) cin >> arr[i]; 
    long long dp[sz + 1][maxv + 1]; 

    for(int i = 0; i <= sz; ++i) 
        for(int j = 0; j <= maxv; ++j) 
            dp[i][j] = 0;

    if (!arr[1]) 
        for(int i = 1; i <= maxv; ++i) 
            dp[1][i] = 1;
    else dp[1][arr[1]] = 1;

    for(int i = 2; i <= sz; ++i) {
        int j = arr[i]; 
        if (j) {
            int v = arr[i]; 
            dp[i][v] = dp[i - 1][v - 1] + dp[i - 1][v] + dp[i - 1][v + 1];   
            dp[i][v] %= MOD;
        }
        else {
            for(int v = 1; v <= maxv; ++v) {
                dp[i][v] = dp[i - 1][v - 1] + dp[i - 1][v] + dp[i - 1][v + 1];   
                dp[i][v] %= MOD;
            }
        }
    }

    long long ans = 0; 
    for(int i = 1; i <= maxv; ++i) {
        ans += dp[sz][i];
        ans %= MOD; 
    }
    cout << ans; 
}
