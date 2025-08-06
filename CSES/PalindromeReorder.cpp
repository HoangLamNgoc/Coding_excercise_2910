#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string s;
string b = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

void Input () {
    cin >> s;
}

void Sol() {
    int a[26] = {0};

    for ( int i = 0; i < s.length() ; ++i ) {
        char c = s[i];
        a[c -'A']++;
    }

    s.clear();
    int dem = 0;
    char x = 0;

    for (int  i = 0; i < 26 ; ++i ) {
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
    for ( int i = 0; i < 26; ++i ) {
        if ( a[i] == 0 ) continue;
        for ( int j = 0; j < a[i] / 2 ; ++j ) {
            left += b[i];
        }
    }

    string left1 = left;
    reverse(left1.begin(), left1.end());

    s = left + x + left1;
    cout << s << endl;
}

int main()
{
    Input();
    Sol();
    return 0;
}
