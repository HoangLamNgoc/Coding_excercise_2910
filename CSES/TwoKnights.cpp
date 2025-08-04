#include <iostream>

using namespace std;
typedef long long ll;

ll Sol ( ll n ) {
    ll knights = 4 * ( n - 1) * ( n - 2 );
    return knights;
}

int main() {
    ll n;
    cin >> n;
    cout << 0 << endl;
    for ( ll i = 2; i <= n; ++i) {
        ll total = i * i;
        ll ans = total * ( total - 1) / 2;
        ll kq = ans - Sol(i);
        cout << kq << endl;
    }
    return 0;
}
