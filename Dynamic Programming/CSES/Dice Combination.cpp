#include <iostream>
 
using namespace std;
const int LOG = 1e9 + 7; 
 
int main() {
    int num; cin >> num; 
 
    long long ways[num + 1];
    fill_n(ways, num + 1, 0); 
    ways[0] = 1; 
    for(int j = 1; j <= num; ++j) {
        for(int i = 1; i <= 6; ++i) {
            if (i <= j) { 
                ways[j] += ways[j - i]; 
                ways[j] %= LOG;
            }  
        }
    } 
    cout << ways[num] % LOG; 
}
