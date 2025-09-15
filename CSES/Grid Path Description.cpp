#include <iostream>
#include <algorithm>
#include <vector>

using namespace std; 

const int N = 7; 
string s;
const pair<int,int> a[4] = {{-1,0},{1,0},{0,1},{0,-1}};
const string rule = "UDRL";
bool visited[N][N];
long long ans = 0; 

bool empty(int x,int y) {
    return !visited[x][y] && max(x, y) < N && min(x,y) >= 0; 
}
    
void dfs(int x, int y, int i) {
    if ( x == N - 1 && y == 0 ){
        if( i == 48) {
              ++ans; 
              return;
        }
    }
    
    visited[x][y] = true; 
    if(x >= 1 && y >= 1 && visited[x - 1][y] && !visited[x][y - 1] && !visited[x][y + 1] && !visited[x + 1][y]) return;  

    if(x >= 1 && y >= 1 && visited[x][y - 1] && visited[x][y + 1] && !visited[x - 1][y] && !visited[x + 1][y]) return; 

    if(x >= 1 && y >= 1 && visited[x - 1][y] && visited[x + 1][y] && !visited[x][y - 1] && !visited[x][y + 1]) return; 


    for(int  j = 0; j < 4; ++j) {
        if( s[i] != '?' && s[i] != rule[j] )
            continue;
        int r = x + a[j].first; 
        int c = y + a[j].second;
        if (!visited[r][c]) {
            dfs(r, c, i + 1);
            visited[r][c] = false; 
        }
    }
}


int main() { 
    cin >> s; 
    dfs(0, 0, 0); 
    cout << ans << endl; 
    return 0; 
}
    
