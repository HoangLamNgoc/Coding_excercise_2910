#include <iostream>
#include <algorithm>
 
using namespace std;
long long pref[5005]; 
long long sum(int l, int r) {
    return pref[r] - pref[l - 1]; 
}
 
int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0); 
 
    int num; cin >> num;
 
    int a[num + 1];
    long long dp[5005][5005]; 
    fill_n(pref, 5005, 0);
 
    for(int i = 1; i <= num ; ++i) {
        for(int j = 1; j <= num; ++j) {
            dp[i][j] = 0; 
        }
    }
 
    for(int i = 1; i <= num; ++i) cin >> a[i]; 
    for(int i = 1; i <= num; ++i) {
        pref[i] = pref[i - 1] + a[i]; 
        dp[i][i] = a[i]; 
    }
 
    for(int len = 2; len <= num; ++len) {
        for(int j = 1; j + len - 1 <= num; ++j) {
            int r = j + len - 1;
            dp[j][r] = max( a[j] + sum(j + 1, r) - dp[j + 1][r], 
                            a[r] + sum(j, r - 1) - dp[j][r - 1]);  
        }
    }
    cout << dp[1][num]; 
}
