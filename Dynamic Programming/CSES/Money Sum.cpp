#include <iostream>
#include <vector>

using namespace std; 

int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0); 

    int n; cin >> n; 

    int a[n + 1];
    long long mxs = 0; 
    for(int i = 1; i <= n; ++i) {
        cin >> a[i]; 
        mxs += a[i]; 
    }
    
    bool dp[mxs + 1]; 
    fill_n(dp, mxs + 1, 0); 
    dp[0] = 1; 
    for(int i = 1; i <= n; ++i) {
        for(long long j = mxs; j >= 0; --j) {
            if (dp[j]) dp[j + a[i]] = 1; 
        }
    }

    vector<long long> path;
    int cnt = 0; 
    for(long long i = 1; i <= mxs; ++i) {
        if (dp[i]) {
            ++cnt; 
            path.push_back(i); 
        }
    }
    cout << cnt << '\n'; 
    for(long long i : path) cout << i << ' '; 
}
