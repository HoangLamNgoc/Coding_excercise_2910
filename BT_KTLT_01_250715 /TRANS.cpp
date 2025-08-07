#include<bits/stdc++.h>

using namespace std;

void Sol(int n, int a, int b) {
    if ( n == 0 ) {
        cout << 0 << ' ' << 0;
        return;
    }

    long long minval = 1e6;
    int res = 0, res1 = 0;
    for (int i = 0; i <= (n + 49) / 50; ++i) {

        int used = i * 50;
        int re = max(0, n - used);

        int j = (re + 3) / 4;
        long long tong = i * a + j * b;
        if ( tong <= minval ) {
            minval = tong;
            res = i;
            res1 = j;
        }
    }
    cout << res << ' ' << res1;
}

int main(){
    freopen("TRANS.INP", "r", stdin);
    freopen("TRANS.OUT", "w", stdout);
    int n, a, b;
    cin >> n >> a >> b;
    Sol (n, a, b);
    return 0;
}
