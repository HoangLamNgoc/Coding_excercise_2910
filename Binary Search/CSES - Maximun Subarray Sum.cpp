#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n; cin >> n; 
    int minv = 0, maxv = 0; 
    long long sum = 0; 

    for(int i = 1; i <= n; ++i){
        int d; cin >> d; 
        sum += d; 
        maxv = max(maxv, (int)sum - minv); 
        minv = min(sum,(long long)minv); 
    }

    cout << maxv << endl; 
    return 0; 
}
