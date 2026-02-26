#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("STRINGKC.INP", "r", stdin);
    freopen("STRINGKC.OUT", "w", stdout);

    int n;
    cin >> n;

    string z;
    cin >> z;

    if (!(n & 1)) {
        cout << "No Solution";
        return 0;
    }

    int m = (n - 1) / 2;

    string s1 = z.substr(0, m);
    string s2 = z.substr(m, m);

    string s3 = z.substr(1, m);
    string s4 = z.substr(m + 1, m);

    bool ok1 = (s1 == s2);
    bool ok2 = (s3 == s4);

    if (ok1 && ok2) {
        cout << "Multiple Solutions";
    }
    else if (ok1) cout << s1;
    else if (ok2) cout << s3;
    else cout << "No Solution";
}
