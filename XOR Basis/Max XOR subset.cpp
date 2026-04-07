#include <bits/stdc++.h>

using namespace std; 

const int MAXB = 30; 
vector<int> basis(MAXB); 
int sz = 0;  

void add(int x) {
    for(int i = MAXB - 1; i >= 0; --i) {
        if (!((x >> i) & 1)) continue; 

        if (!basis[i]) {
            basis[i] = x;
            ++sz; 
            return;  
        }

        x ^= basis[i]; 
    }
}

int max_phanthanhhung() {
    int res = 0; 
    for(int i = MAXB - 1; i >= 0; --i)  
        res = max(res, res ^ basis[i]);

    return res; 
}

int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 

    int n; cin >> n; 

    int a;  
    for(int i = 0; i < n; ++i) {
        cin >> a; 
        add(a); 
    }

    cout << max_phanthanhhung();  
    return 0; 
}
