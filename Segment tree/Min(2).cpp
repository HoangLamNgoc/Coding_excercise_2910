#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 5;

struct segtree {

    struct node {
        long long val;
        long long lazy;

        node() : val(LLONG_MAX), lazy(0) {}
    } st[MAXN * 4];

    void build(int id, int l, int r, vector<long long> &a) {
        if (l == r) {
            st[id].val = a[l];
            return;
        }

        int mid = (l + r) >> 1;

        build(id << 1, l, mid, a);
        build(id << 1 | 1, mid + 1, r, a);

        st[id].val = min(st[id << 1].val, st[id << 1 | 1].val);
    }

    void push(int id) {
        long long t = st[id].lazy;
        if (t == 0) return;

        int L = id << 1;
        int R = id << 1 | 1;

        st[L].val += t;
        st[R].val += t;

        st[L].lazy += t;
        st[R].lazy += t;

        st[id].lazy = 0;
    }

    void update(int id, int l, int r, int u, int v, long long x) {
        if (r < u || l > v) return;

        if (u <= l && r <= v) {
            st[id].val += x;
            st[id].lazy += x;
            return;
        }

        push(id);

        int mid = (l + r) >> 1;

        update(id << 1, l, mid, u, v, x);
        update(id << 1 | 1, mid + 1, r, u, v, x);

        st[id].val = min(st[id << 1].val, st[id << 1 | 1].val);
    }

    long long query(int id, int l, int r, int u, int v) {
        if (r < u || l > v) return LLONG_MAX;

        if (u <= l && r <= v) return st[id].val;

        push(id);

        int mid = (l + r) >> 1;

        return min(
            query(id << 1, l, mid, u, v),
            query(id << 1 | 1, mid + 1, r, u, v)
        );
    }

} seg;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<long long> a(n + 1);

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    seg.build(1, 1, n, a);

    while (q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int l, r;
            long long x;

            cin >> l >> r >> x;

            seg.update(1, 1, n, l, r, x);
        }
        else {
            int l, r;
            cin >> l >> r;

            cout << seg.query(1, 1, n, l, r) << '\n';
        }
    }
}
