#include <bits/stdc++.h>

using namespace std; 
const int MAXN = 2e5 + 5; 
int n, q; 
vector<int> arr;

struct node {
    int left, right; 

    long long sum; 

    node() : sum(0), left(0), right(0) {}; 
    node(long long a, int b, int c) : sum(a), left(b), right(c) {}; 
} st[40 * MAXN]; 

int idx = 0; 
int vers[MAXN];

void calc(int id) {
    st[id].sum = st[st[id].right].sum + st[st[id].left].sum;
}

int update(int old, int l, int r, int p, long long x) {
    int id = ++idx;
    st[id] = st[old];

    if (l == r) {
        st[id].sum = x;
        return id;
    }

    int mid = (l + r) >> 1;
    if (p <= mid) { 
        st[id].left = update(st[old].left, l, mid, p, x);
        st[id].right = st[old].right; 
    }
    else { 
        st[id].right = update(st[old].right, mid + 1, r, p, x);
        st[id].left = st[old].left;
    }
    calc(id);
    return id;
}

long long query_sum(int oldID, int l, int r, int a, int b) {
    if (r < a || b < l) return 0; 
    if (a <= l && b >= r) return st[oldID].sum;

    int mid = (l + r) >> 1; 
    return query_sum(st[oldID].left, l, mid, a, b) +
           query_sum(st[oldID].right, mid + 1, r, a, b); 
}

int build(int l, int r) {
    int id = ++idx; 
    if (l == r) {
        st[id] = node(arr[l], 0, 0); 
        return idx; 
    }

    int mid = (l + r) >> 1; 
    st[id].left = build(l, mid); 
    st[id].right = build(mid + 1, r); 
    calc(id); 
    return id; 
}

int num = 1; 
void copy(int oldID) {
    vers[++num] = vers[oldID]; 
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); 

    cin >> n >> q;

    arr.resize(n + 1); 
    for(int i = 1; i <= n; ++i) cin >> arr[i]; 

    vers[1] = build(1, n); 

    while(q--) {
        int test; cin >> test; 

        if (test == 1) {
            int k, a, x; 
            cin >> k >> a >> x; 

            vers[k] = update(vers[k], 1, n, a, x * 1LL); 
        }

        else if (test == 2) {
            int k, a, b; 
            cin >> k >> a >> b; 

            cout << query_sum(vers[k], 1, n, a, b) << '\n'; 
        }
        
        else {
            int k; cin >> k; 

            copy(k); 
        }
    } 
}
