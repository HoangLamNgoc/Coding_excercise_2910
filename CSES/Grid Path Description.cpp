#include <iostream>
#include <algorithm>
#include <vector>

using namespace std; 

const int N = 1e5; 
int id = 0;
const pair<int,int> a[4] = {{-1,0},{1,0},{0,1},{0,-1}};
const string rule = "UDRL";
bool visited[N][N];
long long ans = 0; 

bool empty(int x,int y) {
    return !visited[x][y] && max(x, y) < N && min(x,y) >= 0; 
}
    
void dfs(int x, int y) {
    if ( x == N - 1 && y == 0 ){
          for(int i = 0; i < n; ++i)
              for(int j = 0; j < n; ++j) 
                    if(visit[i][j]) return;
          ++ans; 
          return;
    }
    visited[x][y] = true; 
    if(visited[x - 1][y] && !visited[x][y - 1] && !visited[x][y + 1] && !visited[x + 1][y]) return;  

    if(visited[x][y - 1] && visited[x][y + 1] && !visited[x - 1][y] && !visited[x + 1][y]) return; 

    if(visited[x - 1][y] && visited[x + 1][y] && !visited[x][y - 1] && !visited[x][y + 1]) return; 

    for(int  i = 0; i < 4; ++i) {
        int r = x + a[i].first; 
        int c = y + a[i].second;
        if (!visited[r][c]) {
            dfs(r, c);
            visited[x][y] = false; 
        }
    }
}


int main() {
    string s; 
    cin >> s; 

    for(int i = 0; i < 9; ++i) {
        visited[0][i] = true; 
        visited[8][i] = true;
        visited[i][0] = true;
        visited[i][8] = true; 
    }

    dfs(1,1); 
    return 0; 
}
    
