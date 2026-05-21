#include <bits/stdc++.h>

using namespace std; 
const int MAXN = 2e5 + 5; 
const int MAXM = 4e5 + 5; 
const int INF = 1e9 + 5; 
const int MAX_VAL = 1e6 + 5; 

struct pii {
    int p, c; 
};

struct piii {
    int tp, tc, d; 
}; 

struct piiii {
    int id; 
    int qL, qR;
    int cL, cR; 
};

int n, m; 
pii hell[MAXN];
pii hehe[MAXN]; 

int prefp[MAXN], prefc[MAXN]; 
int suffp[MAXN], suffc[MAXN]; 

piii query[MAXM];

int ans[MAXM]; 
vector<piiii> buck[MAXN]; 
vector<piiii> qe; 
vector<int> st(MAX_VAL << 2, INF); 

struct segtree {
    void upd(int id, int L, int R, int u, int val) {
        if (R < u || L > u) return; 

        if (L == R) {
            if (val == INF) st[id] = INF; 
            else st[id] = min(st[id], val); 
            return; 
        }
        
        int M = (L + R) >> 1; 
        upd(id << 1, L, M, u, val); 
        upd(id << 1 | 1, M + 1, R, u, val); 

        st[id] = min(st[id << 1], st[id << 1 | 1]); 
    }

    int que(int id, int l, int r, int u, int v) {
        if (r < u || l > v) return INF; 

        if (u <= l && r <= v) {
            return st[id]; 
        }

        int M = (l + r) >> 1; 
        return min(que(id << 1, l, M, u, v), que(id << 1 | 1, M + 1, r, u, v)); 
    }

    int que(int u, int v) {
        return que(1, 0, MAX_VAL, u, v); 
    }
} ST;

int get(int L, int R, int val) {
    if (val < L) return 0; 

    if (val < R) return val; 
    return R; 
}

//hoat dong tuong tu chat nhi phan song song 
void solve(int L, int R, vector<piiii>& que) {
    if (que.empty()) return; 
    if (L > R) return;

    if (L == R) {
        for(piiii& a : que) {
            int res = hell[L].p + hell[L].c; 
            ans[a.id] = min(ans[a.id], res); 
        }
        return; 
    }

    int M = (L + R) >> 1;

    vector<piiii> crss; 
    vector<piiii> queL; 
    vector<piiii> queR; 

    for(piiii& a : que) {
        int idx_L = a.qL; 
        int idx_R = a.qR;

        if (idx_L <= M && idx_R >= M) {
            crss.push_back(a);

            buck[idx_L].push_back(a); 
            buck[idx_R].push_back(a);
        }
        else if (idx_R < M) //bug2 : luon nho qL va qR la idx chu khong phai la gia tri
            queL.push_back(a); 
        else 
            queR.push_back(a); 
    }

    if (!crss.empty()) {
        // xu ly quet M -> L
        for(int i = M; i >= L; --i) {
            ST.upd(1, 0, MAX_VAL, hell[i].c, hell[i].c + hell[i].p);

            while(!buck[i].empty()) {
                piiii& a = buck[i].back(); 
                buck[i].pop_back(); 

                int res = ST.que(a.cL, a.cR);  
                ans[a.id] = min(ans[a.id], res); 
            }
        }

        for(int i = M; i >= L; --i) //bug1 : quen upd / init toan mang -> TLE 
            ST.upd(1, 0, MAX_VAL, hell[i].c, INF);
        
        // xu ly quet M -> R
        for(int i = M + 1; i <= R; ++i) {
            ST.upd(1, 0, MAX_VAL, hell[i].c, hell[i].c + hell[i].p); 

            while(!buck[i].empty()) {
                piiii& a = buck[i].back(); 
                buck[i].pop_back(); 

                int res = ST.que(a.cL, a.cR);  
                ans[a.id] = min(ans[a.id], res); 
            }
        }
    
        for(int i = M + 1; i <= R; ++i) 
            ST.upd(1, 0, MAX_VAL, hell[i].c, INF);
    }
    
    solve(L, M, queL); 
    solve(M + 1, R, queR); 
}

int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 

    cin >> n; 

    for(int i = 1; i <= n; ++i) { 
        cin >> hell[i].p; 
        hehe[i].p = hell[i].p; 
    }

    for(int i = 1; i <= n; ++i) { 
        cin >> hell[i].c; 
        hehe[i].c = hell[i].c; 
    }

    cin >> m; 

    for(int i = 1; i <= m; ++i) 
        cin >> query[i].tp; 

    for(int i = 1; i <= m; ++i) 
        cin >> query[i].tc; 
    
    for(int i = 1; i <= m; ++i) 
        cin >> query[i].d;

    sort(hell + 1, hell + n + 1, [](const pii& x, const pii& y){ 
        return x.p < y.p; 
    }); 

    sort(hehe + 1, hehe + n + 1, [](const pii& x, const pii& y){
        return x.c < y.c; 
    });

    prefp[0] = prefc[0] = INF; 
    suffp[n + 1] = suffc[n + 1] = INF; 
    hehe[n + 1].c = hehe[n + 1].p = INF; 

    fill_n(ans, MAXM, INF); 

    for(int i = 1; i <= n; ++i) {
        prefp[i] = min(prefp[i - 1], hell[i].c);
        prefc[i] = min(prefc[i - 1], hehe[i].p);   
    }

    for(int i = n; i >= 1; --i) {
        suffp[i] = min(suffp[i + 1], hell[i].c); 
        suffc[i] = min(suffc[i + 1], hehe[i].p);
    }

    for(int i = 1; i <= m; ++i) {
        int tpi = query[i].tp; 
        int tci = query[i].tc; 
        int di = query[i].d;

        int qL_idx = lower_bound(hell + 1, hell + 1 + n, tpi, [](const pii& x, int val) {
            return x.p < val;
        }) - hell;

        int qR_idx = lower_bound(hell + 1, hell + 1 + n, tpi + di, [](const pii& x, int val) {
            return x.p < val;
        }) - hell - 1;

        if (qL_idx <= qR_idx) {
            qe.push_back({i, qL_idx, qR_idx, tci, tci + di}); 
        }

        // xet p = 0
        pii* it = lower_bound(hell + 1, hell + 1 + n, tpi, [](const pii& x, int val) {
            return x.p < val; 
        });

        int id = it - hell; 
        if (id > 1) ans[i] = min(ans[i], 0 + get(tci, tci + di, prefp[id - 1])); 
        //bug3 : ham thi phai lay get(gia tri) chu khong phai + thang gia tri 

        // xet p = tpi + di 
        it = lower_bound(hell + 1, hell + 1 + n, tpi + di, [] (const pii& x, int val) {
            return x.p < val;
        });

        if (it != hell + 1 + n) {
            id = it - hell; 
            ans[i] = min(ans[i], tpi + di + get(tci, tci + di, suffp[id])); 
        }

        // xet c = 0 
        pii* jt = lower_bound(hehe + 1, hehe + 1 + n, tci, [](const pii& x, int val) {
            return x.c < val; 
        }); 

        id = jt - hehe; 
        if (id > 1) ans[i] = min(ans[i], get(tpi, tpi + di, prefc[id - 1])); 

        // xet c = di + tci 
        jt = lower_bound(hehe + 1, hehe + 1 + n, tci + di, [](const pii& x, int val) {
            return x.c < val; 
        }); 

        id = jt - hehe; 
        if (id <= n) ans[i] = min(ans[i], tci + di + get(tpi, tpi + di, suffc[id])); 
    }

    solve(1, n, qe); 
    
    for(int i = 1; i <= m; ++i) 
        cout << ans[i] << '\n';

    return 0;
}
