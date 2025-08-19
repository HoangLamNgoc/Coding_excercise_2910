#include <iostream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

long long Giaithua(int n) {
    long long dem = 1;
    while ( n > 0 ) {
        dem *= n;
        --n;
    }

    return dem;
}

bool Permutation(string& s ) {
    int n = s.length();
    int i = n - 2;
    while (i >= 0 && s[i] >= s[i + 1]) {
        i--;
        if ( i < 0 ) return false;
    }

        int j = n - 1;
        while ( j > i && s[j] <= s[i]) {
            j--;
        }

        swap(s[i],s[j]);

        reverse(s.begin() + i + 1, s.end());

    return true;
    }

int main()
{
    string s;
    cin >> s;

    map <char,int> m;
    int dem = Giaithua(s.length());

    for (char c : s ) ++m[c];

    for (auto it = m.begin(); it != m. end(); ++it) {
        dem /= Giaithua(it->second);
    }

    cout << dem << endl;

    if ( dem == 1 ) {
        cout << s << endl;
        return 0;
    }
    else {
        sort(s.begin(), s.end());

        cout << s << endl;

        while (Permutation(s)) {
            cout << s << endl;
        }
    }
    return 0;
}
