#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <numeric> 

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 20;

static int overlap[MAXN][MAXN];
static int dp[1 << MAXN][MAXN];
static int par[1 << MAXN][MAXN];

int lps(string s, string t) {
    string str = s + "#" + t;
    int n = str.size();
    vector<int> pi(n, 0);

    for (int i = 1, j = 0; i < n; ++i) {
        while (j > 0 && str[i] != str[j])
            j = pi[j - 1];
        if (str[i] == str[j]) ++j;
        pi[i] = j;
    }
    return pi.back();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<string> s(n);
    for (int i = 0; i < n; ++i)
        cin >> s[i];

    sort(s.begin(), s.end(), [](const string &a, const string &b) {
        if (a.size() != b.size()) return a.size() > b.size();
        return a < b;
    });

    vector<string> t;
    for (int i = 0; i < n; ++i) {
        bool ok = true;
        for (int j = 0; j < i; ++j) {
            if (s[j].find(s[i]) != string::npos) {
                ok = false;
                break;
            }
        }
        if (ok) t.push_back(s[i]);
    }
    s = t;
    n = s.size();


    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            overlap[i][j] = lps(s[j], s[i]);

    int FULL = 1 << n;
    for (int mask = 0; mask < FULL; ++mask) {
        for (int i = 0; i < n; ++i) {
            dp[mask][i] = INF;
            par[mask][i] = -1;
        }
    }

    for (int i = 0; i < n; ++i) {
        dp[1 << i][i] = (int)s[i].size();
        par[1 << i][i] = -1;
    }

    for (int mask = 1; mask < FULL; ++mask) {
        for (int i = 0; i < n; ++i) {
            if (!(mask & (1 << i))) continue; 
            if (dp[mask][i] == INF) continue;

            for (int j = 0; j < n; ++j) {
                if (mask & (1 << j)) continue;
                int nmask = mask | (1 << j);

                int cost = dp[mask][i] + (int)s[j].size() - overlap[i][j];
            
                if (dp[nmask][j] > cost) {
                    dp[nmask][j] = cost;
                    par[nmask][j] = i;
                }
            }
        }
    }

    int mask = FULL - 1;
    int best = 0;
    for (int i = 1; i < n; ++i)
        if (dp[mask][i] < dp[mask][best])
            best = i;

    vector<int> order;
    
    for (int v = best; v != -1;) {
        order.push_back(v);
        int rev = v; 
        v = par[mask][v]; 
        mask ^= (1 << rev); 
    }

    reverse(order.begin(), order.end());


    string res = s[order[0]];

    for (int i = 1; i < (int)order.size(); ++i) 
        res += s[order[i]].substr(overlap[order[i - 1]][order[i]]);

    cout << res << '\n';
    return 0;
}
