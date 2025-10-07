#include <iostream>
#include <algorithm>
#include <set> 

using namespace std;

int main() {
    int n; cin >> n; 

    int a[n];
    int dem = 0; 
    for(int i = 0; i < n; ++i) cin >> a[i]; 
 
    multiset<int> s; 
    for(int i = 0; i < n; ++i) {
        auto it = s.lower_bound(a[i]);
        if (it == s.begin()) s.insert(a[i]); 
        else {
            --it; 
            s.erase(it); 
            s.insert(a[i]); 
        } 
    }

    cout << s.size() << endl; 
    return 0; 
}
