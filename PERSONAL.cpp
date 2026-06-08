#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
vector<int> sub[MAXN];

struct SUB {
    int prob_id; // bai thu may ? (1 -> n)
    int local_j; // Subtask thu may? (1 -> k_i)
    int val;
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("personal.inp", "r", stdin);
    freopen("personal.out", "w", stdout);

    int n, S;
    cin >> n >> S;

    vector<SUB> subs;

    for (int x, y, i = 1; i <= n; ++i) {
        cin >> x;
        for (int j = 1; j <= x; ++j) {
            cin >> y;
            sub[i].emplace_back(y);
            subs.push_back({i, j, y});
        }
    }

    int M = (int)subs.size();

    vector<char> dec(M * (S + 1), 0);
    vector<bool> dp(S + 1, 0);

    dp[0] = 1;
    int id = 0;

    for (int i = 1; i <= n; ++i) {
        vector<bool> ndp(S + 1, 0);
        int k = (int)sub[i].size();

        for (int j = 0; j < k; ++j) {
            int cur = sub[i][j];

            for (int s = S; s >= cur; --s) {
                if (dp[s - cur]) {
                    ndp[s] = 1;
                    dp[s] = 1;
                    dec[id * (S + 1) + s] = 1;
                }
            }
            ++id;
        }
        dp = move(ndp);
    }

    if (dp[S]) {
        cout << "Yes\n";

        vector<vector<int>> ans(n + 1);
        int cur_s = S;

        for (int f = M - 1; f >= 0; --f) {
            if (dec[f * (S + 1) + cur_s]) {
                ans[subs[f].prob_id].push_back(subs[f].local_j);
                cur_s -= subs[f].val;
            }
        }

        for (int i = 1; i <= n; ++i) {
            cout << ans[i].size() << ' ';
            reverse(ans[i].begin(), ans[i].end());

            for (int& j : ans[i])
                cout << j << ' ';
            cout << "\n";
        }
    } else
        cout << "No\n";

    return 0;
}
