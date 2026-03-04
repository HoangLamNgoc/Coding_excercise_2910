//https://marisaoj.com/problem/662
//Author : Lam Ngoc

#include <bits/stdc++.h>
using namespace std;

const int maxn = 200005;
const int inf = 1e9;

int n, q;
int a[maxn];

int st1[4 * maxn];

struct node {
    int best;
    int lazy;
} st2[4 * maxn];

void upd(int id, int l, int r, int p, int val) {
    if (l == r) {
        st1[id] = val;
        return;
    }
    int m = (l + r) >> 1;
    if (p <= m) upd(id << 1, l, m, p, val);
    else upd(id << 1 | 1, m + 1, r, p, val);
    st1[id] = min(st1[id << 1], st1[id << 1 | 1]);
}

int query(int id, int l, int r, int u, int v) {
    if (l > v || r < u) return inf;
    if (l >= u && r <= v) return st1[id];
    int m = (l + r) >> 1;
    return min(query(id << 1, l, m, u, v),
               query(id << 1 | 1, m + 1, r, u, v));
}

int walk(int id, int l, int r, int u, int v, int val) {
    if (l > v || r < u || st1[id] >= val) return -1;
    if (l == r) return l;
    int m = (l + r) >> 1;
    int res = walk(id << 1, l, m, u, v, val);
    if (res == -1)
        res = walk(id << 1 | 1, m + 1, r, u, v, val);
    return res;
}

void down(int id) {
    if (st2[id].lazy != inf) {
        int v = st2[id].lazy;

        st2[id << 1].best = min(st2[id << 1].best, v);
        st2[id << 1 | 1].best = min(st2[id << 1 | 1].best, v);

        st2[id << 1].lazy = min(st2[id << 1].lazy, v);
        st2[id << 1 | 1].lazy = min(st2[id << 1 | 1].lazy, v);

        st2[id].lazy = inf;
    }
}

void upd2(int id, int l, int r, int u, int v, int val) {
    if (l > v || r < u) return;
    if (l >= u && r <= v) {
        st2[id].best = min(st2[id].best, val);
        st2[id].lazy = min(st2[id].lazy, val);
        return;
    }
    down(id);
    int m = (l + r) >> 1;
    upd2(id << 1, l, m, u, v, val);
    upd2(id << 1 | 1, m + 1, r, u, v, val);
}

int get(int id, int l, int r, int p) {
    if (l == r) return st2[id].best;
    down(id);
    int m = (l + r) >> 1;
    if (p <= m) return get(id << 1, l, m, p);
    return get(id << 1 | 1, m + 1, r, p);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];

    fill(st1, st1 + 4 * maxn, 0);
    for (int i = 0; i < 4 * maxn; i++) {
        st2[i].best = inf;
        st2[i].lazy = inf;
    }

    for (int i = 1; i <= n; i++) {
        if (a[i] > n) continue;

        upd(1, 1, n, a[i], i);

        int cur = a[i];
        while (cur <= n) {
            int mn = query(1, 1, n, 1, cur);
            if (mn == 0) break;

            int r = walk(1, 1, n, cur + 1, n, mn);
            if (r == -1) r = n + 1;

            upd2(1, 1, n, cur, r - 1, i - mn + 1);
            cur = r;
        }
    }

    while (q--) {
        int x;
        cin >> x;

        if (x < 1) {
            cout << 0 << '\n';
        } else if (x > n || query(1, 1, n, 1, x) == 0) {
            cout << -1 << '\n';
        } else {
            int res = get(1, 1, n, x);
            cout << (res >= inf ? -1 : res) << '\n';
        }
    }

    return 0;
}
