#include <iostream>
#include <algorithm>

int main() {
    int n; 
    cin >> n; 

    int pos[n + 5]; 
    for(int i = 1; i <= n; ++i ) {
        int x; cin >> x; 
        pos[x] = i; 
    }
    int r = 0; 
    for (int i = 2; i < n; ++i) 
        if (pos[i] < pos[i - 1]) r++; 

    cout << r << endl; 
    return 0; 
}
