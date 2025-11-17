#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int amount, sum; 
    cin >> amount >> sum; 

    int am[amount + 1];
    for(int i = 1; i <= amount; ++i) cin >> am[i];

    long long minv[sum + 1];
    fill_n(minv, sum + 1, 1e18); 
    minv[0] = 0;

    for(int j = 1; j <= sum; ++j) {
        for(int i = 1; i <= amount; ++i) {
            if (am[i] <= j) {
                minv[j] = min(minv[j], minv[j - am[i]] + 1);
            }
        }
    }

    if(minv[sum] >= 1e18) cout << -1; 
    else cout << minv[sum];
}
