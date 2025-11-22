#include <iostream>

using namespace std; 
const int MOD = 1e9 + 7; 
const int MAXN = 1e6; 

int main() {
    int t, n; cin >> t; 

    long long dp[MAXN + 5][2]; 
    for(int i = 1; i <= MAXN; ++i) 
        dp[i][0] = dp[i][1] = 0; 

    dp[1][0] = dp[1][1] = 1; 
    for(int i = 2; i <= MAXN; ++i ) {
        dp[i][0] += 2 * dp[i - 1][0];
        dp[i][0] %= MOD; 
        dp[i][0] += dp[i - 1][1];
        dp[i][0] %= MOD; 
        dp[i][1] += 4 * dp[i - 1][1]; 
        dp[i][1] %= MOD;
        dp[i][1] += dp[i - 1][0]; 
        dp[i][1] %= MOD;
    }

    while(t--) {
        cin >> n; 
        cout << (dp[n][1] + dp[n][0]) % MOD << endl; 
    }
}
