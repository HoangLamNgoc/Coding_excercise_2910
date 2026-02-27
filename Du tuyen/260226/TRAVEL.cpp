#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> par, sze;
    vector<bool> tag;
    vector<int> ans;
    vector<vector<int>> lst;
    vector<int> pos;

    void ini(int n) {
        par.resize(n + 1);
        iota(par.begin(), par.end(), 0);

        sze.assign(n + 1, 1);
        tag.assign(n + 1, 0);
        ans.assign(n + 1, -1);
        lst.assign(n + 1, {});
        pos.assign(n + 1, 0);

        tag[1] = 1;
    }

    int fnd(int u) {
        return (u == par[u] ? u : par[u] = fnd(par[u]));
    }

    void upd(int rt, int w) {
        for (int x : lst[rt]) {
            if (pos[x] && ans[pos[x]] < 0)
                ans[pos[x]] = w;
        }
    }

    void uni(int u, int v, int w) {
        int ru = fnd(u);
        int rv = fnd(v);
        if (ru == rv) return;

        if (sze[ru] < sze[rv]) swap(ru, rv);

        if (tag[ru] && !tag[rv]) {
            upd(rv, w);
            tag[rv] = 1;
        }
        else if (!tag[ru] && tag[rv]) {
            upd(ru, w);
            tag[ru] = 1;
        }
        else if (!tag[ru] && !tag[rv]) {
            if (lst[ru].size() < lst[rv].size()) swap(ru, rv);
            for (int x : lst[rv])
                lst[ru].push_back(x);
        }

        par[rv] = ru;
        sze[ru] += sze[rv];
        return ;
    }
};

struct Edg {
    int u, v, w;
};

bool cmp(const Edg &a, const Edg &b) {
    return a.w > b.w;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("TRAVEL.INP", "r", stdin);
    freopen("TRAVEL.OUT", "w", stdout);
     
    int n, m, q;
    cin >> n >> m >> q;

    DSU dsu;
    dsu.ini(n);

    vector<Edg> edg(m);
    for (auto &e : edg)
        cin >> e.u >> e.v >> e.w;

    for (int i = 1, x; i <= n; i++) {
        cin >> x;
        dsu.pos[x] = i;
        dsu.lst[x].push_back(x);
    }

    sort(edg.begin(), edg.end(), cmp);

    for (auto &e : edg)
        dsu.uni(e.u, e.v, e.w);

    for (int i = 1; i <= n; i++)
        if (dsu.ans[i] >= 0)
            cout << dsu.ans[i] << '\n';
}
