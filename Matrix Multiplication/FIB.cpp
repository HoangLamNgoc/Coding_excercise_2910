#include <bits/stdc++.h>
using namespace std;

int mod;

struct matrix {
    int n, m;
    vector<vector<long long>> data;

    matrix() {}

    matrix(int r, int c) : n(r), m(c), data(r, vector<long long>(c, 0)) {}

    long long& operator()(int i, int j) {
        return data[i][j];
    }

    long long operator()(int i, int j) const {
        return data[i][j];
    }

    static matrix identity(int n) {
        matrix I(n, n);
        for(int i = 0; i < n; i++) I(i, i) = 1;
        return I;
    }

    matrix operator * (const matrix& a) const {
        matrix c(n, a.m);

        for(int i = 0; i < n; ++i)
            for(int k = 0; k < m; ++k)
                for(int j = 0; j < a.m; ++j)
                    c(i, j) = (c(i, j) + data[i][k] * a(k, j)) % mod;

        return c;
    }

    static matrix powmod(matrix a, long long b) {
        matrix res = identity(a.n);

        while (b > 0) {
            if (b & 1) res = res * a;
            a = a * a;
            b >>= 1;
        }
        return res;
    }
};

void sol() {
    long long a, b, l, r;
    cin >> a >> b >> l >> r >> mod;

    matrix M(2, 2);
    M(0, 0) = 1; M(0, 1) = 1;
    M(1, 0) = 1; M(1, 1) = 0;

    matrix x(2, 1);
    x(0, 0) = b % mod;
    x(1, 0) = a % mod;

    auto get = [&](long long n) {
        if (n == 1) return a % mod;
        if (n == 2) return b % mod;

        matrix R = matrix::powmod(M, n - 2) * x;
        return R(0, 0);
    };

    long long ans = (get(r + 2) - get(l + 1)) % mod;
    if (ans < 0) ans += mod;

    cout << ans << '\n';
}

int main() {
    freopen("FIB.INP", "r", stdin); 
    freopen("FIB.OUT", "w", stdout); 

    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int test; cin >> test;
    while (test--) sol();
}
