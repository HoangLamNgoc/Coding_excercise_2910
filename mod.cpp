#include <bits/stdc++.h>

using namespace std; 
const long long MAXN = 1e6 + 5; 

long long mod; 
//C(k, n - 1) * m * (m - 1) ^ k

long long mux(long long a, long long b) {
    long long ret = 1; 

    while (b) {
        if (b & 1) ret = (ret * a) % mod; 
        a = (a * a) % mod; 
        b >>= 1; 
    }
    return ret; 
}

vector<long long> isprime; 
bool prime[MAXN]; 
void sieve() {
    for(long long i = 2; i < MAXN; ++i) {
        if (!prime[i]) {
            isprime.push_back(i);

            for(long long j = i * i; j < MAXN; j += i) 
                prime[j] = 1; 
        } 
    }
}

//Do phuc tap chuan bi : O(n)
//Do phuc tap truy van : O(n)
//KHONG can MOD NGUYEN TO 
// n <= 1e7 
long long calc(long long p, long long n) {
    long long ans = 0; 
    long long cur = p; 
    while (n / p) {
        ans += n / p; 
        p *= cur; 
    }
    return ans; 
}

long long fact[MAXN]; 
long long finv[MAXN]; 

void pre() {
    fact[0] = 1;  
    for(int i = 1; i < MAXN; ++i) 
        fact[i] = (fact[i - 1] * i) % mod;

    finv[MAXN - 1] = mux(fact[MAXN - 1], mod - 2); 
    for(int i = MAXN - 2; i >= 0; --i) 
        finv[i] = (finv[i + 1] * (i + 1)) % mod;
}

//DPT chuan bi : O(n)
//DPT truy van : O(k)
//mod la so nguyen to >k
//k <= 1e6 && n <= 1e18
long long C(long long n, long long k) {
    if (k == 0) return 1; 
    if (n == k) return 1; 
    if (n < k) return 0; 

    long long cur = 1; 
    for(long long i = n; i >= n - k + 1; --i) 
        cur = (cur * i) % mod; 
    return cur * finv[k] % mod; 
}

//Chi ap dung duoc cho P nguyen to va >n 
//Ap dung fermat nho
//Do phuc tap tien xu ly  O(n) -> n, k <= 1e7
long long c(long long n, long long k) {
        if (k == 0) return 1; 
    if (n == k) return 1; 
    if (n < k) return 0; 
    return fact[n] * finv[k] % mod * finv[n - k] % mod; 
}

int main() {
    // freopen("flowers.inp", "r", stdin);
    // freopen("flowers.out", "w", stdout); 
    
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 

    int t;
    long long p; 
    cin >> t >> p; 
    mod = p;

    long long n, m, k; 
    sieve();  
    pre();

    if (t > 50) {
        while (t--) {
            cin >> n >> m >> k; 
            long long cur = (m % mod) * mux(m - 1, k) % mod; 
            cout << cur * c(n - 1, k) % mod << '\n'; 
        }  
    }

    else {
        while (t--) {
            cin >> n >> m >> k; 
            
            long long cur = (m % mod) * mux(m - 1, k) % mod; 

            if (p == 998244353) 
                cout << C(n - 1, k) * cur % mod << '\n'; 
            else {
                //Tinh C(k, n) bang phan tich thua so nguyen to
                long long ret = 1; 
                for(long long j : isprime) {
                    if (j >= n) break; 

                    long long temp = calc(j, n - 1); 
                    long long div = calc(j, n - k - 1) + calc(j, k);
                    ret = (ret * mux(j, temp - div)) % mod;  
                }    
                cout << ret * cur % mod << '\n'; 
            }
        }
    }

}
