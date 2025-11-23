#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 505;
const int oo = 1e9;
long long dp[MAXN][MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b;
    cin >> a >> b;

    for (int i = 0; i <= a; ++i)
        for (int j = 0; j <= b; ++j)
            dp[i][j] = (i == j ? 0 : oo);

    for (int i = 1; i <= a; ++i) {
        for (int j = 1; j <= b; ++j) {
            if (i == j) continue;
            for (int k = 1; k < i; ++k)
                dp[i][j] = min(dp[i][j], dp[k][j] + dp[i - k][j] + 1);

            for (int k = 1; k < j; ++k)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j - k] + 1);
        }
    }

    cout << dp[a][b];
}
