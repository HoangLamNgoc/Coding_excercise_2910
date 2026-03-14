#include <bits/stdc++.h>

using namespace std; 
const int MAXN = 200000 + 5; 
#define int long long 

struct segtree {

    struct node {
        int mx;
        int lazy;
    };

    vector<node> st;
    int n;

    void init(int _n) {
        n = _n;
        st.assign(4 * n + 5 , {0, 0});
    }

    void push(int id) {
        if(st[id].lazy) {

            int v = st[id].lazy;

            st[id << 1].mx += v;
            st[id << 1 | 1].mx += v;

            st[id << 1].lazy += v;
            st[id << 1 | 1].lazy += v;

            st[id].lazy = 0;
        }
    }

    void update(int id, int l, int r, int u, int v, int val) {

        if(v < l || r < u) return;

        if(u <= l && r <= v) {
            st[id].mx += val;
            st[id].lazy += val;
            return;
        }

        push(id);

        int mid = (l + r) >> 1;

        update(id << 1, l, mid, u, v, val); 
        update(id << 1 | 1, mid + 1, r, u, v, val);

        st[id].mx = max(st[id << 1].mx, st[id << 1 | 1].mx);
    }

    void update(int l, int r, int val) {
        update(1, 1, n, l, r, val);
    }

    int query() {
        return st[1].mx;
    }

} fw;

struct events {
    long long x;
    int y1, y2;
    int type;  

    bool operator< (const events& other) const {
        return (x < other.x) || (x == other.x && type < other.type); 
    }
}; 
 
vector<events> ev; 

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0);

    int n; 
    long long k;

    cin >> n >> k; 

    fw.init(MAXN); 

    for(int i = 0; i < n; ++i) {

        int x, y; 
        cin >> x >> y;

        ev.push_back({x, y, y + k, 1});
        ev.push_back({x + k + 1, y, y + k, -1}); 
    }
 
    sort(ev.begin(), ev.end()); 

    int ans = 0; 

    for(events e : ev) {

        fw.update(e.y1, e.y2, e.type); 
        ans = max(ans, fw.query());
    }
    
    cout << ans << '\n'; 
}
