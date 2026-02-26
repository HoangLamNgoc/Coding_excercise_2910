#include <bits/stdc++.h>

using namespace std; 

int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    
    freopen("MINMM.INP", "r", stdin);
    freopen("MINMM.OUT", "w", stdout); 
    
    int n, k; 
    cin >> n >> k; 

    vector<int> arr(n); 
    for(int i = 0; i < n; ++i) cin >> arr[i]; 

    sort(arr.begin(), arr.end()); 

    vector<int> diff(n); 
    for(int i = 0; i < n - 1; ++i) {
        diff[i] = arr[i + 1] - arr[i]; 
    }

    int i = 0; 
    int j = n - 1; 

    while (k && i < j) {
        if (diff[i] > diff[j - 1]) 
            ++i;
        else --j; 
        --k; 
    }

    long long M = arr[j] - arr[i]; 
    sort(diff.begin() + i, diff.begin() + j);   

    long long m = diff[i]; 
    cout << M + m << '\n'; 
}
