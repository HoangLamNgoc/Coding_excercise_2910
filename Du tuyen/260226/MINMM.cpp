#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("MINMM.INP", "r", stdin);
    freopen("MINMM.OUT", "w", stdout);

    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) cin >> arr[i];

    sort(arr.begin(), arr.end());

    int m = n - k;  

    vector<int> diff(n - 1);
    for (int i = 0; i < n - 1; ++i)
        diff[i] = arr[i + 1] - arr[i];

    deque<int> dq;

    for (int i = 0; i < m - 1; ++i) {
        while (!dq.empty() && diff[i] < diff[dq.back()])
            dq.pop_back();
        dq.push_back(i);
    }

    long long ans = 1LL * diff[dq.front()] + (arr[m - 1] - arr[0]);

    for (int i = 1; i + m - 1 < n; ++i) {
        while (!dq.empty() && dq.front() < i)
            dq.pop_front();

        int j = i + m - 2;
        while (!dq.empty() && diff[j] < diff[dq.back()])
            dq.pop_back();
        dq.push_back(j);

        long long range = arr[i + m - 1] - arr[i];
        long long min_diff = diff[dq.front()];

        ans = min(ans, range + min_diff);
    }

    cout << ans << '\n';
}
