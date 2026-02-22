#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
int n;
int a[MAXN];
int bit[MAXN];

void update(int i, int v) {
    while (i <= n) {
        bit[i] += v;
        i += i & -i;
    }
}

int sum(int i) {
    int s = 0;
    while (i > 0) {
        s += bit[i];
        i -= i & -i;
    }
    return s;
}

int find_pos(int p) {
    int l = p, r = n, ans = n;

    while (l <= r) {
        int mid = (l + r) >> 1;

        int alive = mid - sum(mid);

        if (alive >= p) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 1; i <= n; i++) {
        int p;
        cin >> p;

        int idx = find_pos(p);
        cout << a[idx] << " ";

        update(idx, 1);
    }
}


