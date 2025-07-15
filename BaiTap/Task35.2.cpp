#include <bits/stdc++.h>
using namespace std;

double average_even_digit(long long n) {
    long long sum = 0, count = 0;
    while (n > 0) {
        long long d = n % 10;
        if (d % 2 == 0) {
            sum += d;
            count++;
        }
        n /= 10;
    }
    if (count == 0) return -1;
    return (double)sum / count;
}

int main() {
    int n;
    cin >> n;
    double res = average_even_digit(n);
    if (res == -1) cout << -1;
    else cout << fixed << setprecision(2) << res;
    return 0;
}
