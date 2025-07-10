#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std; 
int main() {
    int a=1, b=2; int n; int snt=2; 
    cin >> n ; 
    for ( int c = a+b ; c<=n ; c=a+b) {
        c = a + b;
        a = b;
        b = c; 
        if ( c % 2 == 0)
        snt = snt + c ;
    }
    cout << snt << endl ;
return 0;
}
