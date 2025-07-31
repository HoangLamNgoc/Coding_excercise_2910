#include <iostream>
using namespace std;

int main() {
    long long n;
    cin >> n;

    long long a[n];
    long long dem = 0;

    for (long long i = 0; i < n; ++i) cin >> a[i];

    for (long long i = 1; i < n; ++i) {
        if (a[i] < a[i - 1]) {
            dem += a[i - 1] - a[i];
            a[i] = a[i - 1];
        }
    }

    cout << dem;
    return 0;
}
