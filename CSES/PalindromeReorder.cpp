#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string s;
string b = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const alphabet = 26;

void Input () {
    cin >> s;
}

void Sol() {
    int a[alphabet] = {0};

    for ( int i = 0; i < s.length() ; ++i ) {
        char c = s[i];
        a[c -'A']++;
    }

    s.clear();
    int dem = 0;
    string x = "";

    for (int  i = 0; i < alphabet ; ++i ) {
        if ( a[i] % 2 == 1 ) {
            dem++;
            if ( dem == 2 ) {
                cout << "NO SOLUTION" << endl;
                return;
            }
            else {
                x = b[i];
                a[i]--;
            }
        }
    }

    string left = "";
    for ( int i = 0; i < alphabet; ++i ) {
        if ( a[i] == 0 ) continue;
        for ( int j = 0; j < a[i] / 2 ; ++j ) {
            left += b[i];
        }
    }

    string right = left;
    reverse(right.begin(), right.end());

    s = left + x + right; 
    cout << s << endl;
}

int main()
{
    Input();
    Sol();
    return 0;
}

HXN: 

#include <iostream>
#include <map>
#include <string>
 
using namespace std;
 
string rearrangePalin(string s) {
    map<char, int> freq;
    for (char c : s) ++freq[c];
 
    string left = "", mid = "";
    for (auto it = freq.begin(); it != freq.end(); ++it) {
        if (it->second % 2 == 1) {
            if (mid != "") return "NO SOLUTION";
            mid = string(1, it->first);
        }
        left += string(it->second / 2, it->first);
    }
    return left + mid + string(left.rbegin(), left.rend());
}
 
int main() {
    string s; cin >> s;
 
    cout << rearrangePalin(s) << endl;
    return 0;
}
