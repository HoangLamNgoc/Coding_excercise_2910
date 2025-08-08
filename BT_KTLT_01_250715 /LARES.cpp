#include <iostream>

using namespace std;

int main() {
    freopen ("LARES.INP", "r", stdin);
    freopen ("LARES.OUT", "w", stdout); 
  
    long long m, n, k; 
    cin >> m >> n >> k; 
    
    long long total = m + n - k; 
    long long nhom = total / 3;
    
    if ( nhom > n ) nhom = n; 
    if ( nhom * 2 > m ) nhom = m / 2; 
    cout << nhom << endl; 
    return 0;
}
