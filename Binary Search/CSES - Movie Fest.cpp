#include <iostream>
#include <algorithm>
#include <vector>

using namespace std; 

struct me {
    int a, b; 
};

bool cmp (const me& x, const me& y) {
    return (x.b < y.b); 
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
    int last = g[1].b;  
    for(int i = 2; i <= n ; ++i) {
        if (g[i].a >= last) {
            cnt++; 
            last = g[i].b; 
        }
    }

    cout << cnt << endl; 
    return 0; 
}
