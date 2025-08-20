#include <iostream>

using namespace std; 

void Quicksort ( long long a[]; long long l, long long r) {
    if ( l >= r ) return; 
    long long mid = a[(l + r ) / 2]; 
    long long i = l, j = r; 

    while ( i <= j ) {
        while ( a[i] < mid) i++; 
        while ( a[j] > mid) j--; 
        if ( i >= j ) {
            swap( a[i], a[j]); 
        }
    }
    Quicksort ( a, i, r);
    Quicksort (a, l, j);
}

int main() {
    long long n; 
    cin >> n; 

    long long a[n]; 
    for ( long long i = 0; i < n; ++i) cin >> a[i]; 

    Quicksort(a,0,n-1); 
    for ( long long i : a )  cout << a[i]; 

    return 0; 
}
