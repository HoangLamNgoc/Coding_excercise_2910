#include <iostream>
#include <algorithm>
#include <vector>

using namespace std; 

int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0); 

    int n, q; cin >> n >> q;

    vector<long long> pref(n + 1, 0);

    for(int i = 1; i <= n; ++i) {
        int a; cin >> a; 

        pref[i] = pref[i - 1] + 1ll * a; 
    }  

    while (q--) {
        int a, b; 
        cin >> a >> b; 

        cout << pref[b] - pref[a - 1] << '\n'; 
    }
}
