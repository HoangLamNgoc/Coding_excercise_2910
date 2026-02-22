#include <iostream>
#include <algorithm>
#include <vector>

using namespace std; 
const int LOG = 20; 

int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(nullptr); 

    int n, q; 
    cin >> n >> q;

    vector<int> arr(n + 1); 
    for(int i = 1; i <= n; ++i) cin >> arr[i]; 

    int st[n + 1][LOG];
    for(int i = 0; i < LOG; ++i) 
        for(int j = 0; j <= n; ++j) 
            st[j][i] = 0; 

    for(int i = 1; i <= n; ++i) st[i][0] = arr[i];   
    for(int k = 1; k < LOG; ++k) 
        for(int i = 1; i + (1 << k) - 1 <= n; ++i) 
            st[i][k] = min(st[i][k - 1], st[i + (1 << (k - 1))][k - 1]); 
    
    while (q--) {
        int a, b; 
        cin >> a >> b; 

        int len = __lg(b - a + 1); 
        cout << min(st[a][len], st[b - (1 << len) + 1][len]) << '\n'; 
    }
}
