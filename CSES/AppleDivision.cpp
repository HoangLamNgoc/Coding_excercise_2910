#include <iostream> 
#include <vector> 
#include <cmath> 
#include <array> 

using namespace std; 

void quicksort(long long a[], long long l, long long r) {
	if ( l >= r ) return; 

	long long i = l, j = r; 
	long long mid = a[(l + r ) / 2];

	while ( i <= j ) {
		while ( a[i] > mid ) i++; 
		while ( a[j] < mid ) --j; 

		if (i <= j) {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }

	quicksort(a, l, j);
	quicksort(a, i, r);
}
	

int main() {
    int n; 
    cin >> n; 

    int a[n]; 
    for ( int i : a ) cin >> a[i]; 
	quicksort(a, 0, n - 1); 

	long long cnt1 = 0; 
	long long cnt2 = 0; 

	for (int x : a) {
	    if (cnt1 <= cnt2) cnt1 += x;
	    else cnt2 += x;
	}

	cout << abs( cnt1 - cnt2) << endl; 
	return 0; 
}

    
    
