#include <iostream>
#include <vector>

using namespace std;
int  n;

void Permutations (int n) {
    vector<int> a;
    if ( n == 1 ) {
        cout << 1;
        return;
    }

    else if ( n <= 3 ) {
        cout << "NO SOLUTION" ;
        return;
    }

    else {
        for ( int i = 2; i <= n; i += 2)
            a.push_back(i);

        for ( int i = 1 ; i <= n ; i += 2)
            a. push_back(i);
    }

    for ( int i = 0; i < n; ++i )
        cout << a[i] << " ";
}

int main() {
    cin >> n;
    Permutations(n);
    return 0;
}
