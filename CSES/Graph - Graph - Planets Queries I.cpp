#include <iostream>
#include <algorithm>

using namespace std; 

int lg[(int)2e5 + 5];
int n, m;
void lg2() {
    lg[1] = 0; 
    for(int i = 2; i <= (int)2e5 + 5; ++i) 
        lg[i] = lg[i / 2] + 1;  
}

const int maxn = 2e5 + 5; 

long long par[31][maxn]; 
int a[maxn]; 

int main() {
    lg2(); 
    cin >> n >> m; 

    for(int i = 1; i <= n; ++i) {
        int v; cin >> v; 
        par[0][i] = v; 
    }

    for(int j = 1; j < 30; ++j) 
        for(int i = 1; i <= n; ++i) 
            par[j][i] = par[j - 1][par[j - 1][i]];

    while(m--)  {
        int u, k; 
        cin >> u >> k;

        int cur = lg[k];
        int ans = u;  

        for(int bit = 0; bit <= cur; ++bit) {
            if (k & (1 << bit)) 
                ans = par[bit][ans]; 
        }
        cout << ans << '\n'; 
    }
}
