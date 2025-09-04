#include <iostream>
#include <algorithm>
#include <vector> 

using namespace std; 

int main() {
    int n; 
    cin >> n; 
    long long ans = 0; 

    long long tonnage; 
    cin >> tonnage; 

    vector <long long> a(n);
    for ( int i = 0; i < n; ++i ) cin >> a[i]; 
    sort(a.begin(), a.end());

    if ( n % 2 == 0 ) {
        a.pop_back(a.begin() + n - 1); 
        ++ans; 
    }

    int i = 0; 
    int j = n - 1; 

    while ( i <= j ) {
        if(a[i] + a[j] <= tonnage) {
            a.pop_back(a.begin() + i - 1); 
            a.pop_back(a.begin() + j - 1); 
            ++i;
            --j; 
            ++ans; 
        }
        else --j; 
    }

    if (!a.empty()) ans += a.size(); 
    cout << ans << endl; 
    return 0; 
}
