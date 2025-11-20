#include <iostream>
#include <algorithm>
#include <vector>

using namespace std; 

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0); 

    string stra, strb; cin >> stra >> strb; 

    int alen = (int)stra.size();
    int blen = (int)strb.size(); 
    stra = "-" + stra; 
    strb = "-" + strb; 

    int L[alen + 1][blen + 1];
    for(int i = 0; i <= alen; ++i) {
        for(int j = 0; j <= blen; ++j) {
            L[i][j] = 0; 
        }
    }
    for(int i = 1; i <= alen; ++i) L[i][0] = i; 
    for(int j = 1; j <= blen; ++j) L[0][j] = j;
    for(int i = 1; i <= alen; ++i) {
        for(int j = 1; j <= blen; ++j) {
            if (stra[i] == strb[j]) 
                L[i][j] = L[i - 1][j - 1]; 
            else 
                L[i][j] = min({L[i - 1][j - 1], L[i - 1][j], L[i][j - 1]}) + 1; 
        }
    }
    cout << L[alen][blen]; 
}
