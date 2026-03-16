#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MAXN = 300000 + 5;

int n, q;

struct fenwick {
    vector<int> bit;

    void init() {
        bit.assign(MAXN + 5, 0);
    }

    void upd(int id) {
        for (; id <= MAXN; id += (id & -id))
            bit[id]++;
    }

    int get(int id) {
        int s = 0;
        for (; id > 0; id -= (id & -id))
            s += bit[id];
        return s;
    }
};

struct Query {
    int x, y, id;
};

vector<pair<int,int>> add[MAXN];
vector<Query> ask[MAXN];

vector<pair<int,int>> addx[MAXN];
vector<pair<int,int>> askx[MAXN];

int ans[MAXN];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;

    fenwick fx, fy;
    fx.init();
    fy.init();

    for(int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;

        add[x + y].push_back({x, y});
        addx[x].push_back({y, 0});
    }

    for(int i = 1; i <= q; i++) {
        int x, y, d;
        cin >> x >> y >> d;

        int s = x + y + d;

        ask[s].push_back({x, y, i});
        askx[x - 1].push_back({y - 1, i});
    }

    int cnt = 0;

    for(int i = 1; i <= MAXN - 1; i++) {

        for(auto &j : add[i]) {
            cnt++;
            fx.upd(j.first);
            fy.upd(j.second);
        }

        for(auto &j : ask[i]) {
            int x = j.x;
            int y = j.y;
            int id = j.id;

            ans[id] = cnt;
            ans[id] -= fx.get(x - 1);
            ans[id] -= fy.get(y - 1);
        }
    }

    fenwick fxx;
    fxx.init();

    for(int i = 1; i <= MAXN - 1; i++) {

        for(auto &j : addx[i])
            fxx.upd(j.first);

        for(auto &j : askx[i]) {
            int y = j.first;
            int id = j.second;

            ans[id] += fxx.get(y);
        }
    }

    for(int i = 1; i <= q; i++)
        cout << ans[i] << "\n";
}
