#include <isostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std; 
int N = 1e6 + 5; 
bool visit[N];

bool isB (int dem) {
    while ( dem > 0 ) {
        int i = dem % 10;
        if ( i > 1 ) return false;
        dem /= 10; 
    }
    return true;
}

string bfs ( int n) {
    queue<pair<int,string>> q;
    fill_n(visit, N, false); 
    q.push({1 % n, "1"}); 
    visit[1 % n] = true; 
    long long dem = s * n; 
    if ( isB(dem)) return s; 

    while (!q.empty()) {
        auto [v, s] = q.front();
        q.pop(); 
        if ( rem == 0 ) return s; 
      
        int rem0 = ( v * 10 ) % n;
        if (!visit[rem0]) {
            visit[rem0] = true; 
            q.push({rem0, s + "0"); 
        }
        int rem1 = ( v * 10 + 1) % n;
        if (!visit[rem1]) {
            visit[rem1] = true; 
            q.push({rem1, s + "1"); 
        }
    }
    return ""; 
}
    
int main() {
    int k; 
    cin >> k; 

    while (k--) {
        int n;   
        cin >> n;
        string ans = bfs(n);
        cout << ans << endl;
    }
  return 0; 
}
        int ans = bfs(1, n); 
        cout << ans << endl;
    }
    return 0; 
}


  
