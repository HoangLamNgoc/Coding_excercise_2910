#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std; 

vector<int> arr; 
int n; 

struct cartesiantree {
    stack<int> st; 
    int root; 

    vector<int> left; 
    vector<int> right;

    vector<int> d;  

    void init() {
        left.assign(n + 1, 0); 
        right.assign(n + 1, 0);
        d.assign(n + 1, 0);  
    }

    int calc(int u, int fl) {
        if (u == 0) return fl - 1; 
        d[u] = fl;
        return max(calc(left[u], fl + 1), calc(right[u], fl + 1)); 
    }

    int build() {
        st.push(1); 
        for(int i = 2; i <= n; ++i) {
            int x = arr[i];
            int last = 0; 
            while (!st.empty() && arr[st.top()] < x) {
                last = st.top(); 
                st.pop(); 
            }

            if (last) 
                left[i] = last; 

            if (!st.empty()) 
                right[st.top()] = i; 

            st.push(i); 
        }

        while (st.size() > 1) st.pop(); 
        root = st.top();
        return calc(root, 1);
    }
};

void sol() {
    cin >> n; 

    cartesiantree ct; 
    ct.init(); 

    arr.assign(n + 1, 0); 
    for(int i = 1; i <= n; ++i) cin >> arr[i]; 

    cout << n - ct.build() << '\n'; 
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int test; cin >> test; 

    while (test--) {
        sol(); 
    }
}
