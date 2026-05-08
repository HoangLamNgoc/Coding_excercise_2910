#include <iostream>
#include <algorithm>
#include <vector>

using namespace std; 

vector<long long> A,B; 

bool check(int l1, int l2, int l3) {
    return (B[l3]- B[l1]) * (A[l1] - A[l2]) <= (B[l2] - B[l1]) * (A[l1] - A[l3]);  
}

void add(long long a, long long b) {
    A.push_back(a); 
    B.push_back(b); 

    while (A.size() >= 3 && check(A.size() - 3, A.size() - 2, A.size() - 1)) {
        A.erase(A.end() - 2);
        B.erase(B.end() - 2); 
    }
}

int ptr = 0; 
int n; 
long long query(long long x) {
    if (ptr >= A.size()) 
        ptr = A.size() - 1; 

    while (ptr < (int)A.size() - 1 && A[ptr] * x + B[ptr] > A[ptr + 1] * x + B[ptr + 1]) 
        ++ptr; 

    return A[ptr] * x + B[ptr];  
}

struct pts {
    int h, w; 
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

    add(pt[0].w, 0);
    long long cost = 0; 
    
    for(int i = 0; i < n; ++i) {
        cost = query(pt[i].h); 
        if (i < n - 1) {
            add(pt[i + 1].w, cost); 
        }
    }
    cout << cost; 
}
