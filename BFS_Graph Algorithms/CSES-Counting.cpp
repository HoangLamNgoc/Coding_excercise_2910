#include <iostream>
#include <vector>
#include <queue>
#include <utility>
 
using namespace std;
 
const int maxN = 1e3 + 5;
bool visit[maxN][maxN] ;
char ans1[maxN][maxN];
long long ans = 0;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int n, m;
 
void bfs(int r, int c) { 
      ans++;
      queue<pair<int, int>> q;
      q.push({r,c});
      visit[r][c] = true; 
      
      while(!q.empty()) {
      	  auto u = q.front();
      	  q.pop();
      	  int r1 = u.first;
      	  int c1 = u.second;
      	  
      	  for(int i = 0; i < 4; ++i) {
      	         int r2 = r1 + dx[i];
      	         int c2 = c1 + dy[i];
      	         if (r2 < 0 || r2 >= n || c2 < 0 || c2 >= m) continue;
      	  	  if(!visit[r2][c2]) {
      	  	  	visit[r2][c2] = true;
      	  	  	q.push({r2,c2});
      	  	  }
      	  }
      }
}
 
int main() {
	  ios_base::sync_with_stdio(0);
	  cin.tie(0); cout.tie(0);
	  
	  cin >> n >> m;
	  
	  for(int i = 0; i < n; ++i) {
	  	  for(int j = 0; j < m; ++j) {
	  	  	  cin >> ans1[i][j];
	  	  	  if (ans1[i][j] == '#') visit[i][j] = true;
	  	  }
	  }
	  for(int i = 0; i < n; ++i) {
	  	  for(int j = 0; j < m; ++j) {
	  	  	  if (!visit[i][j]) bfs(i,j);
	  	  }
	  }
	  cout << ans << endl;
	  return 0;
}
