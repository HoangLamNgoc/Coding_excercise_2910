#include <bits/stdc++.h>

using namespace std;

string check(int n, string z, bool fh) {
    int m = n / 2;
    string targ;
    int si, ti, skip = 0;
    string res = "";

    if (fh) {
        targ = z.substr(n - m, m);
        si = 0; ti = 0;
        while (ti < m && si <= m) {
            if (z[si] == targ[ti]) {
                si++; ti++;
            } else {
                if (skip++) break;
                si++;
            }
        }
        return (ti == m) ? targ : "";
    } else {
        targ = z.substr(0, m);
        si = m; ti = 0;

        while (ti < m && si < n) {
            if (z[si] == targ[ti]) {
                si++; ti++;
            } else {
                if (skip++) break;
                si++;
            }
        }
        return (ti == m) ? targ : "";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("STRINGKC.INP", "r", stdin);
    freopen("STRINGKC.OUT", "w", stdout);

    int n; cin >> n;

    string z;
    cin >> z;

    if (!(n & 1)) {
        cout << "No Solution";
        return 0;
    }

    string s1 = check(n, z, true);
    string s2 = check(n, z, false);

    if (s1 == "" && s2 == "") {
        cout << "No Solution";
    } else if (s1 != "" && s2 != "") {
        if (s1 == s2) cout << s1;
        else cout << "Multiple Solutions";
    } else {
        cout << (s1 != "" ? s1 : s2);
    }

    return 0;
}
