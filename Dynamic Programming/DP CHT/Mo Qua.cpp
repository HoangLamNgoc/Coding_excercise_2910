#include <bits/stdc++.h>

using namespace std; 

deque<long long> A, B;

bool bad(int l1, int l2, long long a, long long b) {
    return ((b - B[l1]) * (A[l1] - A[l2]) < (B[l2] - B[l1]) * (A[l1] - a));  
}

void add(long long a, long long b) {

    while (A.size() >= 2 && bad(A.size() - 2, A.size() - 1, a, b)) {
        A.pop_back(); 
        B.pop_back(); 
    }; 

    A.push_back(a); 
    B.push_back(b); 
}

long long query(long long x) {
    
    while (A.size() >= 2 && (A[0] * x + B[0] >= A[1] * x + B[1])) { 
        A.pop_front(); 
        B.pop_front(); 
    }

    return A[0] * x + B[0];
}

int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 

    int n, C; cin >> n >> C; 

    long long pref[n + 1] = {}; 

    for(int i = 1; i <= n; ++i) {
        cin >> pref[i]; 
        pref[i] += pref[i - 1]; 
    }

    long long dp[n + 1] = {}; 
    add(0LL, 0LL); 
    for(int i = 1; i <= n; ++i) {
        dp[i] = query(pref[i]) + C + pref[i] * pref[i]; 

        if (i < n) 
            add(-2 * pref[i], dp[i] + pref[i] * pref[i]); 
    }

    cout << dp[n]; 
}
