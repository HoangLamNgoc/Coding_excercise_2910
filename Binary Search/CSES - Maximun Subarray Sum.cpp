#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n; cin >> n;
    long long minv = 0 , maxv = -1e15;
    long long sum = 0;

    for(int i = 1; i <= n; ++i){
        int d; cin >> d;
        sum += d;
        maxv = max(maxv,sum - minv);
        minv = min(sum,minv);
    }
    cout << maxv << endl;
    return 0;
}
