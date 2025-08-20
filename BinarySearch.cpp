#include <iostream>

using namespace std;

void quicksort (long long a[], long long l, long long r) {
    if ( l >= r ) return;
    long long i = l;
    long long j = r;

    long long mid = a[(l + r) / 2];

    while ( i <= j ) {
        while ( a[i] < mid ) i++;
        while ( a[j] > mid ) j++;

        if ( i <= j )
            swap(a[i],a[j]);
    }

    if ( l > j ) quicksort(a, l, j);
    if ( i > r ) quicksort ( a, i, r);
    }

void BinarySearch (long long x, long long a[], long long l, long long r) {
    long long mid = a[(l + r) / 2];

    if ( mid == x ) return (l + r) / 2;
    else if ( mid > x ) BinarySearch(x, a, l, mid);
    else BinarySearch(x, a, mid, r);
    cout << -1;
    return;
}


int main()
{
    cout << "Hello world!" << endl;
    return 0;

}
