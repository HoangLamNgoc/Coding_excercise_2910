#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
const long long INF = 4e18;

struct SegTree {
    long long st[MAXN << 2];

    void init() {
        fill(st, st + (MAXN << 2), INF);
    }

    void update(int id, int l, int r, int pos, long long val) {
        if (l == r) {
            st[id] = val;
            return;
        }
        int mid = (l + r) >> 1;
        if (pos <= mid) update(id << 1, l, mid, pos, val);
        else update(id << 1 | 1, mid + 1, r, pos, val);
        st[id] = min(st[id << 1], st[id << 1 | 1]);
    }

    long long query(int id, int l, int r, int u, int v) {
        if (u > v || v < l || r < u) return INF;
        if (u <= l && r <= v) return st[id];
        int mid = (l + r) >> 1;
        return min(query(id << 1, l, mid, u, v), query(id << 1 | 1, mid + 1, r, u, v));
    }
} seg;

struct Radio {
    long long t;
    int a, b, c, d;
};

struct Event {
    int x;
    int id;
    int type; 

    bool operator<(const Event& other) const {
        if (x != other.x) return x < other.x;
        return type > other.type; 
    }
};

int n;
Radio rad[MAXN];
long long distv[MAXN];
vector<Event> ev;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	
	cin >> n; 

    seg.init();
    for (int i = 1; i <= n; ++i) {
        cin >> rad[i].t >> rad[i].a >> rad[i].b >> rad[i].c >> rad[i].d;
        distv[i] = INF;
        ev.push_back({rad[i].c, i, 1});
        ev.push_back({rad[i].d, i, -1});
    }

    sort(ev.begin(), ev.end());

    distv[1] = 0;
    int j = 0;

    for (int i = 1; i <= n; ++i) {
        while (j < (int)ev.size() && ev[j].x == i && ev[j].type == 1) {
            int id = ev[j].id;
            if (distv[id] != INF) {
                seg.update(1, 1, n, id, distv[id] + rad[id].t - id);
            }
            j++;
        }

        if (i == 1) {
            if (rad[1].c <= 1 && rad[1].d >= 1) {
                seg.update(1, 1, n, 1, distv[1] + rad[1].t - 1);
            }
        } else {
            long long best = seg.query(1, 1, n, rad[i].a, rad[i].b);
            if (best < INF) {
                distv[i] = best + rad[i].t + i;
                if (rad[i].c <= i && rad[i].d >= i) {
                    seg.update(1, 1, n, i, distv[i] + rad[i].t - i);
                }
            }
        }

        while (j < (int)ev.size() && ev[j].x == i && ev[j].type == -1) {
            seg.update(1, 1, n, ev[j].id, INF);
            j++;
        }
    }

    for (int i = 2; i <= n; ++i) {
        if (distv[i] >= INF) cout << -1 << " ";
        else cout << distv[i] << " ";
    }
    cout << endl;

    return 0;
}
