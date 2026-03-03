#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100000 + 5;

struct Node {
    int left, right;
    int val;
} st[40 * MAXN];

int n, m;
int idx = 0;
int root[MAXN];        
vector<int> comp;      

int update(int oldID, int l, int r, int pos) {
    int id = ++idx;
    st[id] = st[oldID];         

    if (l == r) {
        st[id].val++;            
        return id;
    }

    int mid = (l + r) >> 1;

    if (pos <= mid)
        st[id].left = update(st[oldID].left, l, mid, pos);
    else
        st[id].right = update(st[oldID].right, mid+1, r, pos);

    st[id].val = st[st[id].left].val + st[st[id].right].val;
    return id;
}

int kth(int Lnode, int Rnode, int l, int r, int k) {
    if (l == r) return l;

    int mid = (l + r) >> 1;

    int cl = st[st[Rnode].left].val - st[st[Lnode].left].val;

    if (cl >= k)
        return kth(st[Lnode].left, st[Rnode].left, l, mid, k);
    else
        return kth(st[Lnode].right, st[Rnode].right, mid + 1, r, k - cl);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    vector<int> a(n+1);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        comp.push_back(a[i]);
    }

    sort(comp.begin(), comp.end());
    comp.erase(unique(comp.begin(), comp.end()), comp.end());

    root[0] = 0;

    for (int i = 1; i <= n; i++) {
        int pos = lower_bound(comp.begin(), comp.end(), a[i]) - comp.begin() + 1;
        root[i] = update(root[i-1], 1, comp.size(), pos);
    }

    while (m--) {
        int l, r, k;
        cin >> l >> r >> k;

        int id = kth(root[l - 1], root[r], 1, comp.size(), k);

        cout << comp[id - 1] << "\n";
    }
}
