#include <bits/stdc++.h>

using namespace std;

long long calc(int xa, int ya, int xb, int yb, int xc, int yc) {
    return (xb - xa) * (yc - ya) - (xc - xa) * (yb - ya); 
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n; 

    vector<pair<int,int>> arr; 

    int x, y; 
    for(int i = 0; i < n; ++i) {
        cin >> x >> y;    

        arr.push_back({x, y}); 
    }

    int xch, ych; cin >> xch >> ych; 

    
    int ans = 0; 
    for(int i = 0; i < n; ++i) {
        int mx = max(arr[i % n].second, arr[(i + 1) % n].second); 
        int mn = min(arr[i % n].second, arr[(i + 1) % n].second); 

        int mx2 = max(arr[i % n].first, arr[(i + 1) % n].first); 
        int mn2 = min(arr[i % n].first, arr[(i + 1) % n].first);

        long long res = calc(arr[i % n].first, arr[i % n].second, arr[(i + 1) % n].first, arr[(i + 1) % n].second, xch, ych);
        if (mn != arr[i].second) 
            res = calc(arr[(i + 1) % n].first, arr[(i + 1) % n].second, arr[i % n].first, arr[i % n].second, xch, ych);

        if (!res) {
            if (mn2 <= xch && mx2 >= xch && mx >= ych && mn <= ych) {
                cout << "BOUNDARY";
                return 0;  
            }  
        }
        if (res >= 0 && 
            mx > ych && mn <= ych) {
                ++ans;
        } 
    }

    if (ans & 1) cout << "INSIDE"; 
    else cout << "OUTSIDE"; 
}
