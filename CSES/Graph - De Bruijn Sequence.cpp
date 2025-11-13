#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std; 

int main() {
    int n; cin >> n; 

    if (n == 1) {
        cout << "10"; 
        return 0; 
    }
    vector<vector<int>> g(1 << (n - 1)); 


    for(int i = 0; i <= (1 << (n - 1)); ++i) {
        int son = (i << 1) % (1 << (n - 1)); 

        g[i].push_back(son);
        g[i].push_back(son | 1); 
    }

    stack<int> todo;
    vector<int> path; 
    todo.push(0);

    while(!todo.empty()) {
        int u = todo.top(); 

        if(!g[u].empty()) {
            cout << g[u].back(); 
            todo.push(g[u].back()); 
            g[u].pop_back(); 
        }
        else {
            todo.pop(); 
            path.push(u & 1); 
        }
    } 

    for(int i = 1; i < n - 2; ++i) path.push_back(0); 
    for(int i : path) cout << i; 
}
