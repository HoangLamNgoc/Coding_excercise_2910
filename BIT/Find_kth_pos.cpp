#include <iostream>
#include <vector>
 
using namespace std;
 
vector<int> bit;
vector<int> a;
int n;
 
void update(int i, int val) {
    int idx = i;
    while (idx <= n) {
        bit[idx] += val;
        idx += (idx & -idx);
    }
}
 
int find_kth_cdjv(int cur) {
    int pos = 0;
    int k1 = cur;
 
    for (int pw = (1 << 18); pw >= 1; pw >>= 1) {
        if (pos + pw <= n && bit[pos + pw] < k1) {
            k1 -= bit[pos + pw];
            pos += pw;
        }
    }
    return pos + 1;
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    cin >> n;
 
    a.assign(n + 1, 0);
    bit.assign(n + 1, 0);
 
    for (int i = 1; i <= n; ++i) cin >> a[i];
 
    for (int i = 1; i <= n; ++i) update(i, 1);
 
    for (int i = 1; i <= n; ++i) {
        int p;
        cin >> p;
 
        int pos = find_kth_cdjv(p);
 
        cout << a[pos] << ' ';
 
        update(pos, -1); 
    }
}
