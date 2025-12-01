#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXA = 2e5 + 10;
vector<vector<int>> spf(MAXA);

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i]; 

    map<int,int> divi; 
    int ans0 = 2;      
    for(int i = 0; i < n; i++){
        for(int p : spf[a[i]]){
            if(divi[p] > 0) ans0 = 0;
            divi[p]++;
        }
    }
    for(int i = 0; i < n; i++){
        for(int p : spf[a[i]]) divi[p]--;
        for(int p : spf[a[i]+1]){
            if(divi[p] > 0) ans0 = min(ans0,1);
        }
        for(int p : spf[a[i]]) divi[p]++;
    }

    cout << ans0 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    for(int i = 2; i < MAXA; i++){
        if(!spf[i].empty()) continue;
        for(int j = i; j < MAXA; j += i) spf[j].push_back(i);
    }

    int T;
    cin >> T;
    while(T--) solve();
}
