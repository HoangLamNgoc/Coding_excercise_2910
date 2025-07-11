#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std; 

int main() {
    int n; int S = 0 ; A = 0; 
    cin >> n ;
    for (int i = 1; i <= n; ++i) { 
        S = S + i * i ;
        A = A + i * i + 2 * round(sqrt(A)) * i;
    }
    cout << A - S; 
    return 0;
}
    
