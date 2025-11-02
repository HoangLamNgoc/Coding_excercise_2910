#include <iostream>
#include <vector>

using namespace std;

const long long oo = 4e18;
int n, m;

void floydwarshall(vector<vector<long long>>& w, vector<vector<long long>>& d) {
    d = w;

    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            if (d[i][k] == oo) continue;
            for (int j = 1; j <= n; ++j) {
                if ( d[i][j] > d[i][k] + d[k][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                    d[j][i] = d[i][k] + d[k][j];
                }
            }
        }
    }
}

int main() {
    cin >> n >> m;
    int q; cin >> q;

    vector<vector<long long>> w1(n + 1, vector<long long>(n + 1, oo));
    for (int i = 1; i <= n; ++i) w1[i][i] = 0;

    for (int i = 0; i < m; ++i) {
        long long u, v, w;
        cin >> u >> v >> w;
        w1[u][v] = min(w, w1[u][v]);
        w1[v][u] = min(w, w1[u][v]);
    }

    vector<vector<long long>> d(n + 1, vector<long long>(n + 1, oo));

    floydwarshall(w1, d);

    while (q--) {
        long long u, v;
        cin >> u >> v;
        if (d[u][v] >= oo / 2)
            cout << "-1\n";
        else
            cout << d[u][v] << '\n';
    }
}
