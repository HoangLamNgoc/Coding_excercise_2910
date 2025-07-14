#include <bits/stdc++.h>

using namespace std; 

vector <long long> Factors(long long n) { 
    vector <long long> even_factors ; 
    for ( long long i = 1 ; i * i <= n ; ++i ) { 
       if (n % i == 0) {
            if (i % 2 == 0) even_factors.push_back(i);
            long long j = n / i;
            if (j != i && j % 2 == 0) even_factors.push_back(j);
        }
    }
    return even_factors ; 
}
int main () {
    long long num ; 
    cin >> num ; 
    vector <long long> even_factors = Factors(num) ; 
    cout << accumulate ( even_factors.begin() , even_factors.end() , 0) ; 
    return 0 ; 
}
