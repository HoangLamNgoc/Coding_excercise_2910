#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std; 

deque<long long> A,B; 

bool check(int l1, int l2, long long a, long long b) {
    return (b - B[l1]) * (A[l1] - A[l2]) <= (B[l2] - B[l1]) * (A[l1] - a);  
}

void add(long long a, long long b) {
    while (A.size() >= 2 && check(A.size() - 2, A.size() - 1, a, b)) {
        A.pop_back();
        B.pop_back(); 
    }

    A.push_back(a); 
    B.push_back(b); 
}

int n; 
long long query(long long x) {
    while (A.size() >= 2 && (A[0] * x + B[0] >= A[1] * x + B[1])) { 
        A.pop_front(); 
        B.pop_front(); 
    }

    return A[0] * x + B[0];
}

struct pts {    
    long long h, w; 
}; 

int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 

    cin >> n; 

    vector<pts> pt(n); 
    for(int i = 0; i < n; ++i) cin >> pt[i].h >> pt[i].w; 

    sort(pt.begin(), pt.end(), [](const pts& a, const pts& b) {
        return a.h < b.h; 
    }); 

    int cnt = 0; 
    for(int i = 0; i < n; ++i) {
        while (cnt > 0 && pt[i].w >= pt[cnt - 1].w) 
            --cnt; 

        pt[cnt++] = pt[i];  
    }    

    add(pt[0].w, 0LL);
    long long cost = 0; 
    
    for(int i = 0; i < cnt; ++i) {
        cost = query(pt[i].h); 
        if (i < n - 1) {
            add(pt[i + 1].w, cost); 
        }
    }
    cout << cost; 
}
