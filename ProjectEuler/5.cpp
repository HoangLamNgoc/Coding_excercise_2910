#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std; 

bool isDivisible(int n) {
    if (n < 0) return false; 
    for ( int i = 1; i <= 20; ++i)
        if (n % i != 0) return false;
    return true;
}

int main() {
    int a=1;
    cin >> a; 
    vector <int> Number ;
    for(int i=a; ; ++i) {
        if (isDivisible(i)) { 
            Number.push_back(i);
            break;
        }
    }    
    cout << Number[0] << endl;
    return 0; 
}
