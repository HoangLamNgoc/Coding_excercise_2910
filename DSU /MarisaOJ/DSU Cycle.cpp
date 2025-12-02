#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct DSU {
    int n;
    vector<int> par;

    void init(int n_) {
        n = n_;
        par.resize(n + 2);
        for (int i = 1; i <= n+1; i++)
            par[i] = i;
    }

    int find_root(int v) {
        if (v > n) v = 1;
        return par[v] == v ? v : par[v] = find_root(par[v]);
    }

    void erase_slot(int v) {
        int nxt = v + 1;
        if (nxt > n) nxt = 1;
        par[v] = nxt;  
    }
} dsu;

int main(){
    int n; 
    cin >> n;
    dsu.init(n);

    for(int i = 1; i <= n; i++){
        int a;
        cin >> a;
        int slot = dsu.find_root(a);
        cout << slot << " ";
        dsu.erase_slot(slot);
    }
}

/* gọi par[u] là đỉnh gần nhất còn trống chỗ */
