#include <iostream>
 
using namespace std;
const int LOG = 1e9 + 7; 
 
int main() {
    int am, num; cin >> am >> num; 
 
    long long ways[num + 1];
    long long a[am + 1]; 
    fill_n(ways, num + 1, 0); 
    ways[0] = 1; 
    for(int i = 1; i <= am; ++i) cin >> a[i]; 
    for(int j = 1; j <= num; ++j) {
        for(int i = 1; i <= am; ++i) {
            if (a[i] <= j) { 
                ways[j] += ways[j - a[i]]; 
                ways[j] %= LOG;
            }  
        }
    } 
    cout << ways[num] % LOG; 
}
