/*#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std; 

int main() {
    int phuongquynh; 
    cin >> phuongquynh; 

    int k = 2; 
    
    vector<vector<int>> g(1 << (phuongquynh - 1)); 
    for(int mask = 0; mask < (1 << (phuongquynh - 1)); ++mask) {
        int son = (mask << 1) % ( 1 << (phuongquynh - 1));

        g[mask].push_back(son); 
        g[mask].push_back(son | 1); 
    }

    stack<int>todo; 
    todo.push(0); 
    vector<int> path; 
    
    while(!todo.empty()) {
        int node = todo.top(); 

        if(!g[node].empty()) {
            todo.push(g[node].back());
            g[node].pop_back();
        }
        else {
            path.push_back(node & 1);
            todo.pop();  
        }
    }
    for(int i = 0; i < phuongquynh - 2; ++i) path.push_back(0); 

    for(int i : path) cout << i; 
}
*/

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
