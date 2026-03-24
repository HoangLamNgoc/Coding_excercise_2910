#include <bits/stdc++.h>
using namespace std;

const long long MOD = 998244353;

struct matrix {
    int n, m;
    vector<vector<long long>> data;

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
        for(int i = 0; i < n; i++)
            for(int k = 0; k < m; k++)
                for(int j = 0; j < a.m; j++)
                    c(i,j) = (c(i,j) + data[i][k] * a(k,j)) % MOD;
        return c;
    }

    static matrix powmod(matrix a, long long b) {
        matrix res = identity(a.n);
        while(b) {
            if(b & 1) res = res * a;
            a = a * a;
            b >>= 1;
        }
        return res;
    }
};

void sol() {
    long long n;
    cin >> n;

    matrix M(2, 2);
    M(0, 0) = 1; M(0, 1) = 1;
    M(1, 0) = 1; M(1, 1) = 0;

    matrix R = matrix::powmod(M, n);

    long long fn = R(0, 1);  
    long long fn1 = R(0, 0);  

    cout << (fn * fn1) % MOD << '\n';
}

int main() {

    freopen("FIBSQR.INP", "r", stdin);
    freopen("FIBSQR.OUT", "w", stdout); 
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    sol();
}
