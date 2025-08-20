#include <iostream>

using namespace std;

void SelectionSort (long long a[],long long n, long long l) {
    for ( long long i = l; i < n; ++i) {
        long long min = i;
        for ( j = i + 1; j < n ; ++j ) {
            if ( a[i] < a[j] )
                min = j;
        }
        swap(a[i],a[min]);
    }
}

int main() {
    long long n;
    cin >> n;

    long long a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    SelectionSort(a, 0);
    cout << a[0] << endl;
    return 0;
}
