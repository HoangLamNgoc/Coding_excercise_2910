#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool cmp(const pair<int,int>& x, const pair<int,int>& y) {
    return x.first < y.first; 
}

int main() {
    int n, k; 
    cin >> n >> k; 

    pair<int,int> a[n]; 
    for(int i = 0; i < n; ++i) {
        int j; cin >> j; 
        a[i] = make_pair(j, i); 
    } 
    sort(a, a + n, cmp); 

    int i = 0, j = n - 1; 
    while (i < j) {
        if (a[i].first + a[j].first == k) {
            cout << a[i].second + 1 << " " << a[j].second + 1; 
            return 0; 
        }
        else if (a[i].first + a[j].first > k) --j; 
        else ++i; 
    }
    cout << "IMPOSSIBLE" << endl; 
    return 0; 
}
