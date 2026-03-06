#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 5;

struct segtree {

    struct node {
        long long val;
        node() : val(0) {}
        node(long long v) : val(v) {}
    } st[MAXN * 4];

    void build(int id, int l, int r, vector<long long> &a) {
        if (l == r) {
            st[id].val = a[l];
            return;
        }

        int mid = (l + r) >> 1;

        build(id << 1, l, mid, a);
        build(id << 1 | 1, mid + 1, r, a);

        st[id].val = st[id << 1].val + st[id << 1 | 1].val;
    }

    void update(int id, int l, int r, int pos, long long val) {
        if (l == r) {
            st[id].val = val;
            return;
        }

        int mid = (l + r) >> 1;

        if (pos <= mid)
            update(id << 1, l, mid, pos, val);
        else
            update(id << 1 | 1, mid + 1, r, pos, val);

        st[id].val = st[id << 1].val + st[id << 1 | 1].val;
    }

    long long query(int id, int l, int r, int u, int v) {
        if (r < u || l > v) return 0;

        if (u <= l && r <= v) return st[id].val;

        int mid = (l + r) >> 1;

        return query(id << 1, l, mid, u, v) +
               query(id << 1 | 1, mid + 1, r, u, v);
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
            int i;
            long long x;
            cin >> i >> x;

            seg.update(1, 1, n, i, x);
        }
        else {
            int l, r;
            cin >> l >> r;

            cout << seg.query(1, 1, n, l, r) << '\n';
        }
    }
}
