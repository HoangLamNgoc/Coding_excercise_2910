// cứu lngoc voiiiiiiiiiiiiiiiiiiiiiiiiiii
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

bool ok = false;
void Sol(int n) {
    if ( n == 0 ) return;
    if (n % 2 == 1){
        cout << 1 << endl;
        cout.flush();

        int res;
        cin >> res;

        n -= res;
        n -= 1;
        Sol(n);

    }

    else {
        int num = n;
        int i = 2;
        if (__builtin_popcount(n) == 1 ) {
                cout << 0 << endl;
                cout.flush();

                int res;
                cin >> res;

                n -= res;
        }

        else {
            if ( num == 1 && !ok ) {
                cout << 0 << endl;
                cout.flush();

                int res;
                cin >> res;

                n -= res;
                ok = true;
                Sol(n);
            }
            else {
                cout << i << endl;
                cout.flush();

                int res;
                cin >> res;

                n -= i;
                n -= res;
                Sol(n);
            }
        }
    }
}

int main() {
    int n;
    cin >> n;

    Sol(n);
    return 0;
}
