#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int f1 = 1 , f2 = 1 , fn ;
    int n ;
    cin >> n ;
    for ( int i = 3 ; i <= n ; ++i) {
        fn = f1 + f2 ;
        f1 = f2 ;
        f2 = fn ;
    }
    cout << fn << endl;
    return 0;
}
