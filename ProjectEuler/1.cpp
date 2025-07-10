#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std; 

int main() {
    int snt = 0 ; int n ; 
    cin >> n ; 
    for ( int b = 1 ; b < n ; ++b) { 
        if ( b % 5 == 0 || b % 3 == 0 ) 
        snt = snt + b ;
    } 
    cout << snt; 
    return 0;
}
