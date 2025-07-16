# include <bits/stdc++.h>

using namespace std ;

const int maxn = 200005 ;
bool is_prime[maxn]; 
void sieve(int n){
    for (int i = 2; i <= n; i++)
        is_prime[i] = true;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i * 2; j <= n; j += i)
                is_prime[j] = false;
        }
    }
}

int main () { 
    int a , b ; 
    cin >> a >> b ; 
    sieve (b) ; 
    for ( int i = a ; i <= b ; i++) {
        if (is_prime[i]) cout << i << endl ; 
    }
    return 0 ; 
}
