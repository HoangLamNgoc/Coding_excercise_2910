#include <iostream>
#include <algorithm>
#include <set>

using namespace std; 

int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0); 

    int t; cin >> t;

    while(t--) {
        int n; cin >> n; 

        vector<int> a(n), b(n); 

        int maxva[n], minva[n], maxvb[n], minvb[n]; 
        fill_n(maxva, n, 0); 
        fill_n(minva, n, 1e9);
        fill_n(maxvb, n, 0); 
        fill_n(minvb, n, 1e9);

        for(int i = 0; i < n; ++i){
            cin >> a[i];
            if (i != 0) {
                maxva[i] = max(maxva[i - 1], a[i]);
                minva[i] = min(minva[i - 1], a[i]); 
            }
            else {
                maxva[i] = a[i];
                minva[i] = a[i]; 
            }  
        } 
        for(int i = 0; i < n; ++i){
            cin >> b[i];
        }

        for(int i = n - 1; i >= 0; --i) {
            if (i != n - 1) {
                maxvb[i] = max(maxvb[i + 1], b[i]);
                minvb[i] = min(minvb[i + 1], b[i]); 
            }
            else {
                maxvb[i] = b[i];
                minvb[i] = b[i]; 
            }  
        } 


        int best[2 * n + 1]; 
        fill_n(best, 2 * n + 1, 0); 
        for(int i = 0; i < n; ++i) {
            int j = i;
            int l = min(minva[i], minvb[j]); 
            int r = max(maxva[i], maxvb[j]); 
            if (r >= 1 && l >= 1 && r <= 2 * n)
                best[r] = max(best[r], l);
        }
        int ans = 0, cur = 0; 
        for(int i = 0; i <= 2 * n; ++i) {
            cur = max(best[i], cur);
            ans += cur; 
        } 
        cout << ans << '\n'; 
    }
}.cpp
