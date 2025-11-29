#include <iostream>

using namespace std;

const int MAXN = 20;
long long dp[MAXN][11][2][2]; 
int x[MAXN];

long long f(int idx, int one, bool smaller, bool leading) {
    if (idx < 0) return 1; 

    long long &memo = dp[idx][one+1][smaller][leading];
    if (memo != -1) return memo;

    long long ans = 0;
    int lim = smaller ? 9 : x[idx];

    for (int digit = 0; digit <= lim; ++digit) {
        if (!leading && digit == one) continue; 
        bool next_leading = leading && digit == 0; 
        ans += f(idx-1, next_leading ? -1 : digit, smaller || (digit < lim), next_leading);
    }

    return memo = ans;
}

long long G(long long X) {
    if (X < 0) return 0;
    if (X == 0) return 1;

    int n = 0;
    while (X > 0) {
        x[n++] = X % 10; 
        X /= 10;
    }

    for (int i = 0; i < MAXN; ++i) {
        for (int j = 0; j < 11; ++j) {
            for (int k = 0; k < 2; ++k) {
                for (int l = 0; l < 2; ++l) {
                    dp[i][j][k][l] = -1;
                }
            }
        }
    }

    return f(n-1, -1, 0, 1); 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long long a, b;
    cin >> a >> b;

    cout << G(b) - G(a-1) << "\n";
}
