#include <bits/stdc++.h>

using namespace std; 
const int MAXN = 1e5 + 5; 

struct segtree {

    struct node {
        int cover;
        long long len;
    };

    vector<node> st;
    int n;

    void init(int _n) {
        n = _n;
        st.assign(4 * n + 5 , {0, 0});
    }

    void push(int id, int l, int r) {
        if(st[id].cover > 0) 
            st[id].len = r - l + 1;

        else if(l == r) 
            st[id].len = 0;
        
        else 
            st[id].len = st[id << 1].len + st[id << 1 | 1].len;
    }

    void update(int id, int l, int r, int u, int v, int val) {

        if(v < l || r < u) return;

        if(u <= l && r <= v) {
            st[id].cover += val;
            push(id, l, r);
            return;
        }

        int mid = (l + r) >> 1;

        update(id << 1, l, mid, u, v, val); 
        update(id << 1 | 1, mid + 1, r, u, v, val);

        push(id, l, r);
    }

    void update(int l, int r, int val) {
        update(1, 1, n, l, r, val);
    }

    long long query() {
        return st[1].len;
    }
} fw;

struct events {
    int x, y1, y2;
    int type;  
 
    bool operator< (const events& other) const {
        return (x < other.x) || (x == other.x && type < other.type); 
    }
}; 
 
struct seg {
    int a, b, c; 
}; 
 
vector<events> ev; 

int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0);
 
    int n; cin >> n; 
    fw.init(MAXN); 
 
    for(int i = 0; i < n; ++i) {
        int x1, y1, x2, y2; 
        cin >> x1 >> y1 >> x2 >> y2;

        ev.push_back({x1, y1, y2, 1});
        ev.push_back({x2, y1, y2, -1}); 
    }
 
    sort(ev.begin(), ev.end()); 
 
    long long ans = 0; 
    
    int m = ev.size(); 
    for(int i = 0; i < m - 1; ++i) {
        events e = ev[i]; 
        fw.update(e.y1, e.y2 - 1, e.type); 
        ans += (ev[i + 1].x - e.x) * fw.query(); 
    }
    
    cout << ans << '\n'; 
}
