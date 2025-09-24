#include <iostream>
#include <queue>
#include <vector>

using namespace std; 

int main() {
    int n, m; 
    cin >> n >> m; 

    char a[n][m]; 
    bool visitm[n][m];
    queue<pair<int,int>> qm;
    queue<pair<int, int>> qA; 
    bool visita[n][m]; 
    pair <int, int> end1; 
    int dA[n][m], dm[n][m]; 

    memset(visita, 0, sizeof visita);
    memset(dA, -1, sizeof dA);

    memset(visitm, 0, sizeof visitm);
    memset(dm, -1, sizeof dm);
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j ) {
            cin >> a[i][j]; 
            if ( a[i][j] == 'M') {
                qm.push({i, j});
                dm[i][j] = 0;
                visitm[i][j] = true;
            }
            if ( a[i][j] == 'A') {
                qA.push({i, j}); 
                dA[i][j] = 0; 
                visita[i][j] = true;
            }
            if ( i == n - 1 || j == m - 1 && a[i][j] == '.') {
                end1 = {i, j}; 
            }
        }  
    }

    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};
    char p[4] = {'L', 'R', 'U', 'D' };

    while (!qm.empty()) {
        auto [x,y] = qm.front();
        qm.pop();
        for (int k = 0; k < 4; ++k) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visitm[nx][ny] && a[nx][ny] != '#') {
                visitm[nx][ny] = true;
                dm[nx][ny] = dm[x][y] + 1;
                qm.push({nx, ny});
            }
        }
    }
    char par[n][m];
    bool found = false; 
    while (!qA.empty() && !found) {
        auto [x,y] = qA.front();
        qA.pop();
      
        if (x == 0 || x == n-1 || y == 0 || y == m-1) { 
            end1 = {x,y};
            found = true;
            break;
        }

        for (int k = 0; k < 4; ++k) {
            int nx = x + dx[k];
            int ny = y + dy[k];
           
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visita[nx][ny] && a[nx][ny] != '#') {
                if (dm[nx][ny] != -1 && dA[x][y]+1 >= dm[nx][ny]) continue;
                visita[nx][ny] = true;
                dA[nx][ny] = dA[x][y] + 1;
                par[nx][ny] = p[k];
                qA.push({nx, ny});
            }
        }
    }

    if ( !found) {
        cout << "No" << endl; 
        return 0; 
    }

    cout << "YES\n" << "\n" <<  dA[end1.first][end1.second] << "\n";
    string ans = ""; 
    int x = end1.first; 
    int y = end1. second; 

    while ( dA[x][y] != 0) {
        ans += par[x][y];
        if (dir == 'U') x++;       
        else if (dir == 'D') x--;  
        else if (dir == 'L') y++; 
        else if (dir == 'R') y--;  
    }
    reverse(ans.begin(), ans.end());
    cout << ans << "\n";
    return 0; 
}


                
