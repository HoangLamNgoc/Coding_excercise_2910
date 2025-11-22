#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0); 

    int n, wei; 
    cin >> n >> wei; 

    vector<int> w(n); 
    for(int i = 0; i < n; ++i) cin >> w[i]; 

    vector<pair<int,int>> dp(1 << n, {1e9, 0}); 
    dp[0] = {1, 0};

    for(int mask = 0; mask < (1 << n); ++mask) {
        for(int i = 0; i < n; ++i) {
            if (!(mask & (1 << i))) { 
                int nw = mask | (1 << i);
                int rides = dp[mask].first; 
                int lst_w = dp[mask].second; 

                if (lst_w + w[i] <= wei)  
                    dp[nw] = min(dp[nw], make_pair(rides, lst_w + w[i]));   
                else
                    dp[nw] = min(dp[nw], make_pair(rides + 1, w[i]));
            }
        }
    } 

    cout << dp[(1 << n) - 1].first << "\n"; 
}
