#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 2e5 + 5;
const int LOG = 30; 

int n, q;
int par[LOG][MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;

    for (int i = 1; i <= n; ++i) {
        cin >> par[0][i];
    }

    for (int j = 1; j < LOG; ++j) {
        for (int i = 1; i <= n; ++i) {
            int mid = par[j - 1][i];
            par[j][i] = par[j - 1][mid];
        }
    }
    while (q--) {
        int u, k;
        cin >> u >> k;
        for (int bit = 0; bit < LOG; ++bit) {
            if (u == 0) break;         
            if (k & (1 << bit))
                u = par[bit][u];        
        }
        cout << u << '\n';
    }

    return 0;
}
