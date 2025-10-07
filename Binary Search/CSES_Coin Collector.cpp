#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n; cin >> n; 

    int a[n];
    int dem = 0; 
    for(int i = 0; i < n; ++i) cin >> a[i]; 

    int i1 = 0; 
    bool used[n];
    fill_n(used, n, 0); 

    while (i1 < n) {
        int i = i1; 
        while (used[i]) ++i;
        if (i == n) break;
        used[i] = true; 
        int j = a[i];   
        while (i < n - 1) {
            if (j < a[i + 1] && !used[i + 1]) {
                used[i + 1] = true;
                j = a[i + 1];  
            } 
            ++i; 
        }
        ++dem; 
        if (i == n) break;
        while(used[i1]) i1++; 
    }
    cout << dem << endl; 
    return 0; 
}
