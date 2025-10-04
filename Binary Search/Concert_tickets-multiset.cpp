#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    multiset<int> a;
    int b[m];
    for(int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        a.insert(x);
    }
    for(int i = 0; i < m; ++i) cin >> b[i];
    for(int i = 0; i < m; ++i) {
        auto it = a.upper_bound(b[i]);
        if(it == a.begin()) cout << -1 << endl;
        else {
            it--;
            cout << *it << endl;
            a.erase(it);
        }
    }

    return 0;
}
