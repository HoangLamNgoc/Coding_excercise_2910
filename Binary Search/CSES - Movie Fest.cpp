#include <iostream>
#include <algorithm>
#include <vector>

using namespace std; 

struct me {
    int a, b; 
};

bool cmp (const me& x, const me& y) {
    return (x.b < y.b) || (x.b == y.b && x.a > y.a); 
}

int main() {
    int n; 
    cin >> n; 
    long long cnt = 1; 

    vector<me> g(n + 1); 
    for(int i = 1; i <= n; ++i) {
        cin >> g[i].a >> g[i].b;  
    }
    sort(g.begin(), g.end(), cmp); 
    for(int i = 1; i < n ; ++i) {
        if (g[i].b <= g[i + 1].a) {
            cnt++; 
        }
    }

    cout << cnt << endl; 
    return 0; 
}
