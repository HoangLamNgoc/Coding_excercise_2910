#include <iostream>
#include <cmath>

using namespace std;

long long Sol(int n) {
    long long res = 1;
    while ( n % 2 == 0 ) {
        n /= 2;
        res *= 2;
    }
    return res;
}

int main() {
    int n;
    cin >> n;


    int log1 = (int)log2(n);

    if ( log1 == log2(n)) {
        cout << 0 << endl;
        cout.flush();
    }

    else {
        long long res = Sol(n);
        cout << res << endl;
        n -= res;
    }

    while ( n > 0 ) {
        int c;
        cin >> c;
        n -= c;

        long long res = Sol(n);
        cout << res << endl;
        cout.flush();
        n -= res;
    }
    return 0;
}
