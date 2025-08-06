#include <iostream>

using namespace std;

int n;

void ReadData () {
    cin >> n;
}

void Sol () {
    for ( int i = 1; i <= n; ++i ) {
        long long a, b;
        cin >> a >> b;

        long long x1 = 2 * a - b;
        long long y2 = 2 * b - a;

        if ( x1 >= 0 && y2 >= 0 ) {
            if ( x1 % 3 == 0 && y2 % 3 == 0 )
                cout << "YES" << endl;
            else cout << "NO" << endl;
        }
        else cout << "NO" << endl;
    }
}

int main()
{
    ReadData();
    Sol();
    return 0;
}
