#include <bits/stdc++.h>

using namespace std; 
const int MAXN = 1e6 + 5; 

struct segtree {
    struct nodes {
        long long sum; // f[i]; 
        long long cnt; // số dãy nếu d[i] = 1; 

        int a1, a0; // a0: lazy khi flip = 0, a1 : lazy khi flip = 1; 
        // a0 ton tai la de flip, 
        //neu de y thi trong ham a_val minh gan nhu khong bao gio +a0, vi khi them r moi thi chi co d[i] = 1 moi bi anh huong

        bool flip; // tung tung tung sahur cả dãy lên 
    } st[MAXN << 2];

    // push flop
    void a_flip(int id, int l, int r) { // 1 cai ham dao dau :) khong co gi dang noi 
        st[id].cnt = r - l + 1 - st[id].cnt;  
        swap(st[id].a0, st[id].a1); 

        st[id].flip ^= 1; // flop qua thi cung phai tro minh thoi (thinh cuc at suy, suy cuc tat thinh) 
    }

    // ham nay push_lazy th, khong co gi dang noi 
    void a_val(int id, int l, int r, int a0, int a1) {
        int len = r - l + 1; 

        st[id].sum += st[id].cnt * a1; 
        st[id].sum += (len - st[id].cnt) * a0; 

        st[id].a0 += a0; 
        st[id].a1 += a1;
    }

    void push(int id, int l, int r) { // push _ lazy 
        bool& t = st[id].flip; 

        int mid = (l + r) >> 1;  // deo biet noi gi, bug la cc 
        int L = id << 1; 
        int R = id << 1 | 1; 

        if (t) { // upd flop > val 
            a_flip(L, l, mid);
            a_flip(R, mid + 1, r); 
            t = 0; 
        }

        int& a0 = st[id].a0; 
        int& a1 = st[id].a1; 

        if (a0 || a1) { //co flop thi moi co tk nay chu :)) lam gi vay troi 
            a_val(L, l, mid, a0, a1);        
            a_val(R, mid + 1, r, a0, a1);
            a0 = a1 = 0;  //day lazy xuong con, xong roi thi cut 
        }
    }   

    void pull(int id) {

        int L = id << 1; 
        int R = id << 1 | 1; 
        
        st[id].sum = st[L].sum + st[R].sum; 
        st[id].cnt = st[L].cnt + st[R].cnt; 
    }

    void upd_flip(int id, int l, int r, int u, int v) {
        if (v < l || u > r) return; 

        if (u <= l && r <= v) {
            a_flip(id, l, r); 
            return; 
        }

        push(id, l, r); 

        int L = id << 1; 
        int R = id << 1 | 1; 
        int mid = (l + r) >> 1; 

        upd_flip(L, l, mid, u, v); 
        upd_flip(R, mid + 1, r, u, v); 

        pull(id); 
    }

    void upd_add(int id, int l, int r, int u, int v, int a0, int a1) {
        if (v < l || u > r) return; 

        if (u <= l && r <= v) {
            a_val(id, l, r, a0, a1); 
            return; 
        }

        push(id, l, r); 

        int L = id << 1; 
        int R = id << 1 | 1; 
        int mid = (l + r) >> 1; 

        upd_add(L, l, mid, u, v, a0, a1); 
        upd_add(R, mid + 1, r, u, v, a0, a1); 

        pull(id); 
    } 

    long long query(int id, int l, int r, int u, int v) {
        if (v < l || u > r) return 0; 

        if (u <= l && r <= v)  
            return st[id].sum; 
        
        push(id, l, r); 

        int L = id << 1; 
        int R = id << 1 | 1; 
        int mid = (l + r) >> 1; 

        long long get1 = query(L, l, mid, u, v); 
        long long get2 = query(R, mid + 1, r, u, v); 

        return get1 + get2; 
    }
} seg; 

struct que {
    int id, l, r;
    long long ans = 0;  
}; 

vector<int> arr, last; 
vector<que> qs; 

int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 

    int n; cin >> n; 

    arr.assign(n + 1, 0);
    last.assign(MAXN + 1, 0); 
    for(int i = 1; i <= n; ++i) cin >> arr[i]; 

    int q; cin >> q; 

    for(int i = 0, l, r; i < q; ++i) {
        cin >> l >> r; 

        qs.push_back({i, l, r, 0}); 
    }

    sort(qs.begin(), qs.end(), [] (const que& x, const que& y) {
        return x.r < y.r; 
    });

    int cur = 0; 
    for(int i = 1; i <= n; ++i) {
        int val = last[arr[i]]; 

        seg.upd_flip(1, 1, n, val + 1, i); 
        seg.upd_add(1, 1, n, 1, i, 0, 1); 

        while (cur < q && qs[cur].r == i) {
            qs[cur].ans = seg.query(1, 1, n, qs[cur].l, i); 
            ++cur; 
        }

        last[arr[i]] = i; 
    }

    sort(qs.begin(), qs.end(), [] (const que& x, const que& y) {
        return x.id < y.id; 
    });

    for(int i = 0; i < q; ++i) cout << qs[i].ans << ' '; 
}
