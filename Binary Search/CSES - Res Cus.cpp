#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main() {
    int n; cin >> n;

    pair<int,int> a[n + 5];
    for(int i = 0; i < n; ++i) cin >> a[i].first >> a[i].second;

    vector<pair<int,int>> a2;
    for(int i = 0; i < n; i++) {
        a2.push_back({a[i].first, 1});
        a2.push_back({a[i].second, -1});
    }

    sort(a2.begin(), a2.end());
    int maxs = 0, cur = 0;

    for(auto& i : a2) {
        cur += i.second;
        maxs = max(cur, maxs);
    }

    cout << maxs << endl;
    return 0;
}
