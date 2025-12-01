#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
 
using namespace std; 
 
vector<int> arr, mx; 
int n; 
 
void input() {
    cin >> n;
    arr.clear();   
    arr.resize(n + 2, 0);
 
    mx.clear(); 
    mx.resize(n + 2, 0); 
 
    for(int i = 1; i <= n; ++i) {
        cin >> arr[i];
        mx[i] = max(mx[i - 1], arr[i]);
    } 
}
 
void sol() {
    int cnt = 0; 
    arr[0] = INFINITY; 
    arr[n + 1] = 1e9; 
    for(int i = 1; i <= n; i += 2) {
        bool ok1 = 0, ok2 = 0; 
        if (arr[i] >= arr[i + 1]) {
            arr[i + 1] = max(mx[i + 1], arr[i + 1]);
            if (arr[i + 1] > arr[i]) continue; 
            else {
                ok2 = 1; 
            }
        }
        if (arr[i] >= arr[i - 1]) {
            arr[i - 1] = max(mx[i - 1], arr[i - 1]); 
            if (arr[i - 1] <= arr[i]) {
                ok1 = 1;  
            }
        } 
 
        if (ok1 && ok2) {
            if (arr[i - 1] <= arr[i + 1]) {
                cnt += arr[i] - arr[i - 1] + 1;
            }
            else cnt += arr[i] - arr[i + 1] + 1;
        }
        else if (ok1) {
            cnt += arr[i] - arr[i - 1] + 1;
        }
        else if (ok2) {
            cnt += arr[i] - arr[i + 1] + 1;
        }
    }
    cout << cnt << '\n' << "\n"; 
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
 
    int tests; cin >> tests; 
 
    while(tests--) {
        input(); 
        sol(); 
    }
}
