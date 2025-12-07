//https://marisaoj.com/problem/138
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, q;

struct node {
    int no, id;
    node() {}
    node(int no1, int id1) : no(no1), id(id1) {}
};

struct DSU {
    vector<int> par, sz;
    vector<bool> actived;

    void init() {
        par.resize(n);
        sz.resize(n);
        actived.resize(n);

        for (int i = 0; i < n; ++i) {
            par[i] = i;
            sz[i] = 1;
            actived[i] = 0;
        }
    }

    int find_root(int v) {
        if (v == par[v]) return v;
        return par[v] = find_root(par[v]);
    }

    int merge(int u, int v) {
        int ru = find_root(u);
        int rv = find_root(v);
        if (ru == rv) return sz[ru];

        if (sz[ru] < sz[rv]) swap(ru, rv);
        par[rv] = ru;
        sz[ru] += sz[rv];
        return sz[ru];
    }
} dsu;

bool ss(const node &x, const node &y) {
    return x.no < y.no;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;
    dsu.init();

    vector<int> arr(n);
    vector<node> brr;
    brr.reserve(n);

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        brr.push_back(node(arr[i], i));
    }

    vector<node> queries;
    queries.reserve(q);

    for (int i = 0; i < q; ++i) {
        int x; cin >> x;
        queries.push_back(node(x, i));
    }

    sort(brr.begin(), brr.end(), ss);
    sort(queries.begin(), queries.end(), ss);

    vector<node> ans(q, node(0, 0));

    int i = 0;
    int mxv = 0;

    for (auto e : queries) {
        int val = e.no;
        int id  = e.id;

        while (i < n && brr[i].no <= val) {
            int idx = brr[i].id;
            dsu.actived[idx] = 1;

            if (idx > 0 && dsu.actived[idx - 1])
                mxv = max(mxv, dsu.merge(idx, idx - 1));
            // cout << 1 << ' ' << mxv << ' ' << id << '\n'; 
            if (idx + 1 < n && dsu.actived[idx + 1])
                mxv = max(mxv, dsu.merge(idx, idx + 1));
            // cout << 2 << ' ' << mxv << ' ' << id << '\n'; 
            mxv = max(mxv, dsu.sz[dsu.find_root(idx)]);
            i++;
            // cout << 3 << ' ' << mxv << ' ' << id << '\n'; 
        }
        // cout << mxv << '^' << id << '\n'; 
        ans[id] = node(mxv, id);
    }

    for (int i = 0; i < q; ++i)
        cout << ans[i].no << '\n';
}
