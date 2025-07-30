#include <bits/stdc++.h>
 
using namespace std;
 
vector <long long> Vector;
 
void algorithm ( long long n ) {
    if ( n == 1) {
        Vector.push_back(1);
        return ;
    }
 
    if ( n % 2 == 0 ) {
        Vector.push_back(n);
        n /= 2;
    }
    else {
        Vector.push_back(n);
        n = n * 3 + 1;
    }
 
    if ( n < 1) return;
    else algorithm (n);
}
 
 
int main() {
    long long n;
    cin >> n;
    algorithm(n);
    for ( int i = 0; i < Vector.size(); ++i ) {
        cout << Vector[i] << " " ;
    }
    return 0;
}
