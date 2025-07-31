#include <bits/stdc++.h>

using namespace std;

int main(){
    long long n;
    cin >> n;
    long long a[n];

    for ( int i = 0; i < n - 1 ; ++i ) cin >> a[i];

    long long tong = n * ( n + 1) / 2 ;
    for ( int i = 0; i < n - 1 ; ++i ) tong -= a[i];

    cout << tong << endl;
    return 0;
}
