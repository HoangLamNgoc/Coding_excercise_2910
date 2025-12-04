#include <iostream>

using namespace std; 

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0); 

    int T; cin >> T;

    while(T--) {
        int k; cin >> k;

        if (k % 3 == 1) {
            cout << "YES" << '\n'; 
        }
        else cout << "NO" << '\n'; 
    }
}
