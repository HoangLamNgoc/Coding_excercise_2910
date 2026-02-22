#include <iostream>
#include <algorithm>
#include <vector>

// update vị trí u thành giá trị v
// tính tổng [u, v]
using namespace std; 

int n; 

    vector<long long> sum; 

    long long get_sum(int u) {
        long long res = 0; 
        while (u > 0) {
            res += sum[u]; 
            u -= (u & -u); 
        }
        return res; 
    }

    void update(int u, int val) {
        int x = u; 
        while (x <= n) {
            sum[x] += val; 
            x += (x & -x); 
        }
    }

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); 

    int q; 
    cin >> n >> q; 

    sum.assign(n + 1, 0); 
    vector<int> arr(n + 1, 0); 
    for(int i = 1; i <= n; ++i) {
        int a; 
        cin >> a; 

        arr[i] = a; 
        update(i, a);
    }

    while (q--) {
        int t, u, v; 
        cin >> t >> u >> v; 

        if (t == 1) {
            update(u, -arr[u]); 
            update(u, v);
            arr[u] = v; 
        } 
        else cout << get_sum(v) - get_sum(u - 1) << '\n';
    }
}
