#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXN = 100000 + 5;
const int LOG = 30;

struct segtree {

    struct node {
        int cnt[LOG];
        int lazy;

        node() {
            for(int i = 0; i < LOG; i++) cnt[i] = 0;
            lazy = 0;
        }
    } st[MAXN * 4];

    void apply(int id, int l, int r, int mask) {
        int len = r - l + 1;

        for(int b = 0; b < LOG; b++) {
            if(mask & (1LL << b)) {
                st[id].cnt[b] = len - st[id].cnt[b];
            }
        }

        st[id].lazy ^= mask;
    }

    void push(int id, int l, int r) {
        if(st[id].lazy == 0) return;
        if(l == r) return;

        int mid = (l + r) >> 1;
        int mask = st[id].lazy;

        apply(id << 1, l, mid, mask);
        apply(id << 1 | 1, mid + 1, r, mask);

        st[id].lazy = 0;
    }

    void pull(int id) {
        for(int b = 0; b < LOG; b++)
            st[id].cnt[b] = st[id << 1].cnt[b] + st[id << 1 | 1].cnt[b];
    }

    void build(int id, int l, int r, vector<int> &pref) {

        if(l == r) {
            for(int b = 0; b < LOG; b++)
                st[id].cnt[b] = (pref[l] >> b) & 1;
            return;
        }

        int mid = (l + r) >> 1;

        build(id << 1, l, mid, pref);
        build(id << 1 | 1, mid + 1, r, pref);

        pull(id);
    }

    void update(int id, int l, int r, int u, int v, int mask) {
        if(r < u || l > v) return;

        if(u <= l && r <= v) {
            apply(id, l, r, mask);
            return;
        }

        push(id, l, r);

        int mid = (l + r) >> 1;

        update(id << 1, l, mid, u, v, mask);
        update(id << 1 | 1, mid + 1, r, u, v, mask);

        pull(id);
    }

    void query(int id, int l, int r, int u, int v, int res[LOG]) {
        if(r < u || l > v) return;

        if(u <= l && r <= v) {
            for(int b = 0; b < LOG; b++)
                res[b] += st[id].cnt[b];
            return;
        }

        push(id, l, r);

        int mid = (l + r) >> 1;

        query(id << 1, l, mid, u, v, res);
        query(id << 1 | 1, mid + 1, r, u, v, res);
    }

} st;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<int> a(n + 1);

    for(int i = 1; i <= n; i++)
        cin >> a[i];

    vector<int> pref(n + 1);
    pref[0] = 0;

    for(int i = 1; i <= n; i++)
        pref[i] = pref[i - 1] ^ a[i];

    st.build(1, 0, n, pref);

    while(q--) {

        int type;
        cin >> type;

        if(type == 1) {

            int i, x;
            cin >> i >> x;

            int delta = a[i] ^ x;
            a[i] = x;

            st.update(1, 0, n, i, n, delta);
        }
        else {

            int l, r;
            cin >> l >> r;

            int cnt[LOG] = {0};

            st.query(1, 0, n, l - 1, r, cnt);

            long long ans = 0;
            int len = r - (l - 1) + 1;

            for(int b = 0; b < LOG; b++) {

                long long c1 = cnt[b];
                long long c0 = len - c1;

                ans += c0 * c1 * (1LL << b);
            }

            cout << ans << '\n';
        }
    }
}
